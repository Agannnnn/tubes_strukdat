//
// Created by ahmad on 18/11/2025.
//

#ifndef TUBES_STD_LAGU_H
#define TUBES_STD_LAGU_H

#include  <iostream>

using namespace std;

namespace lagu {
    typedef struct Node *address;
    typedef struct Edge *edge;

    struct Node {
        string judul;
        string namaPenyanyi;
        string namaAlbum;
        string pathFile;
        string genre;
        string bahasa;
        edge nextGenre;
        edge nextBahasa;
    };

    struct Edge {
        address node;
        edge next;
    };

    struct Graph {
        address first;
    };

    /**
     * I.S. graph yang ingin dioperasikan diberikan sebagai argumen
     *
     * F.S. atribut first pada graph bernilai nullptr
     *
     * @param G graph yang sedang dioperasikan
     */
    void createGraph(Graph &G);

    /**
     * I.S. graph yang sedang dioperasikan dan address node diberikan sebagai argumen
     *
     * F.S. address node yang ingin ditambahkan disimpan dalam graph pada urutan terakhir
     *
     * @param G graph yang sedang dioperasikan
     * @param p address node yang ingin dimasukkan ke dalam graph
     */
    void insertNode(Graph &G, address p);

    /**
     * I.S. graph yang sedang dioperasikan dan address node diberikan sebagai argumen
     *
     * F.S. node yang ingin dihapus sudah hilang dari graph
     *
     * @param G graph yang sedang dioperasikan
     * @param p address node yang ingin dihapus dari graph
     */
    void deleteNode(Graph &G, address &p);

    /**
     * I.S. address node 1 dan 2 yang ingin dihubungkan melalui edge berdasarkan genre
     *
     * F.S. edge ditambahkan pada atribut genre
     *
     * @param n1 address node 1
     * @param n2 address node 2
     */
    void connectNodeGenre(address &n1, address &n2);

    /**
     * I.S. address node 1 dan 2 yang ingin dihubungkan melalui edge berdasarkan bahasa
     *
     * F.S. edge ditambahkan pada atribut bahasa
     *
     * @param n1 address node 1
     * @param n2 address node 2
     */
    void connectNodeBahasa(address &n1, address &n2);

    /**
     * I.S. address node 1 dan 2 yang ingin dipisahkan berdasarkan genre
     *
     * F.S. edge dihapus pada atribut genre
     *
     * @param n1 address node 1
     * @param n2 address node 2
     */
    void disconnectNodeGenre(address &n1, address &n2);

    /**
     * I.S. address node 1 dan 2 yang ingin dipisahkan berdasarkan bahasa
     *
     * F.S. edge dihapus pada atribut bahasa
     *
     * @param n1 address node 1
     * @param n2 address node 2
     */
    void disconnectNodeBahasa(address &n1, address &n2);
}

#endif //TUBES_STD_LAGU_H
