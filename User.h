//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_USER_H
#define TUBES_STD_USER_H

#include <iostream>
#include "Playlist.h"

using namespace std;

namespace user {
    typedef struct User *address;

    struct Elm {
        string username;
        string password;
        string namaPengguna;
    };

    struct List {
        address next;
        address prev;
    };

    /**
     * I.S. list yang sedang dioperasikan diberikan sebagai argumen
     *
     * F.S. atribut next dan prev pada list bernilai nullptr
     *
     * @param L list yang sedang dioperasikan
     */
    void createList(List &L);

    /**
     * I.S. username, password, dan nama pengguna diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen user dengan atribut sesuai argumen
     *
     * @param username username dari user
     * @param password password dari user
     * @param namaPengguna nama pengguna dari user
     * @return address elemen user dengan atribut sesuai argumen
     */
    address allocateElm(string username, string password, string namaPengguna);

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
     * I.S. list yang ingin dioperasikan dan address elemen user yang ingin ditambahkan diberikan sebagai argumen
     *
     * F.S. address elemen user yang ingin ditambahkan disimpan pada urutan terakhir pada list
     *
     * @param L list yang sedang dioperasikan
     * @param p address elemen user yang ingin ditambahkan
     */
    void insertLast(List &L, address p);

    /**
     * I.S. list yang sedang dioperasikan dan address elemen user yang ingin dihapus diberikan sebagai argumen
     *
     * F.S. elemen user yang ingin dihapus telah hilang dari list
     *
     * @param L list yang sedang dioperasikan
     * @param p address elemen yang ingin dihapus
     */
    void deleteElm(List &L, address &p);

    /**
     * I.S. list yang sedang dioperasikan dan username user yang ingin dicari diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen user dengan username sesuai argumen. Jika tidak ditemukan, fungsi mengembalikan nullptr.
     *
     * @param L list yang sedang dioperasikan
     * @param username username dari user yang ingin dicari
     * @return address elemen user dengan username sesuai argumen atau nullptr jika tidak ditemukan
     */
    address find(List L, string username);

    /**
     * I.S. list yang sedang dioperasikan, username, dan password diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address user jika kombinasi username dan password cocok dengan sebuah elemen pada list; jika tidak cocok, fungsi mengembalikan nullptr
     *
     * @param L list yang sedang dioperasikan
     * @param username username untuk login
     * @param password password untuk login
     * @return address elemen user yang berhasil login
     */
    address login(List L, string username, string password);
}

#endif //TUBES_STD_USER_H
