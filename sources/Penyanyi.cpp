#include  "../headers/Penyanyi.h"

#include "../headers/RelasiPenyanyiLagu.h"

namespace penyanyi {
    void createList(List &l) {
        l.first = nullptr;
        l.last = nullptr;
    }

    addr allocateElm(Infotype i) {
        addr e = new Elm();
        e->info = i;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
    }

    bool isEmpty(List l) {
        return l.first == nullptr && l.last == nullptr;
    }

    void insertAfter(List &l, addr p, addr q) {
        if (q == l.last) {
            q->next = p;
            p->prev = q;
            l.last = p;
        } else {
            p->next = q->next;
            p->prev = q;
            p->next->prev = p;
            q->next = p;
        }
    }

    void insertLast(List &l, addr p) {
        if (isEmpty(l)) {
            l.first = p;
            l.last = p;
        } else {
            p->prev = l.last;
            l.last->next = p;
            l.last = p;
        }
    }

    void remove(List &l, addr &p, relasi_penyanyi_lagu::List &rpl) {
        if (l.first == p && l.last == p) {
            l.first = nullptr;
            l.last = nullptr;
        } else if (l.first == p) {
            l.first = p->next;
            p->next->prev = nullptr;
        } else if (l.last == p) {
            l.last = p->prev;
            p->prev->next = nullptr;
        } else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        p->prev = nullptr;
        p->next = nullptr;

        relasi_penyanyi_lagu::removePenyanyi(rpl, p);

        delete p;
    }

    void displayPenyanyi(List l) {
        addr p = l.first;
        cout << "daftar penyanyi" << endl;
        while (p != nullptr) {
            cout << p->info.nama << " (" << p->info.tahunDebut << ")" << endl;
            p = p->next;
        }
    }
}
