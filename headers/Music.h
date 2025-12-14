#ifndef TUBES_STD_LAGU_H
#define TUBES_STD_LAGU_H

#include  <iostream>

#include "ADT.h"

using namespace std;

namespace music {
    /**
     * i.s. graph terdefinisi tapi belum diinisialisasi.
     *
     * f.s. graph terinisialisasi.
     * @param graph graph yang dioperasikan.
     */
    void createGraph(Graph &graph);

    /**
     * i.s. info (data musik) terdefinisi.
     *
     * f.s. mengembalikan address dari vertex musik yang telah dibuat. nullptr jika alokasi gagal.
     * @param info data musik yang akan disimpan pada vertex.
     * @return address vertex musik.
     */
    addr allocateVertex(Infotype info);

    /**
     * i.s. vertex terdefinisi.
     *
     * f.s. mengembalikan address dari edge yang telah dibuat. nullptr jika alokasi gagal.
     * @param vertex vertex tujuan dari edge.
     * @return address edge.
     */
    edge allocateEdge(addr vertex);

    /**
     * i.s. graph terdefinisi.
     *
     * f.s. mengembalikan status kosong graph. true jika graph tidak memiliki vertex.
     * @param graph graph yang dioperasikan.
     * @return status kosong graph.
     */
    bool isEmpty(Graph graph);

    /**
     * i.s. vertex dan category terdefinisi.
     *
     * f.s. mengembalikan edge pertama dari vertex sesuai kategori. nullptr jika tidak ada edge.
     * @param vertex vertex yang dioperasikan.
     * @param category kategori edge yang dicari.
     * @return address edge pertama.
     */
    edge getEdge(addr vertex, Category category);

    /**
     * i.s. vertex dan category terdefinisi.
     *
     * f.s. mengembalikan status kosong edge. true jika vertex tidak memiliki edge pada kategori tersebut.
     * @param vertex vertex yang dioperasikan.
     * @param category kategori edge yang diperiksa.
     * @return status kosong edge.
     */
    bool isEdgeEmpty(addr vertex, Category category);

    /**
     * i.s. fromVertex, toVertex, dan category terdefinisi.
     *
     * f.s. mengembalikan status koneksi antara dua vertex. true jika terdapat edge dari fromVertex ke toVertex
     * pada kategori tersebut.
     * @param fromVertex vertex asal.
     * @param toVertex vertex tujuan.
     * @param category kategori edge yang diperiksa.
     * @return status koneksi vertex.
     */
    bool isConnected(addr fromVertex, addr toVertex, Category category);

    /**
     * i.s. graph, newVertex, dan category terdefinisi.
     *
     * f.s. newVertex ditambahkan ke graph dan dihubungkan dengan vertex-vertex lain sesuai kategori.
     * @param graph graph yang dioperasikan.
     * @param newVertex address vertex yang ingin ditambah.
     * @param category kategori untuk menentukan koneksi.
     */
    void insertVertex(Graph &graph, addr &newVertex, Category category = MUSIC);

    /**
     * i.s. graph, vertex, dan category terdefinisi. vertex berada di dalam graph.
     *
     * f.s. vertex dibuang dari graph dan semua koneksi yang melibatkan vertex dihapus.
     * @param graph graph yang dioperasikan.
     * @param vertex address vertex yang ingin dihapus.
     * @param category kategori untuk menentukan koneksi yang dihapus.
     */
    void deleteVertex(Graph &graph, addr &vertex, Category category = MUSIC);

    /**
     * i.s. vertex dan category terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output daftar vertex yang terhubung dengan vertex pada kategori tersebut.
     * @param vertex vertex yang akan ditampilkan relasinya.
     * @param category kategori relasi yang ditampilkan.
     */
    void displayRelations(addr vertex, Category category);

    /**
     * i.s. fromVertex, toVertex, dan category terdefinisi.
     *
     * f.s. edge dua arah dibuat antara fromVertex dan toVertex pada kategori tersebut jika belum terhubung.
     * @param fromVertex vertex asal.
     * @param toVertex vertex tujuan.
     * @param category kategori edge yang dibuat.
     */
    void connectVertex(addr &fromVertex, addr &toVertex, Category category);

    /**
     * i.s. fromVertex, toVertex, dan category terdefinisi. kedua vertex terhubung pada kategori tersebut.
     *
     * f.s. edge dua arah antara fromVertex dan toVertex pada kategori tersebut dihapus.
     * @param fromVertex vertex asal.
     * @param toVertex vertex tujuan.
     * @param category kategori edge yang dihapus.
     */
    void disconnectVertex(addr &fromVertex, addr &toVertex, Category category);

    /**
     * i.s. graph terdefinisi.
     *
     * f.s. prosedur akan mengeluarkan output daftar musik yang ada pada graph dalam format tabel.
     * @param graph graph yang akan ditampilkan.
     */
    void display(Graph graph);

    /**
     * i.s. graph dan title terdefinisi.
     *
     * f.s. mengembalikan address vertex musik dengan judul yang cocok. nullptr jika tidak ditemukan.
     * @param graph graph yang dioperasikan.
     * @param title judul musik yang dicari.
     * @return address vertex musik jika ditemukan, nullptr jika tidak.
     */
    addr find(Graph graph, string title);

    /**
     * i.s. graph, vertex, dan category terdefinisi.
     *
     * f.s. mengembalikan list antrian musik yang sesuai dengan kriteria kategori dari vertex.
     * @param graph graph yang dioperasikan.
     * @param vertex vertex referensi untuk filter.
     * @param category kategori filter (GENRE/LANGUAGE/MUSIC).
     * @return list antrian musik yang sesuai kriteria.
     */
    queue::List listBy(Graph graph, addr vertex, Category category);
}

namespace container {
    typedef struct Elm *addr;

    struct Elm {
        music::addr song;
        addr next;
    };

    struct List {
        addr first;
    };

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
     * f.s. mengembalikan address dari elemen container yang telah dibuat. nullptr jika alokasi gagal.
     * @param music address musik yang akan disimpan pada elemen.
     * @return address elemen container.
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
     * i.s. list dan elm terdefinisi.
     *
     * f.s. elm ditambahkan sebagai node terakhir dalam list.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang ingin ditambah.
     */
    void insertLast(List &list, addr elm);

    /**
     * i.s. list terdefinisi dan tidak kosong.
     *
     * f.s. elemen pertama dibuang dari list dan dikembalikan melalui elm.
     * @param list list yang dioperasikan.
     * @param elm address elemen yang dibuang dari list.
     */
    void deleteFirst(List &list, addr &elm);

    /**
     * i.s. list dan elm terdefinisi.
     *
     * f.s. mengembalikan status keberadaan elm dalam list. true jika elm ada dalam list.
     * @param list list yang dioperasikan.
     * @param elm address musik yang dicari.
     * @return status keberadaan elm.
     */
    bool exists(List &list, music::addr elm);
}

#endif //TUBES_STD_LAGU_H
