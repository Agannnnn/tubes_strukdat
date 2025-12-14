#include "../headers/Queue.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <thread>

using namespace std;

namespace queue {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(music::addr music) {
        addr elm1 = new Elm();
        elm1->music = music;
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

    void remove(List &list, addr &elm) {
        if (list.first == elm && list.last == elm) {
            list.first = nullptr;
            list.last = nullptr;
        } else if (list.first == elm) {
            list.first = elm->next;
            list.first->prev = nullptr;
        } else if (list.last == elm) {
            list.last = elm->prev;
            list.last->next = nullptr;
        } else {
            elm->prev->next = elm->next;
            elm->next->prev = elm->prev;
        }

        elm->prev = nullptr;
        elm->next = nullptr;
    }

    void display(List list) {
        addr elm1 = list.first;
        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-78s | %-15s |\n", "Title", "Duration (s)");
        printf("+%s+\n", string(98, '-').c_str());
        while (elm1 != nullptr) {
            printf("| %-78s | %-15d |\n", elm1->music->info.title.c_str(), elm1->music->info.duration);
            elm1 = elm1->next;
        }
        printf("+%s+\n", string(98, '-').c_str());
    }

    addr find(List list, string t) {
        if (isEmpty(list)) return nullptr;

        addr elm1 = list.first;
        bool found = false;
        while (elm1 != nullptr && !found) {
            if (elm1->music->info.title == t) found = true;
            else elm1 = elm1->next;
        }
        return elm1;
    }

    void shuffle(List &list) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);

        addr elm1, elm2;
        elm1 = list.first;
        while (elm1 != nullptr) {
            elm2 = elm1;
            double rng = dis(gen);
            while (rng > 0.3 && elm2->next != nullptr) {
                rng = dis(gen);
                elm2 = elm2->next;
            }
            music::addr elm3 = elm2->music;
            elm2->music = elm1->music;
            elm1->music = elm3;
            elm1 = elm1->next;
        }
    }

    void joinQueue(List &list1, List list2) {
        if (isEmpty(list2)) return;
        addr elm = list2.first;
        while (elm != nullptr) {
            insertLast(list1, elm);
            elm = elm->next;
        }
    }

    void clear(List &list) {
        if (isEmpty(list)) return;
        addr elm = list.first;
        while (!isEmpty(list)) {
            remove(list, elm);
            elm = list.first;
        }
    }
}
