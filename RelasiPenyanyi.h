//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIPENYANYI_H
#define TUBES_STD_RELASIPENYANYI_H

#include "Lagu.h"
#include "Penyanyi.h"

namespace relasi_penyanyi {
    typedef struct Elm *address;

    struct Elm {
        penyanyi::address penyanyi;
        lagu::address lagu;
    };

    struct List {
        address first;
    };

    void createList(List &L);

    address allocateElm(penyanyi::address p, lagu::address a);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p);

    void showLagu(List &L, penyanyi::address p);

    void deletePenyanyi(List &L, penyanyi::address p);

    void deleteLagu(List &L, lagu::address l);
}

#endif //TUBES_STD_RELASIPENYANYI_H
