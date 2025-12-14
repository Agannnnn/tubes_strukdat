#ifndef TUBES_STD_PENYANYI_H
#define TUBES_STD_PENYANYI_H

#include <iostream>

#include "ADT.h"

using namespace std;

namespace artists {
    /**
     * i.s. list terdefinisi tapi belum diinisialisasi.
     *
     * f.s. list terinisialisasi.
     * @param list list yang dioperasikan.
     */
    void createList(List &list);

    /**
     * i.s. info (data artis) terdefinisi.
     *
     * f.s. mengembalikan address dari elemen artis yang telah dibuat. 
     * @param info data artis yang akan disimpan pada elemen.
     * @return address elemen artis.
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
     * i.s. list dan elm terdefinisi. elm berada di dalam list. relations terdefinisi.
     *
     * f.s. elm dibuang dari list dan relasi-relasi yang melibatkan elm dihapus dari relations.
     * @param list list yang dioperasikan.
     * @param elm address elemen artis yang ingin dihapus.
     * @param relations relasi singer-music yang harus diperbarui.
     */
    void remove(List &list, addr &elm, singer_music::List &relations);

    /**
     * i.s. list terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output daftar artis yang ada pada list.
     * @param list list yang akan ditampilkan.
     */
    void display(List list);

    /**
     * i.s. list dan name terdefinisi.
     *
     * f.s. mengembalikan address artis dengan nama yang cocok. nullptr jika tidak ditemukan.
     * @param list list yang dioperasikan.
     * @param name nama artis yang dicari.
     * @return address artis jika ditemukan, nullptr jika tidak.
     */
    addr find(List list, string name);
}

#endif //TUBES_STD_PENYANYI_H
