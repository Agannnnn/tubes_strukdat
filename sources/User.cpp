#include "../headers/User.h"

#include "../headers/UserPlaylist.h"

namespace user {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(Infotype info) {
        addr elm1 = new Elm();
        elm1->info = info;
        elm1->next = nullptr;
        elm1->prev = nullptr;
        return elm1;
    }

    bool isEmpty(List list) {
        return list.first == nullptr && list.last == nullptr;
    }

    void insertAfter(List &list, addr &newElm, addr &prevElm) {
        if (prevElm == list.last) {
            prevElm->next = newElm;
            newElm->prev = prevElm;
            list.last = newElm;
        } else {
            newElm->next = prevElm->next;
            newElm->prev = prevElm;
            newElm->next->prev = newElm;
            prevElm->next = newElm;
        }
    }

    void insertLast(List &list, addr &newElm) {
        if (isEmpty(list)) {
            list.first = newElm;
            list.last = newElm;
        } else {
            newElm->prev = list.last;
            list.last->next = newElm;
            list.last = newElm;
        }
    }

    void remove(List &list, addr &elm, user_playlist::List &userPlaylistRelation) {
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

        user_playlist::removeUser(userPlaylistRelation, elm);
    }

    void list(List &list) {
        addr p = list.first;
        while (p != nullptr) {
            printf("%s\n", p->info.username.c_str());
            p = p->next;
        }
    }

    addr find(List list, string username, string password) {
        if (isEmpty(list)) return nullptr;

        addr p = list.first;
        bool found = false;
        while (p != nullptr && !found) {
            if (p->info.username == username && p->info.password == password) found = true;
            else p = p->next;
        }
        if (!found) return nullptr;
        return p;
    }

    addr findAdmin(List list, string username) {
        if (isEmpty(list)) return nullptr;
        addr p = list.first;
        bool found = false;
        while (p != nullptr && !found) {
            if (p->info.username == username) found = true;
            else p = p->next;
        }
        if (!found) return nullptr;
        return p;
    }
}
