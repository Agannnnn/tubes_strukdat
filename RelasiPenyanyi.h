//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIPENYANYI_H
#define TUBES_STD_RELASIPENYANYI_H

#include "Lagu.h"
#include "Penyanyi.h"

namespace relasi_penyanyi {
    typedef struct Elm *address;

    struct Elm {
        penyanyi::address penyanyi;
        lagu::address lagu;
        address next;
        address prev;
    };

    struct List {
        address first;
        address last;
    };

    /**
     * I.S. list yang sedang dioperasikan diberikan sebagai argumen
     *
     * F.S. atribut first dan last pada list bernilai nullptr
     *
     * @param L list yang sedang dioperasikan
     */
    void createList(List &L);

    /**
     * I.S. address penyanyi dan address lagu diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen relasi yang berisi address penyanyi dan address lagu
     *
     * @param p address elemen penyanyi
     * @param a address elemen lagu
     * @return address elemen relasi penyanyi dengan lagu
     */
    address allocateElm(penyanyi::address p, lagu::address a);

    /**
     * I.S. list yang ingin dioperasikan dan address elemen relasi yang ingin ditambahkan diberikan sebagai argumen
     *
     * F.S. address elemen relasi yang ingin ditambahkan disimpan sebagai elemen terakhir pada list
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen relasi yang ingin dimasukkan
     */
    void insertLast(List &L, address p);

    /**
     * I.S. list yang sedang dioperasikan dan address elemen relasi yang ingin dihapus diberikan sebagai argumen
     *
     * F.S. elemen relasi yang ingin dihapus telah hilang dari list
     *
     * @param L list yang sedang dioperasikan
     * @param p address elemen relasi yang ingin dihapus
     */
    void deleteElm(List &L, address &p);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address penyanyi yang ingin ditampilkan lagunya diberikan sebagai argumen
     *
     * F.S. seluruh lagu yang terhubung dengan penyanyi tersebut ditampilkan
     *
     * @param L list relasi yang sedang dioperasikan
     * @param p address penyanyi yang lagunya ingin ditampilkan
     */
    void showLagu(List &L, penyanyi::address p);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address penyanyi yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang melibatkan penyanyi tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param p address penyanyi yang relasinya ingin dihapus
     */
    void deletePenyanyi(List &L, penyanyi::address &p);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address lagu yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang melibatkan lagu tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param l address lagu yang relasinya ingin dihapus
     */
    void deleteLagu(List &L, lagu::address &l);
}

#endif //TUBES_STD_RELASIPENYANYI_H
