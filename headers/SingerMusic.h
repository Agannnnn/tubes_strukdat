#ifndef TUBES_STD_RELASIPENYANYI_H
#define TUBES_STD_RELASIPENYANYI_H

#include "ADT.h"

namespace singer_music {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. music dan singer terdefinisi.
     *
     * f.s. mengembalikan address dari elemen relasi singer-music yang telah dibuat. nullptr jika alokasi gagal.
     * @param music address music yang akan disimpan pada elemen.
     * @param singer address singer yang akan disimpan pada elemen.
     * @return address elemen singer_music.
     */
    addr allocateElm(music::addr music, artists::addr singer);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. mengembalikan status kosong list. true jika list tidak memiliki node.
     * @param list list yang dioperasikan.
     * @return status kosong list.
     */
    bool isEmpty(List list);

    /**
     * i.s. list dan newElm terdefinisi.
     *
     * f.s. newElm ditambahkan sebagai node terakhir dalam list.
     * @param list list yang dioperasikan.
     * @param newElm address elemen yang ingin ditambah.
     */
    void insertLast(List &list, addr &newElm);

    /**
     * i.s. list dan elm terdefinisi. elm berada di dalam list.
     *
     * f.s. elm dibuang dari list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin dihapus.
     */
    void remove(List &list, addr &elm);

    /**
     * i.s. list dan music terdefinisi.
     *
     * f.s. node-node dengan music yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param music address music yang ingin dihapus.
     */
    void removeMusic(List &list, music::addr music);

    /**
     * i.s. list dan singer terdefinisi.
     *
     * f.s. node-node dengan singer yang cocok akan dihapus dari list.
     * @param list list yang dioperasikan.
     * @param singer address singer yang ingin dihapus.
     */
    void removeSinger(List &list, artists::addr singer);

    /**
     * i.s. list, singer, dan music terdefinisi.
     *
     * f.s. mengembalikan address elemen relasi yang cocok dengan singer dan music. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param singer address singer yang dicari.
     * @param music address music yang dicari.
     * @return address elemen relasi jika ditemukan, nullptr jika tidak.
     */
    addr find(List list, artists::addr singer, music::addr music);

    /**
     * i.s. list dan music terdefinisi.
     *
     * f.s. mengembalikan address singer yang memiliki music tersebut. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param music address music yang dicari singernya.
     * @return address singer jika ditemukan, nullptr jika tidak.
     */
    artists::addr findSinger(List list, music::addr music);

    /**
     * i.s. list dan singer terdefinisi.
     *
     * f.s. mengembalikan list antrian musik yang dimiliki oleh singer yang diberikan.
     * @param list list yang dioperasikan.
     * @param singer address singer yang akan dicari musiknya.
     * @return list antrian musik yang dimiliki singer.
     */
    queue::List listMusic(List list, artists::addr singer);
}

#endif //TUBES_STD_RELASIPENYANYI_H
