#ifndef TUBES_STD_PENYANYI_H
#define TUBES_STD_PENYANYI_H

#include <iostream>

#include "RelasiPenyanyiLagu.h"

using namespace std;

namespace penyanyi {
    typedef struct Elm *addr;

    struct Infotype {
        string nama;
        int tahunDebut;
    };

    struct Elm {
        Infotype info;
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
     * @param l list yang dioperasikan
     */
    void createList(List &l);

    /**
     * i.s. nilai diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari elmeen yang baru dibuat
     * @param i nilai dari elemen
     * @return address elemen yang dibuat
     */
    addr allocateElm(Infotype i);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah list kosong atau tidak
     * @param l list yang dioperasikan
     * @return status apakah list kosong (true) atau tidak (false)
     */
    bool isEmpty(List l);

    /**
     * i.s. list, elemen baru, dan elemen penanda diberikan sebagai argumen. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpen setelah elemen penanda
     * @param l list yang dioperasikan
     * @param p address elemen yang ingin ditambahkan
     * @param q address elemen penanda
     */
    void insertAfter(List &l, addr p, addr q);

    /**
     * i.s. list diberikan sebagai arguman. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpan pada urutan paling belakang
     * @param l list yang dioperasikan
     * @param p address elemen yang ingin ditambahkan
     */
    void insertLast(List &l, addr p);

    /**
     * i.s. list dan relasi penyanyi-lagu diberikan sebagai argumen. List berisikan elemen-elemen termasuk elemen yang ingin dihapus
     *
     * f.s. list diperbarui dengan elmen yang ingin dihapus hilang dari list, dan elemen-elemen tetangganya digeser. Relasi penyanyi-lagu yang terkait juga dihapus
     * @param l list yang dioperasikan
     * @param p address elemen yang ingin dihapus
     * @param rpl relasi penyanyi-lagu yang akan diperbarui
     */
    void remove(List &l, addr &p, relasi_penyanyi_lagu::List &rpl);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. isi daftar penyanyi ditampilkan sebagai output di layar pengguna
     * @param l list yang dioperasikan
     */
    void displayPenyanyi(List l);
}

#endif //TUBES_STD_PENYANYI_H
