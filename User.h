//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_USER_H
#define TUBES_STD_USER_H

#include <iostream>
#include "Playlist.h"

using namespace std;

namespace user {
    typedef struct User *address;

    struct Elm {
        string username;
        string password;
        string namaPengguna;
    };

    struct List {
        address next;
        address prev;
    };

    void createList(List &L);

    address allocateElm(string username, string password, string namaPengguna);

    bool isEmpty(List L);

    void insertLast(List &L, address p);

    void deleteElm(List &L, address p, address &q);

    address find(List L, string username);

    address login(List L, string username, string password);
}

#endif //TUBES_STD_USER_H
