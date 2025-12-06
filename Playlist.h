//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_PLAYLIST_H
#define TUBES_STD_PLAYLIST_H

#include "Antrean.h"

using namespace std;

namespace playlist {
    typedef struct Elm *address;

    struct Elm {
        string namaPlaylist;
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
     * I.S. nama playlist diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen playlist baru dengan nama sesuai argumen
     *
     * @param n nama playlist yang ingin dibuat
     * @return address elemen playlist dengan nama sesuai argumen
     */
    address allocateElm(string n);

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
     * I.S. list yang ingin dioperasikan, address elemen playlist yang ingin ditambahkan, dan address elemen penanda
     *
     * F.S. address elemen playlist yang ingin ditambahkan disimpan pada list tepat setelah elemen penanda (q)
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dimasukkan
     * @param q elemen penanda pada posisi sebelum elemen yang ingin dimasukkan
     */
    void insertAfter(List &L, address p, address q);

    /**
     * I.S. list yang ingin dioperasikan dan address elemen playlist yang ingin ditambahkan diberikan sebagai argumen
     *
     * F.S. address elemen playlist yang ingin ditambahkan disimpan sebagai elemen terakhir pada list
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dimasukkan
     */
    void insertLast(List &L, address p);

    /**
     * I.S. list yang sedang dioperasikan dan address elemen playlist yang ingin dihapus diberikan sebagai argumen
     *
     * F.S. elemen playlist yang ingin dihapus telah hilang dari list
     *
     * @param L list yang sedang dioperasikan
     * @param p address elemen yang ingin dihapus
     */
    void deleteElm(List &L, address &p);
}

#endif //TUBES_STD_PLAYLIST_H
