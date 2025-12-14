#ifndef TUBES_STD_PLAYLIST_H
#define TUBES_STD_PLAYLIST_H

#include "ADT.h"

using namespace std;

namespace playlist {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. info (judul playlist) terdefinisi.
     *
     * f.s. mengembalikan address dari elemen playlist yang telah dibuat. nullptr jika alokasi gagal.
     * @param info judul playlist yang akan disimpan pada elemen.
     * @return address elemen playlist.
     */
    addr allocateElm(string info);

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
     * i.s. list, elm, user, dan userPlaylist terdefinisi.
     *
     * f.s. elm ditambahkan sebagai node terakhir dalam list dan relasi user-playlist dibuat dalam userPlaylist.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin ditambah.
     * @param user address user pemilik playlist.
     * @param userPlaylist relasi user-playlist yang akan diperbarui.
     */
    void insertLast(List &list, addr &elm, user::addr user, user_playlist::List &userPlaylist);

    /**
     * i.s. list dan elm terdefinisi. elm berada di dalam list. playlistMusicRelation dan userPlaylistRelation
     * terdefinisi.
     *
     * f.s. elm dibuang dari list dan relasi-relasi yang melibatkan elm dihapus dari playlistMusicRelation
     * dan userPlaylistRelation.
     * @param list list yang dioperasikan.
     * @param elm address elemen playlist yang ingin dihapus.
     * @param playlistMusicRelation relasi playlist-music yang harus diperbarui.
     * @param userPlaylistRelation relasi user-playlist yang harus diperbarui.
     */
    void remove(List &list, addr &elm, playlist_music::List &playlistMusicRelation,
                user_playlist::List &userPlaylistRelation);

    /**
     * i.s. list dan title terdefinisi.
     *
     * f.s. mengembalikan address playlist dengan judul yang cocok. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param title judul playlist yang dicari.
     * @return address playlist jika ditemukan, nullptr jika tidak.
     */
    addr find(List list, string title);
}

#endif //TUBES_STD_PLAYLIST_H
