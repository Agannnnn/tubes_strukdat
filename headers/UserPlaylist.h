#ifndef TUBES_STD_RELASIUSER_H
#define TUBES_STD_RELASIUSER_H

#include  "ADT.h"

using namespace std;

namespace user_playlist {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. user dan playlist terdefinisi.
     *
     * f.s. mengembalikan address dari elemen yang telah dibuat.
     * @param user pemilik playlist.
     * @param playlist playlist.
     * @return address elemen user_playlist.
     */
    addr allocateElm(user::addr user, playlist::addr playlist);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. status kosong list. true jika memiliki minimal satu node..
     * @param list list yang dioperasikan.
     * @return status kosong list.
     */
    bool isEmpty(List list);

    /**
     * i.s. list dan elm terdefinisi.
     *
     * f.s. elm ditambahkan sebagai node terakhir dalam list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin ditambah.
     */
    void insertLast(List &list, addr &elm);

    /**
     * i.s. list dan elm terdefinisi. elm berada di dalam list.
     *
     * f.s. list diperbarui dengan membuang elm dari list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin dihapus.
     */
    void remove(List &list, addr &elm);

    /**
     * i.s. list dan user terdefinisi.
     *
     * f.s. node-node dengan user yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param user address user yang ingin dihapus.
     */
    void removeUser(List &list, user::addr &user);

    /**
     * i.s. list dan playlist terdefinisi.
     *
     * f.s. node-node dengan playlist yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param playlist address playlist yang ingin dihapus.
     */
    void removePlaylist(List &list, playlist::addr &playlist);

    /**
     * i.s. list dan user terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output playlist-playlist yang dimiliki user.
     * @param list lsit yang dioperasikan.
     * @param user pemilik playlist.
     */
    void displayPlaylist(List list, user::addr user);

    /**
     * i.s. list dan playlist terdefinisi.
     *
     * f.s. mengembalikan address user dengan playlist yang diberikan. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param playlist playlist yang dimiliki user.
     * @return address user yang memiliki playlist.
     */
    user::addr findUser(List list, playlist::addr playlist);
}

#endif //TUBES_STD_RELASIUSER_H
