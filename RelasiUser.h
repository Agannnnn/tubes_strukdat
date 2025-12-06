//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_RELASIUSER_H
#define TUBES_STD_RELASIUSER_H

#include  <iostream>

#include "User.h"

using namespace std;

namespace relasi_user {
    typedef struct Elm *address;

    struct Elm {
        user::address user;
        playlist::address playlist;
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
     * I.S. address user dan address playlist diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen relasi yang berisi address user dan address playlist
     *
     * @param u address elemen user
     * @param p address elemen playlist
     * @return address elemen relasi user dengan playlist
     */
    address allocateElm(user::address u, playlist::address p);

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
     * I.S. list relasi yang sedang dioperasikan dan address user yang ingin ditampilkan playlist-nya diberikan sebagai argumen
     *
     * F.S. seluruh playlist yang terhubung dengan user tersebut ditampilkan
     *
     * @param L list relasi yang sedang dioperasikan
     * @param u address user yang playlist-nya ingin ditampilkan
     */
    void showPlaylists(List &L, user::address u);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address user yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang melibatkan user tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param u address user yang relasinya ingin dihapus
     */
    void deleteUser(List &L, user::address &u);

    /**
     * I.S. list relasi yang sedang dioperasikan dan address playlist yang ingin dihapus relasinya diberikan sebagai argumen
     *
     * F.S. seluruh relasi yang melibatkan playlist tersebut terhapus dari list relasi
     *
     * @param L list relasi yang sedang dioperasikan
     * @param p address playlist yang relasinya ingin dihapus
     */
    void deletePlaylist(List &L, playlist::address &p);
}

#endif //TUBES_STD_RELASIUSER_H
