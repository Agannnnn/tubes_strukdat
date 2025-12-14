#include "../headers/UserPlaylist.h"

namespace user_playlist {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(user::addr user, playlist::addr playlist) {
        addr elm1 = new Elm();
        elm1->user = user;
        elm1->playlist = playlist;
        elm1->next = nullptr;
        elm1->prev = nullptr;
        return elm1;
    }

    bool isEmpty(List list) {
        return list.first == nullptr && list.last == nullptr;
    }

    void insertLast(List &list, addr &elm) {
        if (isEmpty(list)) {
            list.first = elm;
            list.last = elm;
        } else {
            list.last->next = elm;
            elm->prev = list.last;
            list.last = elm;
        }
    }

    void remove(List &list, addr &elm) {
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
    }

    void removeUser(List &list, user::addr &user) {
        addr elm1, elm2;
        elm1 = list.first;
        while (elm1 != nullptr) {
            elm2 = elm1;
            elm1 = elm1->next;
            if (elm2->user == user) {
                remove(list, elm2);
            }
        }
    }

    void removePlaylist(List &list, playlist::addr &playlist) {
        addr elm1, elm2;
        elm1 = list.first;
        while (elm1 != nullptr) {
            elm2 = elm1;
            elm1 = elm1->next;
            if (elm2->playlist == playlist) {
                remove(list, elm2);
            }
        }
    }

    void displayPlaylist(List list, user::addr user) {
        printf("+%s+\n", string(98, '-').c_str());
        printf("| PLAYLIST COLLECTION %-76s |\n", user->info.fullName.c_str());
        printf("+%s+\n", string(98, '-').c_str());

        addr elm1 = list.first;
        while (elm1 != nullptr) {
            if (elm1->user == user) printf("| %-96s |\n", elm1->playlist->title.c_str());
            elm1 = elm1->next;
        }
        printf("+%s+\n", string(98, '-').c_str());
    }

    user::addr findUser(List list, playlist::addr playlist) {
        if (isEmpty(list)) return nullptr;
        addr elm = list.first;
        bool found = false;
        while (elm != nullptr && !found) {
            if (elm->playlist == playlist) found = true;
            else elm = elm->next;
        }
        if (found) return elm->user;
        return nullptr;
    }
}
