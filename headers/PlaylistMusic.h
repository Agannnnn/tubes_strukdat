#ifndef TUBES_STD_RELASIPLAYLIST_H
#define TUBES_STD_RELASIPLAYLIST_H

#include "ADT.h"

namespace playlist_music {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. playlist dan music terdefinisi.
     *
     * f.s. mengembalikan address dari elemen relasi playlist-music yang telah dibuat. nullptr jika alokasi gagal.
     * @param playlist address playlist yang akan disimpan pada elemen.
     * @param music address music yang akan disimpan pada elemen.
     * @return address elemen playlist_music.
     */
    addr allocateElm(playlist::addr playlist, music::addr music);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. mengembalikan status kosong list. true jika list tidak memiliki node.
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
     * f.s. elm dibuang dari list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin dihapus.
     */
    void remove(List &list, addr &elm);

    /**
     * i.s. list dan playlist terdefinisi.
     *
     * f.s. node-node dengan playlist yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param playlist address playlist yang ingin dihapus.
     */
    void removePlaylist(List &list, playlist::addr &playlist);

    /**
     * i.s. list dan music terdefinisi.
     *
     * f.s. node-node dengan music yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param music address music yang ingin dihapus.
     */
    void removeMusic(List &list, music::addr &music);

    /**
     * i.s. list dan playlist terdefinisi.
     *
     * f.s. mengembalikan list antrian musik yang ada dalam playlist yang diberikan.
     * @param list list yang dioperasikan.
     * @param playlist address playlist yang akan dicari musiknya.
     * @return list antrian musik yang ada dalam playlist.
     */
    queue::List listMusic(List list, playlist::addr playlist);
}

#endif //TUBES_STD_RELASIPLAYLIST_H
