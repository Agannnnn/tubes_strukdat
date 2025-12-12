#include <iostream>

#include "headers/Song.h"
#include "headers/Penyanyi.h"
#include "headers/RelasiPenyanyiLagu.h"
#include "headers/RelasiUserPlaylist.h"
#include "headers/User.h"

void test_song();

void test();

int main() {
    test_song();

    return 0;
}

void test_song() {
    song::Graph song;

    song::createGraph(song);

    song::addr song1 = song::allocateVertex({"song_1", "singer_1", "album_1", 300, "genre_a", "lang_a"});
    song::addr song2 = song::allocateVertex({"song_2", "singer_1", "album_1", 260, "genre_b", "lang_a"});
    song::addr song3 = song::allocateVertex({"song_3", "singer_1", "album_2", 180, "genre_a", "lang_a"});
    song::addr song4 = song::allocateVertex({"song_4", "singer_2", "album_1", 100, "genre_b", "lang_b"});
    song::addr song5 = song::allocateVertex({"song_5", "singer_3", "album_1", 200, "genre_a", "lang_b"});
    song::addr song6 = song::allocateVertex({"song_6", "singer_3", "album_2", 160, "genre_c", "lang_a"});
    song::addr song7 = song::allocateVertex({"song_7", "singer_4", "album_1", 80, "genre_b", "lang_c"});

    song::insertVertex(song, song3);
    song::insertVertex(song, song1);
    song::insertVertex(song, song4);
    song::insertVertex(song, song2);
    song::insertVertex(song, song5);
    song::insertVertex(song, song6);
    song::insertVertex(song, song7);

    // nyambung lagu dengan genre_a
    song::connectVertex(song1, song3, song::GENRE);
    song::connectVertex(song1, song5, song::GENRE);
    song::connectVertex(song3, song5, song::GENRE);

    // nyambung lagu dengan genre_b
    song::connectVertex(song2, song4, song::GENRE);
    song::connectVertex(song2, song7, song::GENRE);
    song::connectVertex(song4, song7, song::GENRE);

    // nyambung lagu dengan bahasa_a
    song::connectVertex(song1, song2, song::LANGUAGE);
    song::connectVertex(song1, song3, song::LANGUAGE);
    song::connectVertex(song1, song6, song::LANGUAGE);
    song::connectVertex(song2, song6, song::LANGUAGE);
    song::connectVertex(song3, song6, song::LANGUAGE);

    // nyambung lagu dengan bahasa_b
    song::connectVertex(song4, song5, song::LANGUAGE);

    // display semua lagu
    song::display(song);

    // display relasi lagu berdasarkan genre
    song::displayConnections(song1, song::GENRE);
    song::displayConnections(song2, song::GENRE);

    // display relasi lagu berdasarkan bahasa
    song::displayConnections(song1, song::LANGUAGE);
    song::displayConnections(song4, song::LANGUAGE);

    // cari lagu
    song::addr p = song::find(song, "song_3");
    if (p) {
        printf("| title: %20s | singer: %20s |\n", p->info.title.c_str(), p->info.singer.c_str());
    } else {
        cout << "song not found" << endl;
    }

    // buat antrean berdasarkan lagu dan genre yang sama
    antrean::List antrean = song::listBy(song1, song::GENRE);
    antrean::displayAntrean(antrean);
}

