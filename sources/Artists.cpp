#include  "../headers/Artists.h"

#include "../headers/Music.h"
#include "../headers/Queue.h"
#include "../headers/SingerMusic.h"

namespace artists {
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

    void insertAfter(List &list, addr newElm, addr prevElm) {
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

    void insertLast(List &list, addr newElm) {
        if (isEmpty(list)) {
            list.first = newElm;
            list.last = newElm;
        } else {
            newElm->prev = list.last;
            list.last->next = newElm;
            list.last = newElm;
        }
    }

    void remove(List &list, addr &elm, singer_music::List &relations) {
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

        singer_music::removeSinger(relations, elm);
    }

    void display(List list) {
        addr elm1 = list.first;
        while (elm1 != nullptr) {
            printf("| %-89s (%4d) |\n", elm1->info.name.c_str(), elm1->info.debutYear);
            elm1 = elm1->next;
        }
    }

    addr find(List list, string name) {
        if (isEmpty(list)) return nullptr;

        addr elm = list.first;
        bool found = false;
        while (elm != nullptr && !found) {
            if (elm->info.name == name) found = true;
            else elm = elm->next;
        }
        if (!found) return nullptr;
        return elm;
    }
}
