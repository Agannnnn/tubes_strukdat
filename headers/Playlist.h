#ifndef TUBES_STD_PLAYLIST_H
#define TUBES_STD_PLAYLIST_H

#include "RelasiPlaylistLagu.h"

using namespace std;

namespace playlist {
    typedef struct Elm *addr;

    struct Infotype {
        string judul;
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
     * @param list list yang dioperasikan
     */
    void createList(List &list);

    /**
     * i.s. nilai diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address dari elmeen yang baru dibuat
     * @param info nilai dari elemen
     * @return address elemen yang dibuat
     */
    addr allocateElm(Infotype info);

    /**
     * i.s. list diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan nilai boolean yang menandakan apakah list kosong atau tidak
     * @param list list yang dioperasikan
     * @return status apakah list kosong (true) atau tidak (false)
     */
    bool isEmpty(List list);

    /**
     * i.s. list, elemen baru, dan elemen penanda diberikan sebagai argumen. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpen setelah elemen penanda
     * @param list list yang dioperasikan
     * @param baru address elemen yang ingin ditambahkan
     * @param sebelum address elemen penanda
     */
    void insertAfter(List &list, addr baru, addr sebelum);

    /**
     * i.s. list diberikan sebagai arguman. List berisikan elemen-elemen tanpa elemen baru
     *
     * f.s. list diperbarui dengan elemen yang ingin ditambahkan disimpan pada urutan paling belakang
     * @param list list yang dioperasikan
     * @param baru address elemen yang ingin ditambahkan
     */
    void insertLast(List &list, addr baru);

    /**
     * i.s. list dan relasi playlist-lagu diberikan sebagai argumen. List berisikan elemen-elemen termasuk elemen yang ingin dihapus
     *
     * f.s. list diperbarui dengan elmen yang ingin dihapus hilang dari list, dan elemen-elemen tetangganya digeser. Relasi playlist-lagu yang terkait juga dihapus
     * @param list list yang dioperasikan
     * @param elm address elemen yang ingin dihapus
     * @param listRelasi relasi playlist-lagu yang akan diperbarui
     */
    void remove(List & list, addr & elm, relasi_playlist_lagu::List & listRelasi);

    /**
     * i.s. list, judul playlist diberikan sebagai argumen
     *
     * f.s. fungsi mengembalikan address elemen dengan judul yang sama atau nullptr jika tidak ada elemen dengan judul yang sama
     * @param list list yang dioperasikan
     * @param judul judul playlist yang dicari
     * @return address elemen playlist yang berisikan judul yang dicari
     */
    addr find(List list, string judul);
}

#endif //TUBES_STD_PLAYLIST_H