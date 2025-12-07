//
// Created by ahmad on 06/12/2025.
//

#include "../headers/RelasiUserPlaylist.h"

namespace relasi_user_playlist {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(user::addr user, playlist::addr playlist) {
        addr e = new Elm();
        e->user = user;
        e->playlist = playlist;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
    }

    bool isEmpty(List list) {
        return list.first == nullptr && list.last == nullptr;
    }

    void insertLast(List &list, addr baru) {
        if (isEmpty(list)) {
            list.first = baru;
            list.last = baru;
        } else {
            list.last->next = baru;
            baru->prev = list.last;
            list.last = baru;
        }
    }

    void remove(List &list, addr elm) {
        if (list.first == elm && list.last == elm) {
            list.first = nullptr;
            list.last = nullptr;
        } else if (list.first == elm) {
            list.first = elm->next;
            elm->next->prev = nullptr;
        } else if (list.last == elm) {
            list.last = elm->prev;
            elm->prev->next = nullptr;
        } else {
            elm->prev->next = elm->next;
            elm->next->prev = elm->prev;
        }

        elm->prev = nullptr;
        elm->next = nullptr;

        delete elm;
    }

    void removeUser(List &list, user::addr user) {
        addr p, q;
        p = list.first;
        while (p != nullptr) {
            q = p;
            p = p->next;
            if (q->user == user) {
                remove(list, q);
            }
        }
    }

    void removePlaylist(List &list, playlist::addr playlist) {
        addr p, q;
        p = list.first;
        while (p != nullptr) {
            q = p;
            p = p->next;
            if (q->playlist == playlist) {
                remove(list, q);
            }
        }
    }

    void displayPlaylist(List list, user::addr user) {
        addr p = list.first;
        cout << "daftar playlist " << user->info.namaPanjang << ": ";
        while (p != nullptr) {
            if (p->user == user) {
                cout << p->playlist->info.judul << ", ";
            }
            p = p->next;
        }
        cout << endl;
    }
}
