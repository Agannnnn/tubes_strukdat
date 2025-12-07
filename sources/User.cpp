#include "../headers/User.h"

#include "../headers/RelasiUserPlaylist.h"

namespace user {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(Infotype info) {
        addr e = new Elm();
        e->info = info;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
    }

    bool isEmpty(List list) {
        return list.first == nullptr && list.last == nullptr;
    }

    void insertAfter(List &list, addr baru, addr sebelum) {
        if (sebelum == list.last) {
            sebelum->next = baru;
            baru->prev = sebelum;
            list.last = baru;
        } else {
            baru->next = sebelum->next;
            baru->prev = sebelum;
            baru->next->prev = baru;
            sebelum->next = baru;
        }
    }

    void insertLast(List &list, addr baru) {
        if (isEmpty(list)) {
            list.first = baru;
            list.last = baru;
        } else {
            baru->prev = list.last;
            list.last->next = baru;
            list.last = baru;
        }
    }

    void remove(List &list, addr &elm, relasi_user_playlist::List listRelasi) {
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

        relasi_user_playlist::removeUser(listRelasi, elm);

        delete elm;
    }

    addr find(List list, string username, string password) {
        addr p = list.first;
        bool kondisi = false;
        while (p != nullptr && !kondisi) {
            if (p->info.username == username && p->info.password == password) {
                kondisi = true;
            }
            p = p->next;
        }
        return p;
    }
}
