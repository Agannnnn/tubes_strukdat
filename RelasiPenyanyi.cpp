//
// Created by ahmad on 06/12/2025.
//

#include "RelasiPenyanyi.h"

using namespace std;

namespace relasi_penyanyi {
    void createList(List &L) {
        L.first = nullptr;
        L.last = nullptr;
    }

    address allocateElm(penyanyi::address p, lagu::address l) {
        address e = new Elm();
        e->penyanyi = p;
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

    void showLagu(List L, penyanyi::address p) {
        if (isEmpty(L)) {
            cout << "Penyanyi " << p->namaPenyanyi << " tidak memiliki lagu" << endl;
        } else {
            address q = L.first;
            cout << "Penyanyi " << p->namaPenyanyi << endl;
            cout << "Lagu" << endl;
            while (q != nullptr) {
                if (q->penyanyi == p) {
                    cout << "[-] " << q->lagu->judul << endl;
                }
                q = q->next;
            }
        }
    }

    void deletePenyanyi(List &L, penyanyi::address &p) {
        if (isEmpty(L)) {
            cout << "List penyanyi kosong" << endl;
        } else {
            address q = L.first;
            while (q != nullptr) {
                if (q->penyanyi == p) {
                    deleteElm(L, q);
                }
                q = q->next;
            }
        }
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
}
