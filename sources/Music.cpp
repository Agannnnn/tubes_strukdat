#include "../headers/Music.h"
#include  "../headers/Queue.h"

using namespace std;

namespace music {
    void createGraph(Graph &graph) {
        graph.first = nullptr;
    }

    addr allocateVertex(Infotype info) {
        addr elm = new Vertex();
        elm->info = info;
        elm->nextMusic = nullptr;
        elm->nextGenre = nullptr;
        elm->nextLanguage = nullptr;
        return elm;
    }

    edge allocateEdge(addr vertex) {
        edge edge1 = new Edge();
        edge1->vertex = vertex;
        edge1->next = nullptr;
        return edge1;
    }

    bool isEmpty(Graph graph) {
        return graph.first == nullptr;
    }

    edge getEdge(addr vertex, Category category) {
        switch (category) {
            case MUSIC:
                return vertex->nextMusic;
            case GENRE:
                return vertex->nextGenre;
            case LANGUAGE:
                return vertex->nextLanguage;
            default:
                return nullptr;
        }
    }

    bool isEdgeEmpty(addr vertex, Category category) {
        return getEdge(vertex, category) == nullptr;
    }

    bool isConnected(addr fromVertex, addr toVertex, Category category) {
        if (isEdgeEmpty(fromVertex, category)) return false;
        edge edge1 = getEdge(fromVertex, category);
        bool found = false;
        while (edge1 != nullptr && !found) {
            if (edge1->vertex == toVertex) found = true;
            else edge1 = edge1->next;
        }
        return found;
    }

    void insertVertex(Graph &graph, addr &newVertex, Category category) {
        if (isEmpty(graph)) {
            graph.first = newVertex;
        } else {
            queue::List queue1 = listBy(graph, newVertex, category);
            queue::addr elm = queue1.first;
            while (elm != nullptr) {
                connectVertex(elm->music, newVertex, category);
                elm = elm->next;
            }
        }
    }

    void deleteVertex(Graph &graph, addr &vertex, Category category) {
        if (!isEmpty(graph) && graph.first == vertex) {
            if (isEdgeEmpty(vertex, MUSIC)) graph.first = nullptr;
            else {
                edge e = getEdge(vertex, MUSIC);
                graph.first = e->vertex;
            }
        }
        queue::List queue1 = listBy(graph, vertex, category);
        if (!queue::isEmpty(queue1)) {
            queue::addr elm = queue1.first;
            while (elm != nullptr) {
                disconnectVertex(elm->music, vertex, category);
                elm = elm->next;
            }
        }
    }

    void displayRelations(addr vertex, Category category) {
        cout << "+----------------------------------------------+" << endl;
        printf("| CONNECTION OF %-30s |\n", vertex->info.title.c_str());
        cout << "+----------------------------------------------+" << endl;
        edge edge1 = getEdge(vertex, category);
        while (edge1 != nullptr) {
            printf("| %-44s |\n", edge1->vertex->info.title.c_str());
            cout << "+----------------------------------------------+" << endl;
            edge1 = edge1->next;
        }
        cout << endl;
    }

    void connectVertex(addr &fromVertex, addr &toVertex, Category category) {
        if (isConnected(fromVertex, toVertex, category)) return;
        if (fromVertex == toVertex) return;
        edge edge1 = allocateEdge(toVertex);
        if (isEdgeEmpty(fromVertex, category)) {
            switch (category) {
                case MUSIC:
                    fromVertex->nextMusic = edge1;
                    break;
                case GENRE:
                    fromVertex->nextGenre = edge1;
                    break;
                case LANGUAGE:
                    fromVertex->nextLanguage = edge1;
                    break;
            }
        } else {
            edge edge2 = getEdge(fromVertex, category);
            while (edge2->next != nullptr) {
                edge2 = edge2->next;
            }
            edge2->next = edge1;
        }
        connectVertex(toVertex, fromVertex, category);
    }

    void disconnectVertex(addr &fromVertex, addr &toVertex, Category category) {
        if (!isConnected(fromVertex, toVertex, category)) return;
        edge edge1 = getEdge(fromVertex, category);
        // Kalau edge pertama = v2
        if (edge1->vertex == toVertex) {
            switch (category) {
                case MUSIC:
                    fromVertex->nextMusic = edge1->next;
                    edge1->next = nullptr;
                    break;
                case GENRE:
                    fromVertex->nextGenre = edge1->next;
                    edge1->next = nullptr;
                    break;
                case LANGUAGE:
                    fromVertex->nextLanguage = edge1->next;
                    edge1->next = nullptr;
                    break;
            }
        } else {
            while (edge1->next != nullptr && edge1->next->vertex != toVertex) {
                edge1 = edge1->next;
            }
            // e adalah edge sebelum edge yang ingin dihapus, jadi e_delete = edge yang mau dihapus
            edge edge2 = edge1->next;
            edge1->next = edge2->next;
            edge2->next = nullptr;
        }
        disconnectVertex(toVertex, fromVertex, category);
    }

