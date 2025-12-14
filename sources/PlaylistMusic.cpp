#include "../headers/PlaylistMusic.h"
#include "../headers/Queue.h"

namespace playlist_music {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(playlist::addr playlist, music::addr music) {
        addr e = new Elm();
        e->music = music;
        e->playlist = playlist;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
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

    void removeMusic(List &list, music::addr &music) {
        addr elm1, elm2;
        elm1 = list.first;
        while (elm1 != nullptr) {
            elm2 = elm1;
            elm1 = elm1->next;
            if (elm2->music == music) {
                remove(list, elm2);
            }
        }
    }

    queue::List listMusic(List list, playlist::addr playlist) {
        queue::List queue;
        createList(queue);
        addr p = list.first;
        while (p != nullptr) {
            if (p->playlist == playlist) {
                queue::insertLast(queue, queue::allocateElm(p->music));
            }
            p = p->next;
        }
        return queue;
    }
}
