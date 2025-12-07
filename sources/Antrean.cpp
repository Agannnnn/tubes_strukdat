//
// Created by ahmad on 18/11/2025.
//

#include "../headers/Antrean.h"

#include <random>

namespace antrean {
    void createList(List &l) {
        l.first = nullptr;
        l.last = nullptr;
    }

    addr allocateElm(Infotype i) {
        addr e = new Elm();
        e->info = i;
        e->next = nullptr;
        e->prev = nullptr;
        return e;
    }

    bool isEmpty(List l) {
        return l.first == nullptr && l.last == nullptr;
    }

    void insertAfter(List &l, addr p, addr q) {
        if (q == l.last) {
            q->next = p;
            p->prev = q;
            l.last = p;
        } else {
            p->next = q->next;
            p->prev = q;
            p->next->prev = p;
            q->next = p;
        }
    }

    void insertLast(List &l, addr p) {
        if (isEmpty(l)) {
            l.first = p;
            l.last = p;
        } else {
            p->prev = l.last;
            l.last->next = p;
            l.last = p;
        }
    }

    void remove(List &l, addr &p) {
        if (l.first == p && l.last == p) {
            l.first = nullptr;
            l.last = nullptr;
        } else if (l.first == p) {
            l.first = p->next;
            p->next->prev = nullptr;
        } else if (l.last == p) {
            l.last = p->prev;
            p->prev->next = nullptr;
        } else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        p->prev = nullptr;
        p->next = nullptr;

        delete p;
    }

    void displayAntrean(List l) {
        addr p = l.first;
        cout << "daftar lagu" << endl;
        while (p != nullptr) {
            cout << p->info.lagu->info.judul << ", ";
            p = p->next;
        }
        cout << endl;
    }

    addr find(List list, string judulLagu) {
        addr p = list.first;
        bool kondisi = false;
        while (p != nullptr && !kondisi) {
            if (p->info.lagu->info.judul == judulLagu) {
                kondisi = true;
            }
            p = p->next;
        }
        return p;
    }

    void shuffle(List &l) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);

        addr p, q;
        p = l.first;
        while (p != nullptr) {
            q = p;
            float rng = dis(gen);
            while (rng > 0.3 && q->next != nullptr) {
                rng = dis(gen);
                q = q->next;
            }
            lagu::addr temp = q->info.lagu;
            q->info.lagu = p->info.lagu;
            p->info.lagu = temp;
            p = p->next;
        }
    }

    void play(addr &lagu) {
        // TODO: implementasi fungsi untuk play lagu supaya bisa didengar
    }

    void pause(addr p) {
        // TODO: implementasi fungsi untuk pause lagu yang sedang diputar
    }
}
