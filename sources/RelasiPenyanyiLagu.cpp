#include "../headers/RelasiPenyanyiLagu.h"

using namespace std;

namespace relasi_penyanyi_lagu {
    void createList(List &list) {
        list.first = nullptr;
        list.last = nullptr;
    }

    addr allocateElm(lagu::addr lagu, penyanyi::addr penyanyi) {
        addr e = new Elm();
        e->lagu = lagu;
        e->penyanyi = penyanyi;
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

    void removePenyanyi(List &list, penyanyi::addr penyanyi) {
        addr p, q;
        p = list.first;
        while (p != nullptr) {
            q = p;
            p = p->next;
            if (q->penyanyi == penyanyi) {
                remove(list, q);
            }
        }
    }

    penyanyi::addr findPenyanyi(List list, lagu::addr lagu) {
        addr p = list.first;
        penyanyi::addr penyanyi = nullptr;
        while (p != nullptr && penyanyi == nullptr) {
            if (p->lagu == lagu) {
                penyanyi = p->penyanyi;
            }
            p = p->next;
        }
        return penyanyi;
    }

    antrean::List listLagu(List list, penyanyi::addr penyanyi) {
        antrean::List antrean;
        createList(antrean);
        addr p = list.first;
        while (p != nullptr) {
            if (p->penyanyi == penyanyi) {
                antrean::Infotype info;
                info.lagu = p->lagu;
                antrean::insertLast(antrean, antrean::allocateElm(info));
            }
            p = p->next;
        }
        return antrean;
    }
}
