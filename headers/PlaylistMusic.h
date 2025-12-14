#ifndef TUBES_STD_RELASIPLAYLIST_H
#define TUBES_STD_RELASIPLAYLIST_H

#include "ADT.h"

namespace playlist_music {
    void createList(List &list);

    addr allocateElm(playlist::addr playlist, music::addr music);

    bool isEmpty(List list);

    void insertLast(List &list, addr &elm);

    void remove(List &list, addr &elm);

    void removePlaylist(List &list, playlist::addr &playlist);

    void removeMusic(List &list, music::addr &music);

    queue::List listMusic(List list, playlist::addr playlist);
}

#endif //TUBES_STD_RELASIPLAYLIST_H
