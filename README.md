# Aplikasi Pemutar Musik Sederhana

## 1. Fitur:

- menyimpan lagu,
- mengakses lagu (putar),
- menghapus lagu,
- memperbarui lagu,
- membuat playlist,
- menghapus playlist,
- memperbarui playlist (tambah & hapus lagu),
- membuat antrian lagu,
- menghapus antrian lagu,
- memperbarui antrian lagu (tambah & hapus lagu),
- memiliki dua jenis pengguna (admin & user),
- memutar lagu (kalau sempat).

## 2. Spesifikasi:

- Doubly Linked List (DLL):

```c++
typedef struct Elm *addr;

struct Infotype {};

struct Elm {
    Infotype info;
    addr next;
    addr prev;
};

struct List {
    addr first;
    addr last;
};

void createList(List &list);
addr allocateElm(Infotype info);
bool isEmpty(List list);
void insertAfter(List &list, addr baru, addr sebelum);
void insertLast(List &list, addr baru);
void remove(List &list, addr elm);
addr find(List list, Infotype info); // atau ganti jadi salah satu atribut
```

- Multi Linked List (MLL):

```c++
typedef struct Elm *addr;

struct Elm {
    addrNode1 node1;
    addrNode2 node2;
    addr next;
    addr prev;
};

struct List {
    addr first;
    addr last;
};

void createList(List &list);
addr allocateElm(addrNode1 node1, addrNode2 node2);
bool isEmpty(List list);
void insertLast(List &list, addr baru);
void remove(List &list, addr elm);
addr findNode1(List list, InfotypeNode1 info); // atau ganti jadi salah satu atribut
addr findNode2(List list, InfotypeNode2 info); // atau ganti jadi salah satu atribut
void removeNode1(List &list, addrNode1 node1);
void removeNode2(List &list, addrNode2 node2);
void displayNode1(List list, addrNode1 node1);
void displayNode2(List list, addrNode2 node2);
```

- Graph (hanya untuk lagu):

```c++
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

void createGraph(Graph &graph);
addr allocateNode(Infotype info);
addr allocateEdge(addr node);
bool isEmpty(Graph graph);
void insertNode(Graph &G, addr node);
void connectNode(addr &node1, addr node2);
void disconnectNode(addr &node1, addr node2);
void connectNodeGenre(addr &node1, addr node2);
void disconnectNodeGenre(addr &node1, addr node2);
void connectNodeBahasa(addr &node1, addr node2);
void disconnectNodeBahasa(addr &node1, addr node2);
```