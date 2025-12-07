#ifndef TUBES_STD_ANTRIANLAGU_H
#define TUBES_STD_ANTRIANLAGU_H

#include "Lagu.h"

using namespace std;

namespace antrean {
    typedef struct Elm *addr;

    struct Infotype {
        lagu::addr lagu;
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
     * i.s. list diberikan sebagai argumen. List berisikan elemen-elemen termasuk elemen yang ingin dihapus
     *
     * f.s. list diperbarui dengan elmen yang ingin dihapus hilang dari list, dan elemen-elemen tetangganya digeser
     * @param l list yang dioperasikan
     * @param p address elemen yang ingin dihapus
     */
    void remove(List &l, addr &p);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. isi antrean ditampilkan sebagai output di layar pengguna
     * @param l list yang dioperasikan
     */
    void displayAntrean(List l);

    /**
     * i.s. list, judul lagu diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address elemen dengan judul yang sama atau nullptr jika tidak ada elemen dengan judul yang sama
     * @param list list yang dioperasikan
     * @param judulLagu judul lagu yang dicari
     * @return address elemen antrian yang berisikan lagu yang dicari
     */
    addr find(List list, string judulLagu);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. list diurutkan dengan urutan random
     * @param l list yang dioperasikan
     */
    void shuffle(List &l);

    /**
     * i.s. address elemen antrian diberikan sebagai argumen. Aplikasi belum atau sudah memutar musik sebelumnya
     *
     * f.s. aplikasi memutar musik yang terdapat pada address elemen
     * @param p address elemen antrian yang ingin diputar
     */
    void play(addr &p); // lagu bisa nullptr utk play dari depan

    /**
     * i.s. address elemen antrian diberikan sebagai argumen. Aplikasi sedang memutar musik
     *
     * f.s. aplikasi menghentikan musik yang terdapat pada address elemen
     * @param p address elemen antrian yang ingin dihentikan
     */
    void pause(addr p);
}

#endif //TUBES_STD_ANTRIANLAGU_H
