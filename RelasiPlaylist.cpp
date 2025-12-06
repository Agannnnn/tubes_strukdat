//
// Created by ahmad on 06/12/2025.
//

#include "RelasiPlaylist.h"

namespace relasi_playlist {
    void createList(List &L) {
        L.first = nullptr;
        L.last = nullptr;
    }

    address allocateElm(playlist::address p, lagu::address l) {
        address e = new Elm();
        e->playlist = p;
        e->lagu = l;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
    }

    bool isEmpty(List L) {
        return L.first == nullptr && L.last == nullptr;
    }

    void insertLast(List &L, address p) {
        if (isEmpty(L)) {
            L.first = p;
            L.last = p;
        } else {
            L.last->next = p;
            p->prev = L.last;
            L.last = p;
        }
    }

    void deleteElm(List &L, address &p) {
        if (L.first == p && L.last == p) {
            L.first = nullptr;
            L.last = nullptr;
        } else if (L.first == p) {
            L.first = p->next;
            p->next->prev = nullptr;
        } else if (L.last == p) {
            L.last = p->prev;
            p->prev->next = nullptr;
        } else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
    }

    antrean::List fetchLagu(List L, playlist::address p) {
        antrean::List antrean{};
        antrean::createList(antrean);

        if (!isEmpty(L)) {
            address e = L.first;
            while (e != nullptr) {
                if (e->playlist == p) {
                    antrean::address eAntrean = antrean::allocateElm(e->lagu);
                    antrean::insertLast(antrean, eAntrean);
                }
                e = e->next;
            }
        }

        return antrean;
    }

    void deleteLagu(List &L, lagu::address &l) {
        if (isEmpty(L)) {
            cout << "List lagu kosong" << endl;
        } else {
            address q = L.first;
            while (q != nullptr) {
                if (q->lagu == l) {
                    deleteElm(L, q);
                }
                q = q->next;
            }
        }
    }

    void deletePlaylist(List &L, playlist::address &p) {
        if (isEmpty(L)) {
            cout << "List playlist kosong" << endl;
        } else {
            address q = L.first;
            while (q != nullptr) {
                if (q->playlist == p) {
                    deleteElm(L, q);
                }
                q = q->next;
            }
        }
    }
}
