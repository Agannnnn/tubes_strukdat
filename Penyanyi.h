//
// Created by ahmad on 06/12/2025.
//

#ifndef TUBES_STD_PENYANYI_H
#define TUBES_STD_PENYANYI_H

#include <iostream>

using namespace std;

namespace penyanyi {
    typedef struct Elm *address;

    struct Elm {
        string namaPenyanyi;
        int tahunDebit;
    };

    struct List {
        address first;
        address last;
    };

    /**
     * I.S. list yang sedang dioperasikan diberikan sebagai argumen
     *
     * F.S. atribut first dan last pada list bernilai nullptr
     *
     * @param L list yang sedang dioperasikan
     */
    void createList(List &L);

    /**
     * I.S. nama penyanyi dan tahun debut diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen penyanyi dengan atribut sesuai argumen
     *
     * @param n nama penyanyi
     * @param t tahun debut penyanyi
     * @return address elemen penyanyi dengan atribut sesuai argumen
     */
    address allocateElm(string n, int t);

    /**
     * I.S. list yang ingin dioperasikan dan address elemen penyanyi yang ingin ditambahkan diberikan sebagai argumen
     *
     * F.S. address elemen penyanyi yang ingin ditambahkan disimpan sebagai elemen terakhir pada list
     *
     * @param L list yang sedang dioperasikan
     * @param p elemen yang ingin dimasukkan
     */
    void insertLast(List &L, address p);

    /**
     * I.S. list yang sedang dioperasikan dan address elemen penyanyi yang ingin dihapus diberikan sebagai argumen
     *
     * F.S. elemen penyanyi yang ingin dihapus telah hilang dari list
     *
     * @param L list yang sedang dioperasikan
     * @param p address elemen yang ingin dihapus
     */
    void deleteElm(List &L, address &p);

    /**
     * I.S. list yang sedang dioperasikan dan nama penyanyi yang ingin dicari diberikan sebagai argumen
     *
     * F.S. fungsi mengembalikan address elemen penyanyi dengan nama sesuai argumen. Jika tidak ditemukan, fungsi
     * mengembalikan nullptr.
     *
     * @param L list yang sedang dioperasikan
     * @param n nama penyanyi yang dicari
     * @return address elemen penyanyi yang dicari atau nullptr jika tidak ditemukan
     */
    address findElm(List L, string n);
}

#endif //TUBES_STD_PENYANYI_H
