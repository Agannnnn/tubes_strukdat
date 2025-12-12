#ifndef TUBES_STD_LAGU_H
#define TUBES_STD_LAGU_H

#include  <iostream>

#include "ADT.h"

using namespace std;

namespace song {
    const int SONG = 0;
    const int GENRE = 1;
    const int LANGUAGE = 2;

    /**
     * i.s. graph diberikan sebagai argumen
     *
     * f.s. graph diinisialisasi: first bernilai nullptr
     * @param g graph yang dioperasikan
     */
    void createGraph(Graph &g);

    /**
     * i.s. nilai diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari vertex yang baru dibuat
     * @param v nilai dari vertex
     * @return address vertex yang dibuat
     */
    addr allocateVertex(Infotype v);

    /**
     * i.s. vertex diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari edge yang baru dibuat
     * @param v address vertex yang akan dihubungkan
     * @return address edge yang dibuat
     */
    edge allocateEdge(addr v);

    /**
     * i.s. graph diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah graph kosong atau tidak
     * @param g graph yang dioperasikan
     * @return status apakah graph kosong (true) atau tidak (false)
     */
    bool isEmpty(Graph g);

    /**
     * i.s. vertex dan kategori diberikan sebagai argumen
     *
     * f.s. address edge sesuai kategori pertama yang ada dalam vertex
     * @param v vertex yang dioperasikan
     * @param c kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     * @return edge pertama dari vertex sesuai dengan kategori yang diberikan
     */
    edge getEdge(addr v, int c);

    /**
     * i.s. vertex diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah edge kosong atau tidak berdasarkan
     * kategori yang diberikan
     * @param v vertex yang dioperasikan
     * @param c  kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     * @return status apakah edge kosong (true) atau tidak (false)
     */
    bool isEdgeEmpty(addr v, int c);

    /**
     * i.s. dua vertex diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah kedua vertex terhubung atau tidak berdasarkan
     * kategori yang diberikan
     * @param v1 vertex pertama
     * @param v2 vertex kedua
     * @param c  kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     * @return status apakah kedua vertex terhubung (true) atau tidak (false)
     */
    bool isConnected(addr v1, addr v2, int c);

    /**
     * i.s. graph dan vertex diberikan sebagai argumen. Graph berisikan vertex-vertex tanpa vertex baru
     *
     * f.s. graph diperbarui dengan vertex yang ingin ditambahkan disimpan dalam graph
     * @param g graph yang dioperasikan
     * @param v address vertex yang ingin ditambahkan
     */
    void insertVertex(Graph &g, addr v);

    /**
     * i.s. vertex diberikan sebagai argumen
     *
     * f.s. edge dari vertex ditampilkan sebagai output di layar pengguna
     * @param v vertex yang dioperasikan
     * @param c  kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     */
    void displayConnections(addr v, int c);

    /**
     * i.s. dua vertex diberikan sebagai argumen
     *
     * f.s. kedua vertex terhubung dengan masin-masing dengan sebuah edge
     * @param v1 vertex pertama yang akan dihubungkan
     * @param v2 vertex kedua yang akan dihubungkan
     * @param c  kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     */
    void connectVertex(addr &v1, addr &v2, int c);

    /**
     * i.s. dua vertex diberikan sebagai argumen. Kedua vertex sudah terhubung
     *
     * f.s. edge yang menghubungkan kedua vertex dihapus
     * @param v1 vertex pertama yang akan diputus hubungannya
     * @param v2 vertex kedua yang akan diputus hubungannya
     * @param c  kategori edge yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     */
    void disconnectVertex(addr &v1, addr &v2, int c);

    /**
     * i.s. graph diberikan sebagai argumen
     *
     * f.s. isi daftar lagu ditampilkan sebagai output di layar pengguna
     * @param g graph yang dioperasikan
     */
    void display(Graph g);

    /**
     * i.s. graf dan judul lagu yang dicari diberikan sebagai argumen.
     *
     * f.s. mengembalikan address vertex lagu yang dicari atau nullptr jika tidak ditemukan
     * @param g graf yang dioperasikan
     * @param t judul lagu yang dicari
     * @return address vertex lagu, nullptr jika tidak ditemukan
     */
    addr find(Graph g, string t);

    /**
     * i.s. vertex referensi dan kategori diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan list antrean yang berisi lagu-lagu yang berelasi sesuai kategori
     * @param v address vertex referensi
     * @param c kateogori relasi yang ingin dioperasikan: song::SONG, song::GENRE, atau song::LANGUAGE
     * @return list lagu yang berelasi dengan vertex v
     */
    antrean::List listBy(addr v, int c);
}

namespace container {
    typedef struct Elm *addr;

    struct Elm {
        song::addr song;
        addr next;
    };

    struct List {
        addr first;
    };

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. list diinisialisasi: first bernilai nullptr
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
    addr allocateElm(song::addr i);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah list kosong atau tidak
     * @param l list yang dioperasikan
     * @return status apakah list kosong (true) atau tidak (false)
     */
    bool isEmpty(List l);

    /**
     * i.s. list diberikan sebagai arguman. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpan pada urutan paling belakang
     * @param l list yang dioperasikan
     * @param p address elemen yang ingin ditambahkan
     */
    void insertLast(List &l, addr p);

    /**
     * i.s. list diberikan sebagai argumen. List berisikan elemen-elemen termasuk elemen yang ingin dihapus di posisi pertama
     *
     * f.s. list diperbarui dengan elemen pertama dihapus dan elemen-elemen tetangganya digeser
     * @param l list yang dioperasikan
     * @param p address elemen yang dihapus
     */
    void deleteFirst(List &l, addr &p);

    /**
     * i.s. list dan vertex lagu diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah vertex lagu ada dalam list atau tidak
     * @param l list yang dioperasikan
     * @param p vertex lagu yang dicari
     * @return status apakah vertex lagu ada dalam list (true) atau tidak (false)
     */
    bool exists(List &l, song::addr p);
}

#endif //TUBES_STD_LAGU_H
