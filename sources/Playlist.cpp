#include "../headers/Playlist.h"

#include "../headers/PlaylistMusic.h"
#include "../headers/UserPlaylist.h"


namespace playlist {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(string title) {
        addr e = new Elm();
        e->title = title;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
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

    void insertLast(List &list, addr &elm, user::addr user, user_playlist::List &userPlaylist) {
        if (isEmpty(list)) {
            list.first = elm;
            list.last = elm;
        } else {
            elm->prev = list.last;
            list.last->next = elm;
            list.last = elm;
        }

        user_playlist::addr up = user_playlist::allocateElm(user, elm);
        user_playlist::insertLast(userPlaylist, up);
    }

    void remove(List &list, addr &elm, playlist_music::List &playlistMusicRelation,
                user_playlist::List &userPlaylistRelation) {
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

        playlist_music::removePlaylist(playlistMusicRelation, elm);
        user_playlist::removePlaylist(userPlaylistRelation, elm);
    }

    addr find(List list, string title) {
        if (isEmpty(list)) return nullptr;

        addr p = list.first;
        bool found = false;
        while (p != nullptr && !found) {
            if (p->title == title) {
                found = true;
            } else {
                p = p->next;
            }
        }
        return p;
    }
}
