//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_PENYANYI_H
#define TUBES_STD_PENYANYI_H

#include <iostream>

using namespace std;

namespace penyanyi {
    typedef struct Elm *address;

    struct Elm {
        string namaPenyanyi;
        int tahunDebit;
    };

    struct List {
        address first;
        address last;
    };

    void createList(List &L);

    address allocateElm(string n, int t);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p, address &q);

    address findElm(List L, string n);
}

#endif //TUBES_STD_PENYANYI_H
