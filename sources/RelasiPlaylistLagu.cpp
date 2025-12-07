#include "../headers/RelasiPlaylistLagu.h"
#include "../headers/Antrean.h"
#include "../headers/RelasiUserPlaylist.h"

namespace relasi_playlist_lagu {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(playlist::addr playlist, lagu::addr lagu) {
        addr e = new Elm();
        e->lagu = lagu;
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

    void removeLagu(List &list, lagu::addr lagu) {
        addr p, q;
        p = list.first;
        while (p != nullptr) {
            q = p;
            p = p->next;
            if (q->lagu == lagu) {
                remove(list, q);
            }
        }
    }

    antrean::List listLagu(List list, playlist::addr playlist) {
        antrean::List antrean;
        createList(antrean);
        addr p = list.first;
        while (p != nullptr) {
            if (p->playlist == playlist) {
                antrean::Infotype info;
                info.lagu = p->lagu;
                antrean::insertLast(antrean, antrean::allocateElm(info));
            }
            p = p->next;
        }
        return antrean;
    }
}