    void display(Graph graph) {
        if (isEmpty(graph)) return;
        printf("+%s+\n", string(98, '-').c_str());
        printf("| %29s | %15s | %20s | %15s | %5s |\n", "Title", "Duration", "Artist", "Genre", "Lang");
        printf("+%s+\n", string(98, '-').c_str());

        queue::List musicList = listBy(graph, graph.first, MUSIC);
        queue::addr eMusic = musicList.first;
        while (eMusic != nullptr) {
            printf(
                "| %29s | %15d | %20s | %15s | %5s |\n",
                eMusic->music->info.title.c_str(),
                eMusic->music->info.duration,
                eMusic->music->info.artist.c_str(),
                eMusic->music->info.genre.c_str(),
                eMusic->music->info.language.c_str());

            eMusic = eMusic->next;
        }

        printf("+%s+\n", string(98, '-').c_str());
    }

    addr find(Graph graph, string title) {
        if (isEmpty(graph)) return nullptr;

        container::List visited, planned;
        container::createList(visited);
        container::createList(planned);

        container::addr elmContainer1 = container::allocateElm(graph.first);
        container::insertLast(planned, elmContainer1);

        // Kalau ternyata vertex pertama adalah lagu yang dicari
        if (elmContainer1->song->info.title == title) return elmContainer1->song;

        addr vertex = nullptr;
        while (!container::isEmpty(planned) && vertex == nullptr) {
            container::addr elmContainer2;
            container::deleteFirst(planned, elmContainer2);
            container::insertLast(visited, elmContainer2);

            edge edge1 = getEdge(elmContainer2->song, MUSIC);
            while (edge1 != nullptr && vertex == nullptr) {
                if (edge1->vertex->info.title == title) {
                    vertex = edge1->vertex;
                }
                if (!container::exists(visited, edge1->vertex)) {
                    elmContainer1 = container::allocateElm(edge1->vertex);
                    container::insertLast(planned, elmContainer1);
                }
                edge1 = edge1->next;
            }
        }

        return vertex;
    }

    queue::List listBy(Graph graph, addr vertex, Category category) {
        queue::List queue;
        queue::createList(queue);

        if (isEmpty(graph)) return queue;

        container::List visited, planned;
        container::createList(visited);
        container::createList(planned);

        container::addr elmContainer1 = container::allocateElm(graph.first);
        container::insertLast(planned, elmContainer1);

        while (!container::isEmpty(planned)) {
            container::addr elmContainer2;
            container::deleteFirst(planned, elmContainer2);
            if (!container::exists(visited, elmContainer2->song)) container::insertLast(visited, elmContainer2);


            edge edge1 = getEdge(elmContainer2->song, MUSIC);
            while (edge1 != nullptr) {
                if (!container::exists(visited, edge1->vertex)) {
                    elmContainer2 = container::allocateElm(edge1->vertex);
                    container::insertLast(planned, elmContainer2);
                }
                edge1 = edge1->next;
            }
        }

        elmContainer1 = visited.first;
        while (elmContainer1 != nullptr) {
            queue::addr elmQueue1 = queue::allocateElm(elmContainer1->song);
            switch (category) {
                case GENRE:
                    if (elmContainer1->song->info.genre == vertex->info.genre) {
                        queue::insertLast(queue, elmQueue1);
                    }
                    break;
                case LANGUAGE:
                    if (elmContainer1->song->info.language == vertex->info.language) {
                        queue::insertLast(queue, elmQueue1);
                    }
                    break;
                case MUSIC:
                    queue::insertLast(queue, elmQueue1);
            }
            elmContainer1 = elmContainer1->next;
        }

        return queue;
    }
}

namespace container {
    void createList(List &list) {
        list.first = nullptr;
    }

    addr allocateElm(music::addr music) {
        addr elm = new Elm();
        elm->song = music;
        elm->next = nullptr;
        return elm;
    }

    bool isEmpty(List list) {
        return list.first == nullptr;
    }

    void insertLast(List &list, addr elm) {
        if (isEmpty(list)) {
            list.first = elm;
        } else {
            addr elm1 = list.first;
            while (elm1->next != nullptr) {
                elm1 = elm1->next;
            }
            elm1->next = elm;
        }
    }

    void deleteFirst(List &list, addr &elm) {
        elm = list.first;
        list.first = list.first->next;
        elm->next = nullptr;
    }

    bool exists(List &list, music::addr elm) {
        addr elm1 = list.first;
        bool found = false;
        while (elm1 != nullptr && !found) {
            if (elm1->song == elm) {
                found = true;
            }
            elm1 = elm1->next;
        }
        return found;
    }
}
