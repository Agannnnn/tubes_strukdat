#ifndef TUBES_STD_LAGU_H
#define TUBES_STD_LAGU_H

#include  <iostream>

using namespace std;

namespace lagu {
    typedef struct Vertex *addr;

    typedef struct Edge *edge;

    struct Edge {
        addr node;
        edge next;
    };

    struct Infotype {
        string judul;
        string penyanyi;
        string album;
        int durasi;
        string genre;
        string bahasa;
        edge nextGenre;
        edge nextBahasa;
    };

    struct Vertex {
        Infotype info;
        edge nextLagu;
    };

    struct Graph {
        addr first;
    };

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
     * f.s. fungsi mengembalikan address dari node yang baru dibuat
     * @param i nilai dari node
     * @return address node yang dibuat
     */
    addr allocateNode(Infotype i);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari edge yang baru dibuat
     * @param n address node yang akan dihubungkan
     * @return address edge yang dibuat
     */
    edge allocateEdge(addr n);

    /**
     * i.s. graph diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah graph kosong atau tidak
     * @param g graph yang dioperasikan
     * @return status apakah graph kosong (true) atau tidak (false)
     */
    bool isEmpty(Graph g);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah edge kosong atau tidak
     * @param n node yang dioperasikan
     * @return status apakah edge kosong (true) atau tidak (false)
     */
    bool isEdgeEmpty(addr n);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah edge genre kosong atau tidak
     * @param n node yang dioperasikan
     * @return status apakah edge genre kosong (true) atau tidak (false)
     */
    bool isEdgeEmptyGenre(addr n);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah edge bahasa kosong atau tidak
     * @param n node yang dioperasikan
     * @return status apakah edge bahasa kosong (true) atau tidak (false)
     */
    bool isEdgeEmptyBahasa(addr n);

    /**
     * i.s. dua node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah kedua node terhubung atau tidak
     * @param n1 node pertama
     * @param n2 node kedua
     * @return status apakah kedua node terhubung (true) atau tidak (false)
     */
    bool isConnected(addr n1, addr n2);

    /**
     * i.s. dua node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah kedua node terhubung melalui genre atau tidak
     * @param n1 node pertama
     * @param n2 node kedua
     * @return status apakah kedua node terhubung melalui genre (true) atau tidak (false)
     */
    bool isConnectedGenre(addr n1, addr n2);

    /**
     * i.s. dua node diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah kedua node terhubung melalui bahasa atau tidak
     * @param n1 node pertama
     * @param n2 node kedua
     * @return status apakah kedua node terhubung melalui bahasa (true) atau tidak (false)
     */
    bool isConnectedBahasa(addr n1, addr n2);

    /**
     * i.s. graph dan node diberikan sebagai argumen. Graph berisikan node-node tanpa node baru
     *
     * f.s. graph diperbarui dengan node yang ingin ditambahkan disimpan dalam graph
     * @param g graph yang dioperasikan
     * @param n address node yang ingin ditambahkan
     */
    void insertNode(Graph &g, addr n);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. edge dari node ditampilkan sebagai output di layar pengguna
     * @param n node yang dioperasikan
     */
    void displayEdge(addr n);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node belum terhubung
     *
     * f.s. kedua node dihubungkan dengan edge
     * @param n1 node pertama yang akan dihubungkan
     * @param n2 node kedua yang akan dihubungkan
     */
    void connectNode(addr &n1, addr &n2);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node sudah terhubung
     *
     * f.s. edge yang menghubungkan kedua node dihapus
     * @param n1 node pertama yang akan diputus hubungannya
     * @param n2 node kedua yang akan diputus hubungannya
     */
    void disconnectNode(addr &n1, addr &n2);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. edge genre dari node ditampilkan sebagai output di layar pengguna
     * @param n node yang dioperasikan
     */
    void displayEdgeGenre(addr n);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node belum terhubung melalui genre
     *
     * f.s. kedua node dihubungkan dengan edge genre
     * @param n1 node pertama yang akan dihubungkan melalui genre
     * @param n2 node kedua yang akan dihubungkan melalui genre
     */
    void connectNodeGenre(addr &n1, addr &n2);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node sudah terhubung melalui genre
     *
     * f.s. edge genre yang menghubungkan kedua node dihapus
     * @param n1 node pertama yang akan diputus hubungan genrenya
     * @param n2 node kedua yang akan diputus hubungan genrenya
     */
    void disconnectNodeGenre(addr &n1, addr &n2);

    /**
     * i.s. node diberikan sebagai argumen
     *
     * f.s. edge bahasa dari node ditampilkan sebagai output di layar pengguna
     * @param n node yang dioperasikan
     */
    void displayEdgeBahasa(addr n);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node belum terhubung melalui bahasa
     *
     * f.s. kedua node dihubungkan dengan edge bahasa
     * @param n1 node pertama yang akan dihubungkan melalui bahasa
     * @param n2 node kedua yang akan dihubungkan melalui bahasa
     */
    void connectNodeBahasa(addr &n1, addr &n2);

    /**
     * i.s. dua node diberikan sebagai argumen. Kedua node sudah terhubung melalui bahasa
     *
     * f.s. edge bahasa yang menghubungkan kedua node dihapus
     * @param n1 node pertama yang akan diputus hubungan bahasanya
     * @param n2 node kedua yang akan diputus hubungan bahasanya
     */
    void disconnectNodeBahasa(addr &n1, addr &n2);

    /**
     * i.s. graph diberikan sebagai argumen
     *
     * f.s. isi daftar lagu ditampilkan sebagai output di layar pengguna
     * @param g graph yang dioperasikan
     */
    void displayLagu(Graph g);
}

namespace list_traversal {
    typedef struct Elm *addr;

    struct Elm {
        lagu::addr info;
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
    addr allocateElm(lagu::addr i);

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
     * i.s. list dan node lagu diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah node lagu ada dalam list atau tidak
     * @param l list yang dioperasikan
     * @param p node lagu yang dicari
     * @return status apakah node lagu ada dalam list (true) atau tidak (false)
     */
    bool exists(List &l, lagu::addr p);
}

#endif //TUBES_STD_LAGU_H