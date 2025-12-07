#ifndef TUBES_STD_RELASIPENYANYI_H
#define TUBES_STD_RELASIPENYANYI_H

#include <iostream>

#include "Antrean.h"
#include "Lagu.h"

namespace penyanyi {
    typedef struct Elm *addr;
}

namespace relasi_penyanyi_lagu {
    typedef struct Elm *addr;

    struct Elm {
        lagu::addr lagu;
        penyanyi::addr penyanyi;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };

    /**
     * i.s. list l sembarang
     * f.s. list l terdefinisi sebagai list kosong
     * @param list list yang akan dibuat
     */
    void createList(List &list);

    /**
     * i.s. lagu dan penyanyi terdefinisi
     * f.s. mengembalikan address elemen baru dengan info lagu dan penyanyi
     * @param lagu address lagu
     * @param penyanyi address penyanyi
     * @return address elemen baru
     */
    addr allocateElm(lagu::addr lagu, penyanyi::addr penyanyi);

    /**
     * i.s. list l terdefinisi
     * f.s. mengembalikan true jika list kosong, false jika tidak
     * @param list list yang akan dicek
     * @return boolean status list kosong
     */
    bool isEmpty(List list);

    /**
     * i.s. list l dan address p terdefinisi
     * f.s. elemen p disisipkan di akhir list
     * @param list list yang akan disisipkan
     * @param baru elemen yang akan disisipkan
     */
    void insertLast(List &list, addr baru);

    /**
     * i.s. list l dan address p terdefinisi, p adalah elemen dari l
     * f.s. elemen p dihapus dari list l
     * @param list list yang akan dihapus elemennya
     * @param elm elemen yang akan dihapus
     */
    void remove(List &list, addr elm);

    /**
     * i.s. list l dan lagu terdefinisi
     * f.s. semua relasi yang berhubungan dengan lagu dihapus dari list l
     * @param list list yang akan dihapus relasinya
     * @param lagu lagu yang akan dihapus relasinya
     */
    void removeLagu(List &list, lagu::addr lagu);

    /**
     * i.s. list l dan penyanyi terdefinisi
     * f.s. semua relasi yang berhubungan dengan penyanyi dihapus dari list l
     * @param list list yang akan dihapus relasinya
     * @param penyanyi penyanyi yang akan dihapus relasinya
     */
    void removePenyanyi(List &list, penyanyi::addr penyanyi);

    /**
     * i.s. list l dan lagu terdefinisi
     * f.s. mengembalikan address penyanyi dari lagu, atau null jika tidak ditemukan
     * @param list list yang akan dicari
     * @param lagu lagu yang akan dicari penyanyinya
     * @return address penyanyi
     */
    penyanyi::addr findPenyanyi(List list, lagu::addr lagu);

    /**
     * i.s. list l dan penyanyi terdefinisi
     * f.s. mengembalikan list lagu dari penyanyi
     * @param list list yang akan dicari
     * @param penyanyi penyanyi yang akan dicari lagunya
     * @return list lagu
     */
    antrean::List listLagu(List list, penyanyi::addr penyanyi);
}

#endif //TUBES_STD_RELASIPENYANYI_H