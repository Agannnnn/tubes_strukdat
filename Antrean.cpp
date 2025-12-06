//
// Created by ahmad on 18/11/2025.
//

#include "Antrean.h"

namespace antrean {
    void createList(List &L) {
        L.first = nullptr;
        L.last = nullptr;
    }

    address allocateElm(lagu::address l) {
        address p = new Elm;
        p->lagu = l;
        p->next = nullptr;
        p->prev = nullptr;
        return p;
    }

    bool isEmpty(List L) {
        return L.first == nullptr && L.last == nullptr;
    }

    void insertFirst(List &L, address p) {
        if (isEmpty(L)) {
            L.first = p;
            L.last = p;
        } else {
            p->next = L.first;
            L.first->prev = p;
            L.first = p;
        }
    }

    void insertAfter(List &L, address p, address q) {

    }

    void insertLast(List &L, address p) {
    }

    void deleteFirst(List &L, address &p) {
    }

    void deleteAfter(List &L, address p) {
    }

    void deleteLast(List &L, address p) {
    }

    void deleteAll(List &L) {
    }

    address find(List L, string j) {
    }

    void shuffle(List &L) {
    }
}
