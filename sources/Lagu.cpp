#include "../headers/Lagu.h"

namespace lagu {
    void createGraph(Graph &g) {
        g.first = nullptr;
    }

    addr allocateNode(Infotype i) {
        addr e = new Vertex();
        e->info = i;
        e->nextLagu = nullptr;
        return e;
    }

    edge allocateEdge(addr n) {
        edge e = new Edge();
        e->node = n;
        e->next = nullptr;
        return e;
    }

    bool isEmpty(Graph g) {
        return g.first == nullptr;
    }

    bool isEdgeEmpty(addr n) {
        return n->nextLagu == nullptr;
    }

    bool isEdgeEmptyGenre(addr node) {
        return node->info.nextGenre == nullptr;
    }

    bool isEdgeEmptyBahasa(addr n) {
        return n->info.nextBahasa == nullptr;
    }

    bool isConnected(addr n1, addr n2) {
        if (isEdgeEmpty(n1)) {
            return false;
        }
        edge e = n1->nextLagu;
        bool kondisi = false;
        while (e != nullptr && !kondisi) {
            if (e->node == n2) {
                kondisi = true;
            }
            e = e->next;
        }
        return kondisi;
    }

    bool isConnectedGenre(addr n1, addr n2) {
        if (isEdgeEmpty(n1)) {
            return false;
        }
        edge e = n1->info.nextGenre;
        bool kondisi = false;
        while (e != nullptr && !kondisi) {
            if (e->node == n2) {
                kondisi = true;
            }
            e = e->next;
        }
        return kondisi;
    }

    bool isConnectedBahasa(addr n1, addr n2) {
        if (isEdgeEmpty(n1)) {
            return false;
        }
        edge e = n1->info.nextBahasa;
        bool kondisi = false;
        while (e != nullptr && !kondisi) {
            if (e->node == n2) {
                kondisi = true;
            }
            e = e->next;
        }
        return kondisi;
    }

    void insertNode(Graph &g, addr n) {
        if (isEmpty(g)) {
            g.first = n;
        } else {
            connectNode(g.first, n);
        }
    }

    void displayEdge(addr n) {
        edge e = n->nextLagu;
        cout << "koneksi " << n->info.judul << ": ";
        while (e != nullptr) {
            cout << e->node->info.judul << ", ";
            e = e->next;
        }
        cout << endl;
    }

    void connectNode(addr &n1, addr &n2) {
        if (isConnected(n1, n2)) return;
        if (isEdgeEmpty(n1)) {
            n1->nextLagu = allocateEdge(n2);;
        } else {
            edge e = n1->nextLagu;
            while (e->next != nullptr) {
                e = e->next;
            }
            e->next = allocateEdge(n2);;
        }
        connectNode(n2, n1);
    }

    void disconnectNode(addr &n1, addr &n2) {
        if (!isConnected(n1, n2)) return;
        if (n1->nextLagu->node == n2) {
            edge e = n1->nextLagu;
            n1->nextLagu = e->next;
            e->next = nullptr;

            delete e;
        } else {
            edge e = n1->nextLagu;
            while (e->next != nullptr && e->next->node != n2) {
                e = e->next;
            }
            edge f = e->next;
            e->next = f->next;
            f->next = nullptr;

            delete f;
        }
        disconnectNode(n2, n1);
    }

    void displayEdgeGenre(addr n) {
        edge e = n->info.nextGenre;
        cout << "koneksi " << n->info.judul << ": ";
        while (e != nullptr) {
            cout << e->node->info.judul << ", ";
            e = e->next;
        }
        cout << endl;
    }

    void connectNodeGenre(addr &n1, addr &n2) {
        if (isConnectedGenre(n1, n2)) return;
        if (isEdgeEmptyGenre(n1)) {
            n1->info.nextGenre = allocateEdge(n2);
        } else {
            edge e = n1->info.nextGenre;
            while (e->next != nullptr) {
                e = e->next;
            }
            e->next = allocateEdge(n2);
        }
        connectNodeGenre(n2, n1);
    }

    void disconnectNodeGenre(addr &node1, addr &n2) {
        if (!isConnectedGenre(node1, n2)) return;
        if (node1->info.nextGenre->node == n2) {
            edge e = node1->info.nextGenre;
            node1->info.nextGenre = e->next;
            e->next = nullptr;

            delete e;
        } else {
            edge e = node1->info.nextGenre;
            while (e->next != nullptr && e->next->node != n2) {
                e = e->next;
            }
            edge f = e->next;
            e->next = f->next;
            f->next = nullptr;

            delete f;
        }
        disconnectNodeGenre(n2, node1);
    }

    void displayEdgeBahasa(addr n) {
        edge e = n->info.nextBahasa;
        cout << "koneksi " << n->info.judul << ": ";
        while (e != nullptr) {
            cout << e->node->info.judul << ", ";
            e = e->next;
        }
        cout << endl;
    }

    void connectNodeBahasa(addr &n1, addr &n2) {
        if (isConnectedBahasa(n1, n2)) return;
        if (isEdgeEmptyBahasa(n1)) {
            n1->info.nextBahasa = allocateEdge(n2);
        } else {
            edge e = n1->info.nextBahasa;
            while (e->next != nullptr) {
                e = e->next;
            }
            e->next = allocateEdge(n2);
        }
        connectNodeBahasa(n2, n1);
    }

    void disconnectNodeBahasa(addr &n1, addr &n2) {
        if (!isConnectedBahasa(n1, n2)) return;
        if (n1->info.nextBahasa->node == n2) {
            edge e = n1->info.nextBahasa;
            n1->info.nextBahasa = e->next;
            e->next = nullptr;

            delete e;
        } else {
            edge e = n1->info.nextBahasa;
            while (e->next != nullptr && e->next->node != n2) {
                e = e->next;
            }
            edge f = e->next;
            e->next = f->next;
            f->next = nullptr;

            delete f;
        }
        disconnectNodeBahasa(n2, n1);
    }

    void displayLagu(Graph g) {
        if (isEmpty(g)) { return; }

        list_traversal::List dikunjungi, tujuan;
        list_traversal::createList(dikunjungi);
        list_traversal::createList(tujuan);

        list_traversal::addr p = list_traversal::allocateElm(g.first);
        list_traversal::insertLast(tujuan, p);

        while (!list_traversal::isEmpty(tujuan)) {
            list_traversal::addr q;
            list_traversal::deleteFirst(tujuan, q);
            list_traversal::insertLast(dikunjungi, q);

            edge e = q->info->nextLagu;
            while (e != nullptr) {
                if (!list_traversal::exists(dikunjungi, e->node)) {
                    p = list_traversal::allocateElm(e->node);
                    list_traversal::insertLast(tujuan, p);
                }
                e = e->next;
            }
        }

        list_traversal::addr q;
        q = dikunjungi.first;
        while (q != nullptr) {
            cout << q->info->info.judul << endl;
            q = q->next;
        }
    }
}

namespace list_traversal {
    void createList(List &l) {
        l.first = nullptr;
    }

    addr allocateElm(lagu::addr i) {
        addr p = new Elm();
        p->info = i;
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

    bool exists(List &l, lagu::addr p) {
        addr q = l.first;
        bool kondisi = false;
        while (q != nullptr) {
            if (q->info == p) {
                kondisi = true;
            }
            q = q->next;
        }
        return kondisi;
    }
}
