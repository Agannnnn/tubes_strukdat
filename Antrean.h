//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_ANTRIANLAGU_H
#define TUBES_STD_ANTRIANLAGU_H

#include "Lagu.h"

using namespace std;

namespace antrean {
    typedef struct Elm *address;

    struct Elm {
        lagu::address lagu;
        address next;
        address prev;
    };

    struct List {
        address first;
        address last;
    };

    /**
     * I.S. list yang ingin dibuat diberikan sebagai argumen
     *
     * F.S. atribut first dan last pada list bernilai nullptr
     *
     * @param L list yang sedang dioperasikan
     */
    void createList(List &L);

    /**
     * I.S. address lagu yang ingin dimasukkan ke antrean diberikan sebagai argumen
     *
     * F.S. address elemen antrean dengan argumen lagu dikembalikan
     *
     * @param l lagu yang ingin dimasukkan ke antrean
     * @return address elemen antrean beserta lagunya
     */
    address allocateElm(lagu::address l);

    /**
     * I.S. list yang ingin diperiksa diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan status apakah list kosong atau tidak sebagai boolean
     *
     * @param L list yang sedang dioperasikan
     * @return status apakah list kosong (true) atau tidak (false)
     */
    bool isEmpty(List L);

    /**
     * I.S. list yang ingin dioperasikan, address elemen antrean yang ingin ditambahkan, dan address elemen pada posisi
     * sebelum elemen yang ingin dioperasikan diberikan sebagai arguman
     *
     * F.S. address elemen antrean yang ingin ditambahkan disimpan pada list pada urutan setelah address elemen penanda
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dimasukkan
     * @param q elemen penanda pada posisi sebelum elemen yang ingin dimasukkan
     */
    void insertAfter(List &L, address p, address q);

    /**
     * I.S. list yang ingin dioperasikan dan address elemen antrean yang inign ditambahkan diberikan sebagai argumen
     *
     * F.S. address elemen antrean yang ingin ditambahkan disimpan sebagai elemen terakhir pada list
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dimasukkan
     */
    void insertLast(List &L, address p);

    /**
     * I.S. list yang sedang dioperasikan dan address elemen antrean yang ingin dihapus diberikan sebagai argumen
     *
     * F.S. address elemen antrean yang ingin dihapus telah hilang dari list antrean
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dihapus
     */
    void deleteElm(List &L, address &p);

    /**
     * I.S. list yang sedang dioperasikan diberikan sebagai argumen
     *
     * F.S. list kosong
     *
     * @param L list yang sedang dioperasikan
     */
    void deleteAll(List &L);

    /**
     * I.S. list yang sedang dioperasikan dan judul lagu diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen antrean yang berisikan judul lagu yang dicari
     *
     * @param L list yang sedang dioperasikan
     * @param j judul lagu yang sedang dicari dalam antrean
     * @return address elemen antrian yang dicari
     */
    address find(List L, string j);

    /**
     * I.S. list yang sedang dioperasikan
     *
     * F.S. list sudah dishuffle secara random
     *
     * @param L list yang sedang dioperasikan
     */
    void shuffle(List &L);
}

#endif //TUBES_STD_ANTRIANLAGU_H
