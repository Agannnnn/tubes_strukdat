#ifndef TUBES_STD_RELASIPENYANYI_H
#define TUBES_STD_RELASIPENYANYI_H

#include "ADT.h"

namespace singer_music {
    void createList(List &list);

    addr allocateElm(music::addr music, artists::addr singer);

    bool isEmpty(List list);

    void insertLast(List &list, addr &newElm);

    void remove(List &list, addr &elm);

    void removeMusic(List &list, music::addr music);

    void removeSinger(List &list, artists::addr singer);

    addr find(List list, artists::addr singer, music::addr music);

    artists::addr findSinger(List list, music::addr music);

    queue::List listMusic(List list, artists::addr singer);
}

#endif //TUBES_STD_RELASIPENYANYI_H
