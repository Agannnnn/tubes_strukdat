#include "../headers/Song.h"

#include  "../headers/Antrean.h"

namespace song {
    void createGraph(Graph &g) {
        g.first = nullptr;
    }

    addr allocateVertex(Infotype v) {
        addr e = new Vertex();
        e->info = v;
        e->next_song = nullptr;
        e->next_genre = nullptr;
        e->next_language = nullptr;
        return e;
    }

    edge allocateEdge(addr v) {
        edge e = new Edge();
        e->vertex = v;
        e->next = nullptr;
        return e;
    }

    bool isEmpty(Graph g) {
        return g.first == nullptr;
    }

    edge getEdge(addr v, int c) {
        switch (c) {
            case SONG:
                return v->next_song;
            case GENRE:
                return v->next_genre;
            case LANGUAGE:
                return v->next_language;
            default:
                return nullptr;
        }
    }

    bool isEdgeEmpty(addr v, int c) {
        return getEdge(v, c) == nullptr;
    }

    bool isConnected(addr v1, addr v2, int c) {
        if (isEdgeEmpty(v1, c)) return false;
        edge e = getEdge(v1, c);
        bool found = false;
        while (e != nullptr && !found) {
            if (e->vertex == v2) found = true;
            e = e->next;
        }
        return found;
    }

    void insertVertex(Graph &g, addr v) {
        if (isEmpty(g)) {
            g.first = v;
        } else {
            connectVertex(g.first, v, SONG);
        }
    }

    void displayConnections(addr v, int c) {
        edge e = getEdge(v, c);
        cout << "Relasi lagu " << v->info.title << ": ";
        while (e != nullptr) {
            cout << e->vertex->info.title;
            if (e->next != nullptr) {
                cout << ", ";
            }
            e = e->next;
        }
        cout << endl;
    }

    void connectVertex(addr &v1, addr &v2, int c) {
        if (isConnected(v1, v2, c)) return;
        if (isEdgeEmpty(v1, c)) {
            switch (c) {
                case SONG:
                    v1->next_song = allocateEdge(v2);
                    break;
                case GENRE:
                    v1->next_genre = allocateEdge(v2);
                    break;
                case LANGUAGE:
                    v1->next_language = allocateEdge(v2);
                    break;
                default:
                    break;
            }
        } else {
            edge e = getEdge(v1, c);
            while (e->next != nullptr) { e = e->next; }
            e->next = allocateEdge(v2);
        }
    }

    void disconnectVertex(addr &v1, addr &v2, int c) {
        if (!isConnected(v1, v2, c)) return;
        edge e = getEdge(v1, c);
        // Kalau edge pertama = v2
        if (e->vertex == v2) {
            switch (c) {
                case SONG:
                    v1->next_song = e->next;
                    e->next = nullptr;
                    break;
                case GENRE:
                    v1->next_genre = e->next;
                    e->next = nullptr;
                    break;
                case LANGUAGE:
                    v1->next_language = e->next;
                    e->next = nullptr;
                    break;
                default:
                    break;
            }
            delete e;
        } else {
            while (e->next != nullptr && e->next->vertex != v2) {
                e = e->next;
            }
            // e adalah edge sebelum edge yang ingin dihapus, jadi e_delete = edge yang mau dihapus
            edge e_delete = e->next;
            e->next = e_delete->next;
            e_delete->next = nullptr;

            delete e_delete;
        }
    }

