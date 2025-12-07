#include <iostream>

#include "headers/Lagu.h"
#include "headers/Penyanyi.h"
#include "headers/RelasiPenyanyiLagu.h"
#include "headers/RelasiUserPlaylist.h"
#include "headers/User.h"

void test();

int main() {
    test();

    return 0;
}

void test() {
    lagu::Graph g;
    penyanyi::List l;
    relasi_penyanyi_lagu::List rpl;
    antrean::List a;
    user::List u;
    relasi_user_playlist::List rup;
    relasi_playlist_lagu::List rpll;
    playlist::List p;

    lagu::createGraph(g);

    lagu::Infotype iL1;
    iL1.judul = "Lagu 1";
    iL1.penyanyi = "Penyanyi 1";
    iL1.durasi = 300;
    iL1.album = "Album 1";
    iL1.genre = "Pop";
    iL1.bahasa = "Indonesia";
    lagu::addr l1 = lagu::allocateNode(iL1);

    lagu::Infotype iL2;
    iL2.judul = "Lagu 2";
    iL2.penyanyi = "Penyanyi 1";
    iL2.durasi = 300;
    iL2.album = "Album 2";
    iL2.genre = "Pop";
    iL2.bahasa = "Indonesia";
    lagu::addr l2 = lagu::allocateNode(iL2);

    lagu::Infotype iL3;
    iL3.judul = "Lagu 3";
    iL3.penyanyi = "Penyanyi 2";
    iL3.durasi = 300;
    iL3.album = "Album 3";
    iL3.genre = "Pop";
    iL3.bahasa = "Indonesia";
    lagu::addr l3 = lagu::allocateNode(iL3);

    lagu::Infotype iL4;
    iL4.judul = "Lagu 4";
    iL4.penyanyi = "Penyanyi 3";
    iL4.durasi = 300;
    iL4.album = "Album 4";
    iL4.genre = "Pop";
    iL4.bahasa = "Indonesia";
    lagu::addr l4 = lagu::allocateNode(iL4);

    lagu::Infotype iL5;
    iL5.judul = "Lagu 5";
    iL5.penyanyi = "Penyanyi 3";
    iL5.durasi = 300;
    iL5.album = "Album 5";
    iL5.genre = "Pop";
    iL5.bahasa = "Indonesia";
    lagu::addr l5 = lagu::allocateNode(iL5);

    lagu::insertNode(g, l1);
    lagu::insertNode(g, l2);
    lagu::insertNode(g, l3);
    lagu::insertNode(g, l4);
    lagu::insertNode(g, l5);

    cout << "setelah ditambahkan" << endl;
    lagu::displayLagu(g);

    lagu::connectNode(l2, l4);
    if (lagu::isConnected(l2, l4)) {
        cout << "lagu: " << l2->info.judul << " terkoneksi dengan lagu: " << l4->info.judul << endl;
        lagu::displayEdge(l2);
    } else {
        cout << "lagu: " << l2->info.judul << " tidak terkoneksi dengan lagu: " << l4->info.judul << endl;
        lagu::displayEdge(l2);
    }

    lagu::disconnectNode(l4, l2);
    if (lagu::isConnected(l4, l2)) {
        cout << "lagu: " << l2->info.judul << " masih terkoneksi dengan lagu: " << l4->info.judul << endl;
        lagu::displayEdge(l4);
    } else {
        cout << "lagu: " << l2->info.judul << " tidak lagi terkoneksi dengan lagu: " << l4->info.judul << endl;
        lagu::displayEdge(l4);
    }

    cout << endl;

    penyanyi::createList(l);
    relasi_penyanyi_lagu::createList(rpl);

    penyanyi::Infotype iP1;
    iP1.nama = "Penyanyi 1";
    iP1.tahunDebut = 2000;
    penyanyi::addr p1 = penyanyi::allocateElm(iP1);

    penyanyi::Infotype iP2;
    iP2.nama = "Penyanyi 2";
    iP2.tahunDebut = 1983;
    penyanyi::addr p2 = penyanyi::allocateElm(iP2);

    penyanyi::Infotype iP3;
    iP3.nama = "Penyanyi 3";
    iP3.tahunDebut = 2010;
    penyanyi::addr p3 = penyanyi::allocateElm(iP3);

    penyanyi::insertLast(l, p1);
    penyanyi::insertLast(l, p2);
    penyanyi::insertAfter(l, p3, p1);

    penyanyi::displayPenyanyi(l);

    relasi_penyanyi_lagu::addr r1 = relasi_penyanyi_lagu::allocateElm(l1, p1);
    relasi_penyanyi_lagu::insertLast(rpl, r1);

    relasi_penyanyi_lagu::addr r2 = relasi_penyanyi_lagu::allocateElm(l2, p1);
    relasi_penyanyi_lagu::insertLast(rpl, r2);

    relasi_penyanyi_lagu::addr r3 = relasi_penyanyi_lagu::allocateElm(l3, p2);
    relasi_penyanyi_lagu::insertLast(rpl, r3);

    relasi_penyanyi_lagu::addr r4 = relasi_penyanyi_lagu::allocateElm(l4, p3);
    relasi_penyanyi_lagu::insertLast(rpl, r4);

    relasi_penyanyi_lagu::addr r5 = relasi_penyanyi_lagu::allocateElm(l5, p3);
    relasi_penyanyi_lagu::insertLast(rpl, r5);

    antrean::List a1 = relasi_penyanyi_lagu::listLagu(rpl, p1);
    antrean::List a2 = relasi_penyanyi_lagu::listLagu(rpl, p2);
    antrean::List a3 = relasi_penyanyi_lagu::listLagu(rpl, p3);

    cout << "lagu " << p1->info.nama << endl;
    antrean::displayAntrean(a1);
    cout << "lagu " << p2->info.nama << endl;
    antrean::displayAntrean(a2);
    cout << "lagu " << p3->info.nama << endl;
    antrean::displayAntrean(a3);

    cout << endl;

    antrean::createList(a);

    antrean::Infotype ia1;
    ia1.lagu = l1;
    antrean::Infotype ia2;
    ia2.lagu = l2;
    antrean::Infotype ia3;
    ia3.lagu = l3;
    antrean::Infotype ia4;
    ia4.lagu = l4;
    antrean::Infotype ia5;
    ia5.lagu = l5;

    antrean::addr aa1 = antrean::allocateElm(ia1);
    antrean::addr aa2 = antrean::allocateElm(ia2);
    antrean::addr aa3 = antrean::allocateElm(ia3);
    antrean::addr aa4 = antrean::allocateElm(ia4);
    antrean::addr aa5 = antrean::allocateElm(ia5);

    antrean::insertLast(a, aa1);
    antrean::insertLast(a, aa2);
    antrean::insertAfter(a, aa3, aa1);
    antrean::insertLast(a, aa4);
    antrean::insertLast(a, aa5);

    cout << "daftar lagu untuk dimainkan" << endl;
    antrean::displayAntrean(a);

    antrean::shuffle(a);
    cout << "daftar lagu setelah di-shuffle" << endl;
    antrean::displayAntrean(a);

    cout << endl;

    user::createList(u);

    user::Infotype iu1;
    iu1.username = "user1";
    iu1.password = "pwuser1";
    iu1.namaPanjang = "User 1";
    user::addr u1 = user::allocateElm(iu1);

    user::Infotype iu2;
    iu2.username = "user2";
    iu2.password = "pwuser2";
    iu2.namaPanjang = "User 2";
    user::addr u2 = user::allocateElm(iu2);

    user::insertLast(u, u1);
    user::insertLast(u, u2);

    cout << "misal login dengan user2 password pwuser (salah)" << endl;
    user::addr u3 = user::find(u, "user2", "pwuser");
    if (u3 == nullptr) {
        cout << "user tidak dapat ditemukan" << endl;
    } else {
        cout << "user ditemukan" << endl;
    }

    cout << "misal login dengan user2 password pwuser (salah)" << endl;
    u3 = user::find(u, "user2", "pwuser2");
    if (u3 == nullptr) {
        cout << "user tidak dapat ditemukan" << endl;
    } else {
        cout << "user ditemukan" << endl;
    }

    playlist::createList(p);

    playlist::Infotype ipl1;
    ipl1.judul = "Playlist 1";
    playlist::addr pl1 = playlist::allocateElm(ipl1);
    playlist::insertLast(p, pl1);

    playlist::Infotype ipl2;
    ipl2.judul = "Playlist 2";
    playlist::addr pl2 = playlist::allocateElm(ipl2);
    playlist::insertLast(p, pl2);

    playlist::Infotype ipl3;
    ipl3.judul = "Playlist 3";
    playlist::addr pl3 = playlist::allocateElm(ipl3);
    playlist::insertLast(p, pl3);

    cout << endl;

    relasi_user_playlist::createList(rup);

    relasi_user_playlist::addr rup1 = relasi_user_playlist::allocateElm(u1, pl1);
    relasi_user_playlist::insertLast(rup, rup1);
    relasi_user_playlist::addr rup2 = relasi_user_playlist::allocateElm(u1, pl2);
    relasi_user_playlist::insertLast(rup, rup2);

    relasi_user_playlist::displayPlaylist(rup, u1);

    relasi_user_playlist::addr rup3 = relasi_user_playlist::allocateElm(u2, pl3);
    relasi_user_playlist::insertLast(rup, rup3);

    relasi_user_playlist::displayPlaylist(rup, u2);

    cout << endl;

    relasi_playlist_lagu::createList(rpll);

    relasi_playlist_lagu::addr rpll1 = relasi_playlist_lagu::allocateElm(pl1, l1);
    relasi_playlist_lagu::insertLast(rpll, rpll1);
    relasi_playlist_lagu::addr rpll2 = relasi_playlist_lagu::allocateElm(pl1, l2);
    relasi_playlist_lagu::insertLast(rpll, rpll2);
    relasi_playlist_lagu::addr rpll3 = relasi_playlist_lagu::allocateElm(pl2, l3);
    relasi_playlist_lagu::insertLast(rpll, rpll3);
    relasi_playlist_lagu::addr rpll4 = relasi_playlist_lagu::allocateElm(pl2, l2);
    relasi_playlist_lagu::insertLast(rpll, rpll4);
    relasi_playlist_lagu::addr rpll5 = relasi_playlist_lagu::allocateElm(pl3, l1);
    relasi_playlist_lagu::insertLast(rpll, rpll5);
    relasi_playlist_lagu::addr rpll6 = relasi_playlist_lagu::allocateElm(pl3, l4);
    relasi_playlist_lagu::insertLast(rpll, rpll6);
    relasi_playlist_lagu::addr rpll7 = relasi_playlist_lagu::allocateElm(pl3, l5);
    relasi_playlist_lagu::insertLast(rpll, rpll7);

    antrean::List rplla1 = relasi_playlist_lagu::listLagu(rpll, pl1);
    antrean::List rplla2 = relasi_playlist_lagu::listLagu(rpll, pl2);
    antrean::List rplla3 = relasi_playlist_lagu::listLagu(rpll, pl3);

    cout << pl1->info.judul << endl;
    antrean::displayAntrean(rplla1);
    cout << pl2->info.judul << endl;
    antrean::displayAntrean(rplla2);
    cout << pl3->info.judul << endl;
    antrean::displayAntrean(rplla3);

    relasi_playlist_lagu::removePlaylist(rpll, pl2);

    cout << "setelah dihapus" << endl;

    relasi_user_playlist::displayPlaylist(rup, u1);
}
