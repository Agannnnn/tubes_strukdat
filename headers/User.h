#ifndef TUBES_STD_USER_H
#define TUBES_STD_USER_H

#include <iostream>
#include "ADT.h"

using namespace std;

namespace user {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. info (data user) terdefinisi.
     *
     * f.s. mengembalikan address dari elemen user yang telah dibuat. nullptr jika alokasi gagal.
     * @param info data user yang akan disimpan pada elemen.
     * @return address elemen user.
     */
    addr allocateElm(Infotype info);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. mengembalikan status kosong list. true jika list tidak memiliki node.
     * @param list list yang dioperasikan.
     * @return status kosong list.
     */
    bool isEmpty(List list);

    /**
     * i.s. list, newElm, dan prevElm terdefinisi. prevElm berada di dalam list.
     *
     * f.s. newElm disisipkan setelah prevElm dalam list.
     * @param list list yang dioperasikan.
     * @param newElm address elemen yang ingin disisipkan.
     * @param prevElm address elemen sebelumnya tempat penyisipan.
     */
    void insertAfter(List &list, addr &newElm, addr &prevElm);

    /**
     * i.s. list dan newElm terdefinisi.
     *
     * f.s. newElm ditambahkan sebagai node terakhir dalam list.
     * @param list list yang dioperasikan.
     * @param newElm address elemen yang ingin ditambah.
     */
    void insertLast(List &list, addr &newElm);

    /**
     * i.s. list dan elm terdefinisi. elm berada di dalam list. userPlaylistRelation terdefinisi.
     *
     * f.s. elm dibuang dari list dan relasi-relasi yang melibatkan elm dihapus dari userPlaylistRelation.
     * @param list list yang dioperasikan.
     * @param elm address elemen user yang ingin dihapus.
     * @param userPlaylistRelation relasi user-playlist yang harus diperbarui.
     */
    void remove(List &list, addr &elm, user_playlist::List &userPlaylistRelation);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output daftar user yang ada pada list.
     * @param list list yang akan ditampilkan.
     */
    void list(List &list);

    /**
     * i.s. list, username, dan password terdefinisi.
     *
     * f.s. mengembalikan address user yang cocok dengan username dan password. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param username username user yang dicari.
     * @param password kata sandi yang dicocokkan.
     * @return address user jika ditemukan, nullptr jika tidak.
     */
    addr find(List list, string username, string password);

    /**
     * i.s. list dan username terdefinisi.
     *
     * f.s. mengembalikan address user dengan username yang diberikan. nullptr jika tidak ditemukan
     * @param list list yang dioperasikan.
     * @param username username user yang dicari.
     * @return address user jika ditemukan, nullptr jika tidak.
     */
    addr findAdmin(List list, string username);
}

#endif //TUBES_STD_USER_H