    void display(Graph g) {
        if (isEmpty(g)) return;

        container::List visited, planned;
        container::createList(visited);
        container::createList(planned);

        // Masukkan vertex pertama graf sebagai vertex yang mau di-traverse
        container::addr p = container::allocateElm(g.first);
        container::insertLast(planned, p);

        while (!container::isEmpty(planned)) {
            // Hapus elemen container (vertex graf) yang sudah di-traverse, lalu masukkan ke list dikunjungi
            container::addr q;
            container::deleteFirst(planned, q);
            container::insertLast(visited, q);

            // Ambil edge pertama dalam elemen container (vertex graf)
            edge e = getEdge(q->song, SONG);
            while (e != nullptr) {
                // Selama vertex yang ditunjuk edge belum di-traverse, masukkan ke container planned (vertex untuk
                // di-traverse)
                if (!container::exists(visited, e->vertex)) {
                    p = container::allocateElm(e->vertex);
                    container::insertLast(planned, p);
                }
                e = e->next;
            }
        }

        printf(
            "+--------------------------------+--------+----------------------+-----------------+----------------------+\n");
        printf(
            "| Judul                          | Durasi | Penyanyi             | Genre           | Bahasa               |\n");
        printf(
            "+--------------------------------+--------+----------------------+-----------------+----------------------+\n");

        p = visited.first;
        while (p != nullptr) {
            printf("| %30s | %6d | %20s | %15s | %20s |\n",
                   p->song->info.title.c_str(),
                   p->song->info.duration,
                   p->song->info.singer.c_str(),
                   p->song->info.genre.c_str(),
                   p->song->info.language.c_str());
            p = p->next;
        }

        printf(
            "+--------------------------------+--------+----------------------+-----------------+----------------------+\n");
    }

    addr find(Graph g, string t) {
        if (isEmpty(g)) return nullptr;

        container::List visited, planned;
        container::createList(visited);
        container::createList(planned);

        container::addr p = container::allocateElm(g.first);
        container::insertLast(planned, p);

        // Kalau ternyata vertex pertama adalah lagu yang dicari
        if (p->song->info.title == t) return p->song;

        addr vertex = nullptr;

        while (!container::isEmpty(planned) && vertex == nullptr) {
            container::addr q;
            container::deleteFirst(planned, q);
            container::insertLast(visited, q);

            edge e = getEdge(q->song, SONG);
            while (e != nullptr && vertex == nullptr) {
                if (e->vertex->info.title == t) {
                    vertex = e->vertex;
                }

                if (!container::exists(visited, e->vertex)) {
                    p = container::allocateElm(e->vertex);
                    container::insertLast(planned, p);
                }
                e = e->next;
            }
        }
        return vertex;
    }

    antrean::List listBy(addr v, int c) {
        antrean::List q;
        antrean::createList(q);

        if (isEdgeEmpty(v, c)) return q;

        container::List visited, planned;
        container::createList(visited);
        container::createList(planned);

        container::addr p = container::allocateElm(v);
        container::insertLast(planned, p);

        edge e = getEdge(v, c);
        while (e != nullptr) {
            container::addr cAddr;
            container::deleteFirst(planned, cAddr);
            container::insertLast(visited, cAddr);

            if (!container::exists(visited, e->vertex)) {
                p = container::allocateElm(e->vertex);
                container::insertLast(planned, p);
            }
            e = e->next;
        }

        p = visited.first;
        while (p != nullptr) {
            antrean::addr qAddr = antrean::allocateElm(p->song);
            antrean::insertLast(q, qAddr);
            p = p->next;
        }
        return q;
    }
}

namespace container {
    void createList(List &l) {
        l.first = nullptr;
    }

    addr allocateElm(song::addr i) {
        addr p = new Elm();
        p->song = i;
        p->next = nullptr;
        return p;
    }

    bool isEmpty(List l) {
        return l.first == nullptr;
    }

    void insertLast(List &l, addr p) {
        if (isEmpty(l)) {
            l.first = p;
        } else {
            addr q = l.first;
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
        }
    }

    void deleteFirst(List &l, addr &p) {
        p = l.first;
        l.first = l.first->next;
        p->next = nullptr;
    }

    bool exists(List &l, song::addr p) {
        addr q = l.first;
        bool kondisi = false;
        while (q != nullptr) {
            if (q->song == p) {
                kondisi = true;
            }
            q = q->next;
        }
        return kondisi;
    }
}
