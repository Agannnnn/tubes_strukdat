//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIPLAYLIST_H
#define TUBES_STD_RELASIPLAYLIST_H
#include "Playlist.h"

namespace relasi_playlist {
    typedef struct Elm *address;

    struct Elm {
        playlist::address playlist;
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
     * I.S. address playlist dan address lagu diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen relasi yang berisi address playlist dan address lagu
     *
     * @param p address elemen playlist
     * @param l address elemen lagu
     * @return address elemen relasi dengan playlist dan lagu
     */
    address allocateElm(playlist::address p, lagu::address l);

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
     * I.S. list relasi yang sedang dioperasikan dan address playlist yang ingin diambil lagunya diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan antrean lagu berisi seluruh lagu yang terhubung dengan playlist tersebut. Jika tidak
     * ada relasi, antrean kosong
     *
     * @param L list relasi yang sedang dioperasikan
     * @param p address playlist yang dicari
     * @return antrean lagu yang terkait dengan playlist p
     */
    antrean::List fetchLagu(List L, playlist::address p);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address lagu yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang berisi lagu tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param l address lagu yang relasinya ingin dihapus
     */
    void deleteLagu(List &L, lagu::address &l);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address playlist yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang berisi playlist tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param p address playlist yang relasinya ingin dihapus
     */
    void deletePlaylist(List &L, playlist::address &p);
}

#endif //TUBES_STD_RELASIPLAYLIST_H
