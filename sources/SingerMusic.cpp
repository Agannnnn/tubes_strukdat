#include "../headers/SingerMusic.h"

#include "../headers/Queue.h"
#include "../headers/Artists.h"

using namespace std;

namespace singer_music {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(music::addr music, artists::addr singer) {
        addr elm1 = new Elm();
        elm1->music = music;
        elm1->singer = singer;
        elm1->next = nullptr;
        elm1->prev = nullptr;
        return elm1;
    }


    bool isEmpty(List list) {
        return list.first == nullptr && list.last == nullptr;
    }

    void insertLast(List &list, addr &newElm) {
        if (isEmpty(list)) {
            list.first = newElm;
            list.last = newElm;
        } else {
            list.last->next = newElm;
            newElm->prev = list.last;
            list.last = newElm;
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

    void removeMusic(List &list, music::addr music) {
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

    void removeSinger(List &list, artists::addr singer) {
        addr elm1, elm2;
        elm1 = list.first;
        while (elm1 != nullptr) {
            elm2 = elm1;
            elm1 = elm1->next;
            if (elm2->singer == singer) {
                remove(list, elm2);
            }
        }
    }

    addr find(List list, artists::addr singer, music::addr music) {
        if (isEmpty(list)) return nullptr;
        addr elm1 = list.first;
        bool found = false;
        while (elm1 != nullptr && !found) {
            if (elm1->music == music && elm1->singer == singer) {
                found = true;
            } else {
                elm1 = elm1->next;
            }
        }
        return elm1;
    }

    artists::addr findSinger(List list, music::addr music) {
        if (isEmpty(list)) return nullptr;

        addr elm1 = list.first;
        artists::addr singer = nullptr;
        while (elm1 != nullptr && singer == nullptr) {
            if (elm1->music == music) {
                singer = elm1->singer;
            }
            elm1 = elm1->next;
        }
        return singer;
    }

    queue::List listMusic(List list, artists::addr singer) {
        queue::List queue;
        queue::createList(queue);
        addr elm1 = list.first;
        while (elm1 != nullptr) {
            if (elm1->singer == singer) {
                queue::addr elmQueue = queue::allocateElm(elm1->music);
                queue::insertLast(queue, elmQueue);
            }
            elm1 = elm1->next;
        }
        return queue;
    }
}
