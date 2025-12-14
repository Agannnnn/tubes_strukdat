#ifndef TUBES_STD_ANTRIANLAGU_H
#define TUBES_STD_ANTRIANLAGU_H

#include "ADT.h"

#include <SFML/Audio.hpp>

#include <bits/std_thread.h>

using namespace std;

namespace queue {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. music terdefinisi.
     *
     * f.s. mengembalikan address dari elemen antrian yang telah dibuat. nullptr jika alokasi gagal.
     * @param music address musik yang akan disimpan pada elemen.
     * @return address elemen antrian.
     */
    addr allocateElm(music::addr music);

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
    void insertAfter(List &list, addr newElm, addr prevElm);

    /**
     * i.s. list dan newElm terdefinisi.
     *
     * f.s. newElm ditambahkan sebagai node terakhir dalam list.
     * @param list list yang dioperasikan.
     * @param newElm address elemen yang ingin ditambah.
     */
    void insertLast(List &list, addr newElm);

    /**
     * i.s. list dan elm terdefinisi. elm berada di dalam list.
     *
     * f.s. elm dibuang dari list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin dihapus.
     */
    void remove(List &list, addr &elm);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output daftar musik yang ada pada antrian.
     * @param list list yang akan ditampilkan.
     */
    void display(List list);

    /**
     * i.s. list dan title terdefinisi.
     *
     * f.s. mengembalikan address musik dengan judul yang cocok. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param title judul musik yang dicari.
     * @return address musik jika ditemukan, nullptr jika tidak.
     */
    addr find(List list, string title);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. urutan elemen dalam list diacak. semua node tetap valid dan list tetap dapat digunakan.
     * @param list list yang akan diacak.
     */
    void shuffle(List &list);

    /**
     * i.s. list1 dan list2 terdefinisi.
     *
     * f.s. semua node dari list2 ditambahkan ke akhir list1. list2 tetap tidak berubah.
     * @param list1 list tujuan yang akan ditambahkan.
     * @param list2 list sumber yang elemennya akan digabung.
     */
    void joinQueue(List &list1, List list2);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. semua node dihapus dan list menjadi kosong.
     * @param list list yang akan dikosongkan.
     */
    void clear(List &list);
}

#endif //TUBES_STD_ANTRIANLAGU_H
