//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_PLAYLIST_H
#define TUBES_STD_PLAYLIST_H

#include "Antrean.h"

using namespace std;

namespace playlist {
    typedef struct Elm *address;

    struct Elm {
        string namaPlaylist;
        address next;
        address prev;
    };

    struct List {
        address first;
        address last;
    };

    void createList(List &L);

    address allocateElm(string n);

    bool isEmpty(List L);

    void insertFirst(List &L, address p);

    void insertAfter(List &L, address p, address q);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p, address &q);
}

#endif //TUBES_STD_PLAYLIST_H
