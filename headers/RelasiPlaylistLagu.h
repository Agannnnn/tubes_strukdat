#ifndef TUBES_STD_RELASIPLAYLIST_H
#define TUBES_STD_RELASIPLAYLIST_H

#include <iostream>
#include "Lagu.h"
#include "RelasiPenyanyiLagu.h"

namespace playlist {
    typedef struct Elm *addr;
}

namespace antrean {
    struct List;
}

namespace relasi_playlist_lagu {
    typedef struct Elm *addr;

    struct Elm {
        playlist::addr playlist;
        lagu::addr lagu;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. list diinisialisasi: first dan last bernilai nullptr
     * @param list list yang dioperasikan
     */
    void createList(List &list);

    /**
     * i.s. playlist dan lagu diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari elmeen yang baru dibuat dengan relasi playlist-lagu
     * @param playlist address playlist dari elemen
     * @param lagu address lagu dari elemen
     * @return address elemen yang dibuat
     */
    addr allocateElm(playlist::addr playlist, lagu::addr lagu);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah list kosong atau tidak
     * @param list list yang dioperasikan
     * @return status apakah list kosong (true) atau tidak (false)
     */
    bool isEmpty(List list);

    /**
     * i.s. list diberikan sebagai arguman. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpan pada urutan paling belakang
     * @param list list yang dioperasikan
     * @param baru address elemen yang ingin ditambahkan
     */
    void insertLast(List &list, addr baru);

    /**
     * i.s. list diberikan sebagai argumen. List berisikan elemen-elemen termasuk elemen yang ingin dihapus
     *
     * f.s. list diperbarui dengan elmen yang ingin dihapus hilang dari list, dan elemen-elemen tetangganya digeser
     * @param list list yang dioperasikan
     * @param elm address elemen yang ingin dihapus
     */
    void remove(List &list, addr elm);

    /**
     * i.s. list dan playlist diberikan sebagai argumen. List berisikan elemen-elemen relasi termasuk yang terkait dengan playlist yang ingin dihapus
     *
     * f.s. list diperbarui dengan semua relasi yang terkait dengan playlist tertentu dihapus dari list
     * @param list list yang dioperasikan
     * @param playlist address playlist yang relasi-nya akan dihapus
     */
    void removePlaylist(List &list, playlist::addr playlist);

    /**
     * i.s. list dan lagu diberikan sebagai argumen. List berisikan elemen-elemen relasi termasuk yang terkait dengan lagu yang ingin dihapus
     *
     * f.s. list diperbarui dengan semua relasi yang terkait dengan lagu tertentu dihapus dari list
     * @param list list yang dioperasikan
     * @param lagu address lagu yang relasi-nya akan dihapus
     */
    void removeLagu(List &list, lagu::addr lagu);

    /**
     * i.s. list relasi dan playlist diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan list antrean yang berisi semua lagu yang terkait dengan playlist tertentu
     * @param list list relasi yang dioperasikan
     * @param playlist address playlist yang lagu-lagunya akan dikumpulkan
     * @return list antrean yang berisi lagu-lagu dari playlist
     */
    antrean::List listLagu(List list, playlist::addr playlist);
}

#endif //TUBES_STD_RELASIPLAYLIST_H
