//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIPLAYLIST_H
#define TUBES_STD_RELASIPLAYLIST_H
#include "Playlist.h"

namespace relasi_playlist {
    typedef struct Elm *address;

    struct Elm {
        playlist::address playlist;
        lagu::address lagu;
        address next;
    };

    struct List {
        address first;
    };

    void createList(List &L);

    address allocateElm(playlist::address p, lagu::address l);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p);

    antrean::List fetchLagu(List L, playlist::address p);

    void deleteLagu(List &L, lagu::address p);

    void deletePlaylist(List &L, playlist::address p);
}

#endif //TUBES_STD_RELASIPLAYLIST_H
