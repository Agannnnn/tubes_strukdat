//
// Created by ahmad on 06/12/2025.
//

#include "RelasiUser.h"

namespace relasi_user {
    void createList(List &L) {
        L.first = nullptr;
        L.last = nullptr;
    }

    address allocateElm(user::address u, playlist::address p) {
        address e = new Elm();
        e->user = u;
        e->playlist = p;
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

    void showPlaylists(List &L, user::address u) {
        if (isEmpty(L)) {
            cout << "User " << u->namaPengguna << " tidak memiliki playlist" << endl;
        } else {
            address q = L.first;
            cout << "User " << u->namaPengguna << endl;
            cout << "Playlist" << endl;
            while (q != nullptr) {
                if (q->user == u) {
                    cout << "[-] " << q->playlist->namaPlaylist << endl;
                }
                q = q->next;
            }
        }
    }

    void deleteUser(List &L, user::address &u) {
        if (isEmpty(L)) {
            cout << "List user kosong" << endl;
        } else {
            address q = L.first;
            while (q != nullptr) {
                if (q->user == u) {
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