// void test() {
//     song::Graph g;
//     penyanyi::List l;
//     relasi_penyanyi_lagu::List rpl;
//     antrean::List a;
//     user::List u;
//     relasi_user_playlist::List rup;
//     relasi_playlist_lagu::List rpll;
//     playlist::List p;
//
//     song::createGraph(g);
//
//     song::Infotype iL1;
//     iL1.title = "Lagu 1";
//     iL1.singer = "Penyanyi 1";
//     iL1.duration = 300;
//     iL1.album = "Album 1";
//     iL1.genre = "Pop";
//     iL1.language = "Indonesia";
//     song::addr l1 = song::allocateVertex(iL1);
//
//     song::Infotype iL2;
//     iL2.title = "Lagu 2";
//     iL2.singer = "Penyanyi 1";
//     iL2.duration = 300;
//     iL2.album = "Album 2";
//     iL2.genre = "Pop";
//     iL2.language = "Indonesia";
//     song::addr l2 = song::allocateVertex(iL2);
//
//     song::Infotype iL3;
//     iL3.title = "Lagu 3";
//     iL3.singer = "Penyanyi 2";
//     iL3.duration = 300;
//     iL3.album = "Album 3";
//     iL3.genre = "Pop";
//     iL3.language = "Indonesia";
//     song::addr l3 = song::allocateVertex(iL3);
//
//     song::Infotype iL4;
//     iL4.title = "Lagu 4";
//     iL4.singer = "Penyanyi 3";
//     iL4.duration = 300;
//     iL4.album = "Album 4";
//     iL4.genre = "Pop";
//     iL4.language = "Indonesia";
//     song::addr l4 = song::allocateVertex(iL4);
//
//     song::Infotype iL5;
//     iL5.title = "Lagu 5";
//     iL5.singer = "Penyanyi 3";
//     iL5.duration = 300;
//     iL5.album = "Album 5";
//     iL5.genre = "Pop";
//     iL5.language = "Indonesia";
//     song::addr l5 = song::allocateVertex(iL5);
//
//     song::insertVertex(g, l1);
//     song::insertVertex(g, l2);
//     song::insertVertex(g, l3);
//     song::insertVertex(g, l4);
//     song::insertVertex(g, l5);
//
//     cout << "setelah ditambahkan" << endl;
//     song::display(g);
//
//     song::connectNodes(l2, l4);
//     if (song::isConnected(l2, l4)) {
//         cout << "lagu: " << l2->info.title << " terkoneksi dengan lagu: " << l4->info.title << endl;
//         song::displayEdges(l2);
//     } else {
//         cout << "lagu: " << l2->info.title << " tidak terkoneksi dengan lagu: " << l4->info.title << endl;
//         song::displayEdges(l2);
//     }
//
//     song::disconnectNode(l4, l2);
//     if (song::isConnected(l4, l2)) {
//         cout << "lagu: " << l2->info.title << " masih terkoneksi dengan lagu: " << l4->info.title << endl;
//         song::displayEdges(l4);
//     } else {
//         cout << "lagu: " << l2->info.title << " tidak lagi terkoneksi dengan lagu: " << l4->info.title << endl;
//         song::displayEdges(l4);
//     }
//
//     cout << endl;
//
//     penyanyi::createList(l);
//     relasi_penyanyi_lagu::createList(rpl);
//
//     penyanyi::Infotype iP1;
//     iP1.nama = "Penyanyi 1";
//     iP1.tahunDebut = 2000;
//     penyanyi::addr p1 = penyanyi::allocateElm(iP1);
//
//     penyanyi::Infotype iP2;
//     iP2.nama = "Penyanyi 2";
//     iP2.tahunDebut = 1983;
//     penyanyi::addr p2 = penyanyi::allocateElm(iP2);
//
//     penyanyi::Infotype iP3;
//     iP3.nama = "Penyanyi 3";
//     iP3.tahunDebut = 2010;
//     penyanyi::addr p3 = penyanyi::allocateElm(iP3);
//
//     penyanyi::insertLast(l, p1);
//     penyanyi::insertLast(l, p2);
//     penyanyi::insertAfter(l, p3, p1);
//
//     penyanyi::displayPenyanyi(l);
//
//     relasi_penyanyi_lagu::addr r1 = relasi_penyanyi_lagu::allocateElm(l1, p1);
//     relasi_penyanyi_lagu::insertLast(rpl, r1);
//
//     relasi_penyanyi_lagu::addr r2 = relasi_penyanyi_lagu::allocateElm(l2, p1);
//     relasi_penyanyi_lagu::insertLast(rpl, r2);
//
//     relasi_penyanyi_lagu::addr r3 = relasi_penyanyi_lagu::allocateElm(l3, p2);
//     relasi_penyanyi_lagu::insertLast(rpl, r3);
//
//     relasi_penyanyi_lagu::addr r4 = relasi_penyanyi_lagu::allocateElm(l4, p3);
//     relasi_penyanyi_lagu::insertLast(rpl, r4);
//
//     relasi_penyanyi_lagu::addr r5 = relasi_penyanyi_lagu::allocateElm(l5, p3);
//     relasi_penyanyi_lagu::insertLast(rpl, r5);
//
//     antrean::List a1 = relasi_penyanyi_lagu::listLagu(rpl, p1);
//     antrean::List a2 = relasi_penyanyi_lagu::listLagu(rpl, p2);
//     antrean::List a3 = relasi_penyanyi_lagu::listLagu(rpl, p3);
//
//     cout << "lagu " << p1->info.nama << endl;
//     antrean::displayAntrean(a1);
//     cout << "lagu " << p2->info.nama << endl;
//     antrean::displayAntrean(a2);
//     cout << "lagu " << p3->info.nama << endl;
//     antrean::displayAntrean(a3);
//
//     cout << endl;
//
//     antrean::createList(a);
//
//     antrean::Infotype ia1;
//     ia1.lagu = l1;
//     antrean::Infotype ia2;
//     ia2.lagu = l2;
//     antrean::Infotype ia3;
//     ia3.lagu = l3;
//     antrean::Infotype ia4;
//     ia4.lagu = l4;
//     antrean::Infotype ia5;
//     ia5.lagu = l5;
//
//     antrean::addr aa1 = antrean::allocateElm(ia1);
//     antrean::addr aa2 = antrean::allocateElm(ia2);
//     antrean::addr aa3 = antrean::allocateElm(ia3);
//     antrean::addr aa4 = antrean::allocateElm(ia4);
//     antrean::addr aa5 = antrean::allocateElm(ia5);
//
//     antrean::insertLast(a, aa1);
//     antrean::insertLast(a, aa2);
//     antrean::insertAfter(a, aa3, aa1);
//     antrean::insertLast(a, aa4);
//     antrean::insertLast(a, aa5);
//
//     cout << "daftar lagu untuk dimainkan" << endl;
//     antrean::displayAntrean(a);
//
//     antrean::shuffle(a);
//     cout << "daftar lagu setelah di-shuffle" << endl;
//     antrean::displayAntrean(a);
//
//     cout << endl;
//
//     user::createList(u);
//
//     user::Infotype iu1;
//     iu1.username = "user1";
//     iu1.password = "pwuser1";
//     iu1.namaPanjang = "User 1";
//     user::addr u1 = user::allocateElm(iu1);
//
//     user::Infotype iu2;
//     iu2.username = "user2";
//     iu2.password = "pwuser2";
//     iu2.namaPanjang = "User 2";
//     user::addr u2 = user::allocateElm(iu2);
//
//     user::insertLast(u, u1);
//     user::insertLast(u, u2);
//
//     cout << "misal login dengan user2 password pwuser (salah)" << endl;
//     user::addr u3 = user::find(u, "user2", "pwuser");
//     if (u3 == nullptr) {
//         cout << "user tidak dapat ditemukan" << endl;
//     } else {
//         cout << "user ditemukan" << endl;
//     }
//
//     cout << "misal login dengan user2 password pwuser (salah)" << endl;
//     u3 = user::find(u, "user2", "pwuser2");
//     if (u3 == nullptr) {
//         cout << "user tidak dapat ditemukan" << endl;
//     } else {
//         cout << "user ditemukan" << endl;
//     }
//
//     playlist::createList(p);
//
//     playlist::Infotype ipl1;
//     ipl1.judul = "Playlist 1";
//     playlist::addr pl1 = playlist::allocateElm(ipl1);
//     playlist::insertLast(p, pl1);
//
//     playlist::Infotype ipl2;
//     ipl2.judul = "Playlist 2";
//     playlist::addr pl2 = playlist::allocateElm(ipl2);
//     playlist::insertLast(p, pl2);
//
//     playlist::Infotype ipl3;
//     ipl3.judul = "Playlist 3";
//     playlist::addr pl3 = playlist::allocateElm(ipl3);
//     playlist::insertLast(p, pl3);
//
//     cout << endl;
//
//     relasi_user_playlist::createList(rup);
//
//     relasi_user_playlist::addr rup1 = relasi_user_playlist::allocateElm(u1, pl1);
//     relasi_user_playlist::insertLast(rup, rup1);
//     relasi_user_playlist::addr rup2 = relasi_user_playlist::allocateElm(u1, pl2);
//     relasi_user_playlist::insertLast(rup, rup2);
//
//     relasi_user_playlist::displayPlaylist(rup, u1);
//
//     relasi_user_playlist::addr rup3 = relasi_user_playlist::allocateElm(u2, pl3);
//     relasi_user_playlist::insertLast(rup, rup3);
//
//     relasi_user_playlist::displayPlaylist(rup, u2);
//
//     cout << endl;
//
//     relasi_playlist_lagu::createList(rpll);
//
//     relasi_playlist_lagu::addr rpll1 = relasi_playlist_lagu::allocateElm(pl1, l1);
//     relasi_playlist_lagu::insertLast(rpll, rpll1);
//     relasi_playlist_lagu::addr rpll2 = relasi_playlist_lagu::allocateElm(pl1, l2);
//     relasi_playlist_lagu::insertLast(rpll, rpll2);
//     relasi_playlist_lagu::addr rpll3 = relasi_playlist_lagu::allocateElm(pl2, l3);
//     relasi_playlist_lagu::insertLast(rpll, rpll3);
//     relasi_playlist_lagu::addr rpll4 = relasi_playlist_lagu::allocateElm(pl2, l2);
//     relasi_playlist_lagu::insertLast(rpll, rpll4);
//     relasi_playlist_lagu::addr rpll5 = relasi_playlist_lagu::allocateElm(pl3, l1);
//     relasi_playlist_lagu::insertLast(rpll, rpll5);
//     relasi_playlist_lagu::addr rpll6 = relasi_playlist_lagu::allocateElm(pl3, l4);
//     relasi_playlist_lagu::insertLast(rpll, rpll6);
//     relasi_playlist_lagu::addr rpll7 = relasi_playlist_lagu::allocateElm(pl3, l5);
//     relasi_playlist_lagu::insertLast(rpll, rpll7);
//
//     antrean::List rplla1 = relasi_playlist_lagu::listLagu(rpll, pl1);
//     antrean::List rplla2 = relasi_playlist_lagu::listLagu(rpll, pl2);
//     antrean::List rplla3 = relasi_playlist_lagu::listLagu(rpll, pl3);
//
//     cout << pl1->info.judul << endl;
//     antrean::displayAntrean(rplla1);
//     cout << pl2->info.judul << endl;
//     antrean::displayAntrean(rplla2);
//     cout << pl3->info.judul << endl;
//     antrean::displayAntrean(rplla3);
//
//     relasi_playlist_lagu::removePlaylist(rpll, pl2);
//
//     cout << "setelah dihapus" << endl;
//
//     relasi_user_playlist::displayPlaylist(rup, u1);
// }
