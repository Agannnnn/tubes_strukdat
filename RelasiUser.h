//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIUSER_H
#define TUBES_STD_RELASIUSER_H

#include  <iostream>

#include "User.h"

using namespace std;

namespace relasi_user {
    typedef struct Elm *address;

    struct Elm {
        user::address user;
        playlist::address playlist;
        address next;
    };

    struct List {
        address first;
    };

    void createList(List &L);

    address allocateElm(user::address u, playlist::address p);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p);

    void showPlaylists(List &L, user::address u);

    void deleteUser(List &L, user::address u);

    void deletePlaylist(List &L, playlist::address p);
}

#endif //TUBES_STD_RELASIUSER_H
