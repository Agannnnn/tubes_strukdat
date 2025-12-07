#ifndef TUBES_STD_RELASIUSER_H
#define TUBES_STD_RELASIUSER_H

#include  <iostream>

#include "User.h"
#include "Playlist.h"

using namespace std;

namespace relasi_user_playlist {
    typedef struct Elm *addr;

    struct Elm {
        user::addr user;
        playlist::addr playlist;
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
     * i.s. user dan playlist diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari elmeen yang baru dibuat dengan relasi user-playlist
     * @param user address user dari elemen
     * @param playlist address playlist dari elemen
     * @return address elemen yang dibuat
     */
    addr allocateElm(user::addr user, playlist::addr playlist);

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
     * i.s. list dan user diberikan sebagai argumen. List berisikan elemen-elemen relasi termasuk yang terkait dengan user yang ingin dihapus
     *
     * f.s. list diperbarui dengan semua relasi yang terkait dengan user tertentu dihapus dari list
     * @param list list yang dioperasikan
     * @param user address user yang relasi-nya akan dihapus
     */
    void removeUser(List &list, user::addr user);

    /**
     * i.s. list dan playlist diberikan sebagai argumen. List berisikan elemen-elemen relasi termasuk yang terkait dengan playlist yang ingin dihapus
     *
     * f.s. list diperbarui dengan semua relasi yang terkait dengan playlist tertentu dihapus dari list
     * @param list list yang dioperasikan
     * @param playlist address playlist yang relasi-nya akan dihapus
     */
    void removePlaylist(List &list, playlist::addr playlist);

    /**
     * i.s. list relasi dan user diberikan sebagai argumen
     *
     * f.s. isi daftar playlist yang dimiliki user ditampilkan sebagai output di layar pengguna
     * @param list list relasi yang dioperasikan
     * @param user address user yang playlist-nya akan ditampilkan
     */
    void displayPlaylist(List list, user::addr user);
}

#endif //TUBES_STD_RELASIUSER_H
