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

    void createGraph(Graph &G);

    void insertNode(Graph &G, address p);

    void deleteNode(Graph &G, address p, address &q);

    void connectNode(address &n1, address &n2);

    void disconnectNode(address &n1, address &n2);
}

#endif //TUBES_STD_LAGU_H
