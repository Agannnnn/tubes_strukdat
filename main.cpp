#include <iostream>
#include <thread>

#include "SFML/Audio/SoundBuffer.hpp"

#include "headers/AdminMenu.h"
#include "headers/Music.h"
#include "headers/Playlist.h"
#include "headers/PlaylistMusic.h"
#include "headers/Queue.h"
#include "headers/Artists.h"
#include "headers/SingerMusic.h"
#include "headers/User.h"
#include "headers/UserMenu.h"
#include "headers/UserPlaylist.h"

// void testUser(user::List &user) {
//     user::createList(user);
//
//     user::addr e1 = user::allocateElm({"user_1", "pw1", "user 1"});
//     user::insertLast(user, e1);
//     user::addr e2 = user::allocateElm({"user_2", "pw2", "user 2"});
//     user::insertLast(user, e2);
//     user::addr e3 = user::allocateElm({"user_3", "pw3", "user 3"});
//     user::insertLast(user, e3);
//
//     // try finding user of username 'user_2' and password 'pw2'
//     if (user::find(user, "user_2", "pw2")) {
//         cout << "there is a user of user_2" << endl;
//     } else {
//         cout << "user_2 not found" << endl;
//     }
// }
//
// void testMusic(music::Graph &library) {
//     music::createGraph(library);
//
//     music::addr song1 = music::allocateVertex({
//         "andaikan_kau_datang",
//         "ruth_sahayana",
//         "album_1",
//         300,
//         "genre_a",
//         "lang_a",
//         "../assets/andaikan_kau_datang.mp3"
//     });
//     music::addr song2 = music::allocateVertex({
//         "close_to_you_jauh",
//         "reality_club",
//         "album_1",
//         260,
//         "genre_b",
//         "lang_a",
//         "../assets/close_to_you_jauh.mp3"
//     });
//     music::addr song3 = music::allocateVertex({
//         "lukisan_jiwa",
//         "mayang_sari",
//         "album_2",
//         180,
//         "genre_a",
//         "lang_a",
//         "../assets/lukisan_jiwa.mp3"
//     });
//     music::addr song4 = music::allocateVertex({
//         "my_heart_will_go_on",
//         "celine_dion",
//         "album_1",
//         100,
//         "genre_b",
//         "lang_b",
//         "../assets/my_heart_will_go_on.mp3"
//     });
//     music::addr song5 = music::allocateVertex({
//         "sabilulungan",
//         "suaray_parahiangan",
//         "album_1",
//         200,
//         "genre_a",
//         "lang_b",
//         "../assets/sabilulungan.mp3"
//     });
//     music::addr song6 = music::allocateVertex({
//         "send_my_love_to_your_new_lover",
//         "adele",
//         "album_2",
//         160,
//         "genre_c",
//         "lang_a",
//         "../assets/send_my_love_to_your_new_lover.mp3"
//     });
//     music::addr song7 = music::allocateVertex({
//         "tegar",
//         "rossa",
//         "album_1",
//         80,
//         "genre_b",
//         "lang_c",
//         "../assets/tegar.mp3"
//     });
//
//     music::insertVertex(library, song3);
//     music::insertVertex(library, song1);
//     music::insertVertex(library, song4);
//     music::insertVertex(library, song2);
//     music::insertVertex(library, song5);
//     music::insertVertex(library, song6);
//     music::insertVertex(library, song7);
//
//     music::display(library);
//
//     // nyambung lagu dengan genre_a
//     music::insertVertex(library, song1, music::GENRE);
//     music::insertVertex(library, song3, music::GENRE);
//     music::insertVertex(library, song5, music::GENRE);
//
//     // nyambung lagu dengan genre_b
//     music::insertVertex(library, song2, music::GENRE);
//     music::insertVertex(library, song4, music::GENRE);
//     music::insertVertex(library, song7, music::GENRE);
//
//     // nyambung lagu dengan genre_c
//     music::insertVertex(library, song6, music::GENRE);
//
//     // nyambung lagu dengan bahasa_a
//     music::insertVertex(library, song1, music::LANGUAGE);
//     music::insertVertex(library, song2, music::LANGUAGE);
//     music::insertVertex(library, song4, music::LANGUAGE);
//     music::insertVertex(library, song6, music::LANGUAGE);
//
//     // nyambung lagu dengan bahasa_b
//     music::insertVertex(library, song3, music::LANGUAGE);
//     music::insertVertex(library, song5, music::LANGUAGE);
//
//     // nyambung lagu dengan bahasa_c
//     music::insertVertex(library, song7, music::LANGUAGE);
//
//     music::connectVertex(song4, song5, music::LANGUAGE);
//     music::connectVertex(song4, song5, music::LANGUAGE);
//
//     // display relasi lagu
//     music::displayRelations(song1, music::MUSIC);
//     music::displayRelations(song3, music::MUSIC);
//     music::displayRelations(song7, music::MUSIC);
//
//     // display relasi lagu berdasarkan genre
//     music::displayRelations(song1, music::GENRE);
//     music::displayRelations(song3, music::GENRE);
//     music::displayRelations(song7, music::GENRE);
//
//     // display relasi lagu berdasarkan bahasa
//     music::displayRelations(song1, music::LANGUAGE);
//     music::displayRelations(song3, music::LANGUAGE);
//     music::displayRelations(song7, music::LANGUAGE);
//
//     // cari lagu
//     music::addr p = music::find(library, "Andaikan Kau Datang");
//     if (p) {
//         printf("[FOUND] %s (%s)\n", p->info.title.c_str(), p->info.artists.c_str());
//     } else {
//         cout << "[NOT FOUND]" << endl;
//     }
//
//     // display lagu segenre
//     queue::List lagu1Relations = music::listBy(library, song1, music::GENRE);
//     queue::display(lagu1Relations);
//
//     // display lagu sebahasa
//     queue::List lagu3Relations = music::listBy(library, song1, music::LANGUAGE);
//     queue::display(lagu3Relations);
//
//     // hapus koneksi antara song 3 dan 2
//     music::disconnectVertex(song3, song2, music::LANGUAGE);
//     music::displayRelations(song3, music::LANGUAGE);
//     music::displayRelations(song2, music::LANGUAGE);
//
//     // hapus vertex dari graf
//     music::deleteVertex(library, song2, music::MUSIC);
//     music::display(library);
// }
//
// void testQueue(music::Graph &library, queue::List &queue) {
//     queue::createList(queue);
//
//     // ambil lagu 'Lukisan Jiwa' dan teman-teman segenrenya
//     music::addr m = music::find(library, "Lukisan Jiwa");
//     queue::List mRelations = music::listBy(library, m, music::GENRE);
//     queue::addr r = mRelations.first;
//     while (r != nullptr) {
//         queue::insertLast(queue, r);
//         r = r->next;
//     }
//     queue::display(queue);
//
//     // cari lagu 'Send My Love (To Your New Lover)' lalu tambahkan setelah lagu pertama
//     m = music::find(library, "Send My Love (To Your New Lover)");
//     queue::insertAfter(queue, queue::allocateElm(m), queue.first);
//     queue::display(queue);
//
//     // cari lagu 'Sabilulungan' lalu hapus dari queue
//     r = queue::find(queue, "Sabilulungan");
//     if (r != nullptr) {
//         queue::remove(queue, r);
//     }
//     queue::display(queue);
//
//     // shuffle urutan lagu
//     queue::shuffle(queue);
//     queue::display(queue);
//
//     sf::SoundBuffer sb;
//     sf::Sound s(sb);
//
//     // putar lagu
//     // queue::addr q = queue.first;
//     // sb = queue::load(q);
//     // thread tPlay1(queue::play, ref(sb), ref(s), q->music->info.title, sf::Time::Zero);
//
//     // this_thread::sleep_for(chrono::milliseconds(sb.getDuration().asMilliseconds() / 2));
//
//     // pause lagu
//     // sf::Time offset = queue::pause(s);
//     // tPlay1.join();
//     // printf("lagu dipause pada durasi %.2f s\n", offset.asSeconds());
//
//     // resume lagu
//     // tPlay1 = thread(queue::play, ref(sb), ref(s), q->music->info.title, offset);
//     // this_thread::sleep_for(chrono::milliseconds(sb.getDuration().asMilliseconds() / 2));
//     // tPlay1.join();
// }
//
// void testSinger(music::Graph &library, artists::List &artists,
//                 singer_music::List &singerMusicRelation) {
//     artists::createList(artists);
//     singer_music::createList(singerMusicRelation);
//
//     artists::addr s1 = artists::allocateElm({"Mayang Sari", 1990});
//     artists::insertLast(artists, s1);
//     artists::addr s2 = artists::allocateElm({"Ruth Sahanaya", 1987});
//     artists::insertLast(artists, s2);
//     artists::addr s3 = artists::allocateElm({"Celine Dion", 2016});
//     artists::insertLast(artists, s3);
//     artists::addr s4 = artists::allocateElm({"Suara Parahiangan", 2025});
//     artists::insertLast(artists, s4);
//     artists::addr s5 = artists::allocateElm({"Adelle", 2008});
//     artists::insertLast(artists, s5);
//     artists::addr s6 = artists::allocateElm({"Rossa", 1988});
//     artists::insertLast(artists, s6);
//
//     artists::display(artists);
//
//     music::addr m1 = music::find(library, "Lukisan Jiwa");
//     if (m1 != nullptr) {
//         singer_music::addr sm1 = singer_music::allocateElm(m1, s1);
//         singer_music::insertLast(singerMusicRelation, sm1);
//     }
//     music::addr m2 = music::find(library, "Andaikan Kau Datang");
//     if (m2 != nullptr) {
//         singer_music::addr sm2 = singer_music::allocateElm(m2, s2);
//         singer_music::insertLast(singerMusicRelation, sm2);
//     }
//     music::addr m3 = music::find(library, "My Heart Will Go On (Love Theme from Titanic)");
//     if (m3 != nullptr) {
//         singer_music::addr sm3 = singer_music::allocateElm(m3, s3);
//         singer_music::insertLast(singerMusicRelation, sm3);
//     }
//     music::addr m4 = music::find(library, "Close to You_Jauh");
//     if (m4 != nullptr) {
//         singer_music::addr sm4 = singer_music::allocateElm(m4, s4);
//         singer_music::insertLast(singerMusicRelation, sm4);
//     }
//     music::addr m5 = music::find(library, "Sabilulungan");
//     if (m5 != nullptr) {
//         singer_music::addr sm5 = singer_music::allocateElm(m5, s5);
//         singer_music::insertLast(singerMusicRelation, sm5);
//     }
//     music::addr m6 = music::find(library, "Send My Love (To Your New Lover)");
//     if (m6 != nullptr) {
//         singer_music::addr sm6 = singer_music::allocateElm(m6, s6);
//         singer_music::insertLast(singerMusicRelation, sm6);
//     }
//
//     queue::display(singer_music::musicCollection(singerMusicRelation, s1));
//     queue::display(singer_music::musicCollection(singerMusicRelation, s2));
//     queue::display(singer_music::musicCollection(singerMusicRelation, s3));
//     queue::display(singer_music::musicCollection(singerMusicRelation, s4));
//     queue::display(singer_music::musicCollection(singerMusicRelation, s5));
//     queue::display(singer_music::musicCollection(singerMusicRelation, s6));
//
//     artists::remove(artists, s3, singerMusicRelation);
//
//     artists::display(artists);
// }

// void testPlaylist(user::List &user, playlist::List &playlist, playlist_music::List &playlistMusicRelation,
//                   user_playlist::List &userPlaylistRelation, music::Graph &library) {
//     playlist::createList(playlist);
//     playlist_music::createList(playlistMusicRelation);
//     user_playlist::createList(userPlaylistRelation);
//
//     playlist::addr p1 = playlist::allocateElm("playlist 1");
//     playlist::insertLast(playlist, p1, user);
//     playlist::addr p2 = playlist::allocateElm("playlist 2");
//     playlist::insertLast(playlist, p2, user);
//     playlist::addr p3 = playlist::allocateElm("playlist 3");
//     playlist::insertLast(playlist, p3, user);
//
//     user::addr u1 = user::find(user, "user_1", "pw1");
//     if (u1 != nullptr) {
//         user_playlist::addr up1 = user_playlist::allocateElm(u1, p1);
//         user_playlist::insertLast(userPlaylistRelation, up1);
//     }
//     user::addr u2 = user::find(user, "user_2", "pw2");
//     if (u2 != nullptr) {
//         user_playlist::addr up2 = user_playlist::allocateElm(u2, p2);
//         user_playlist::insertLast(userPlaylistRelation, up2);
//     }
//     user::addr u3 = user::find(user, "user_3", "pw3");
//     if (u3 != nullptr) {
//         user_playlist::addr up3 = user_playlist::allocateElm(u3, p3);
//         user_playlist::insertLast(userPlaylistRelation, up3);
//     }
//
//     user_playlist::displayPlaylist(userPlaylistRelation, u1);
//     user_playlist::displayPlaylist(userPlaylistRelation, u2);
//     user_playlist::displayPlaylist(userPlaylistRelation, u3);
//
//     music::addr m1 = music::find(library, "Lukisan Jiwa");
//     if (m1 != nullptr) {
//         playlist_music::addr pm1 = playlist_music::allocateElm(p1, m1);
//         playlist_music::insertLast(playlistMusicRelation, pm1);
//     }
//     music::addr m2 = music::find(library, "Andaikan Kau Datang");
//     if (m2 != nullptr) {
//         playlist_music::addr pm2 = playlist_music::allocateElm(p1, m2);
//         playlist_music::insertLast(playlistMusicRelation, pm2);
//     }
//     music::addr m3 = music::find(library, "My Heart Will Go On (Love Theme from Titanic)");
//     if (m3 != nullptr) {
//         playlist_music::addr pm3 = playlist_music::allocateElm(p2, m3);
//         playlist_music::insertLast(playlistMusicRelation, pm3);
//     }
//     music::addr m4 = music::find(library, "Close to You_Jauh");
//     if (m4 != nullptr) {
//         playlist_music::addr pm4 = playlist_music::allocateElm(p3, m4);
//         playlist_music::insertLast(playlistMusicRelation, pm4);
//     }
//     music::addr m5 = music::find(library, "Sabilulungan");
//     if (m5 != nullptr) {
//         playlist_music::addr pm5 = playlist_music::allocateElm(p3, m5);
//         playlist_music::insertLast(playlistMusicRelation, pm5);
//     }
//     music::addr m6 = music::find(library, "Send My Love (To Your New Lover)");
//     if (m6 != nullptr) {
//         playlist_music::addr pm6 = playlist_music::allocateElm(p3, m6);
//         playlist_music::insertLast(playlistMusicRelation, pm6);
//     }
//
//     p1 = playlist::find(playlist, "playlist 1");
//     if (p1 != nullptr) queue::display(playlist_music::musicCollection(playlistMusicRelation, p1));
//     p2 = playlist::find(playlist, "playlist 2");
//     if (p2 != nullptr) queue::display(playlist_music::musicCollection(playlistMusicRelation, p2));
//     p3 = playlist::find(playlist, "playlist 3");
//     if (p3 != nullptr) queue::display(playlist_music::musicCollection(playlistMusicRelation, p3));
//
//     playlist::remove(playlist, p1, playlistMusicRelation, userPlaylistRelation);
//
//     p1 = playlist::find(playlist, "playlist 1");
//     if (p1 != nullptr) {
//         queue::display(playlist_music::musicCollection(playlistMusicRelation, p1));
//         user_playlist::displayPlaylist(userPlaylistRelation, u1);
//     }
// }

// void test() {
//     user::List user{};
//     music::Graph library{};
//     queue::List queue{};
//     artists::List artists{};
//     singer_music::List singerMusicRelation{};
//     playlist::List playlist{};
//     playlist_music::List playlistMusicRelation{};
//     user_playlist::List userPlaylistRelation{};
//
//     testMusic(library);
//     testQueue(library, queue);
//     testSinger(library, artists, singerMusicRelation);
//     testUser(user);
//     testPlaylist(user, playlist, playlistMusicRelation, userPlaylistRelation, library);
// }

void insertMusic(music::Graph &library) {
    music::addr song1 = music::allocateVertex({
        "andaikan_kau_datang",
        "ruth_sahayana",
        "salute_to_koes_plus",
        308,
        "pop",
        "ID",
        "../assets/andaikan_kau_datang.mp3"
    });
    music::addr song2 = music::allocateVertex({
        "close_to_you_jauh",
        "reality_club",
        "who_knows_where_life_will_take_you?",
        200,
        "alternative",
        "ID",
        "../assets/close_to_you_jauh.mp3"
    });
    music::addr song3 = music::allocateVertex({
        "lukisan_jiwa",
        "mayang_sari",
        "lukisan_jiwa",
        217,
        "rock",
        "ID",
        "../assets/lukisan_jiwa.mp3"
    });
    music::addr song4 = music::allocateVertex({
        "my_heart_will_go_on",
        "celine_dion",
        "lets_talk_about_love",
        264,
        "balad",
        "EN",
        "../assets/my_heart_will_go_on.mp3"
    });
    music::addr song5 = music::allocateVertex({
        "sabilulungan",
        "suaray_parahiangan",
        "dagung-sabilulungan",
        324,
        "national",
        "INST",
        "../assets/sabilulungan.mp3"
    });
    music::addr song6 = music::allocateVertex({
        "send_my_love",
        "adele",
        "25",
        207,
        "alternative",
        "EN",
        "../assets/send_my_love_to_your_new_lover.mp3"
    });
    music::addr song7 = music::allocateVertex({
        "tegar",
        "rossa",
        "yang_terpilih",
        206,
        "rock",
        "ID",
        "../assets/tegar.mp3"
    });

    music::insertVertex(library, song1, music::MUSIC);
    music::insertVertex(library, song2, music::MUSIC);
    music::insertVertex(library, song3, music::MUSIC);
    music::insertVertex(library, song4, music::MUSIC);
    music::insertVertex(library, song5, music::MUSIC);
    music::insertVertex(library, song6, music::MUSIC);
    music::insertVertex(library, song7, music::MUSIC);

    music::insertVertex(library, song1, music::GENRE);
    music::insertVertex(library, song2, music::GENRE);
    music::insertVertex(library, song3, music::GENRE);
    music::insertVertex(library, song4, music::GENRE);
    music::insertVertex(library, song5, music::GENRE);
    music::insertVertex(library, song6, music::GENRE);
    music::insertVertex(library, song7, music::GENRE);

    music::insertVertex(library, song1, music::LANGUAGE);
    music::insertVertex(library, song2, music::LANGUAGE);
    music::insertVertex(library, song3, music::LANGUAGE);
    music::insertVertex(library, song4, music::LANGUAGE);
    music::insertVertex(library, song5, music::LANGUAGE);
    music::insertVertex(library, song6, music::LANGUAGE);
    music::insertVertex(library, song7, music::LANGUAGE);
}

int main() {
    user::List user{};
    user::createList(user);

    music::Graph library{};
    music::createGraph(library);

    queue::List queue{};
    queue::createList(queue);

    artists::List singer{};
    artists::createList(singer);

    singer_music::List singerMusic{};
    singer_music::createList(singerMusic);

    playlist::List playlist{};
    playlist::createList(playlist);

    playlist_music::List playlistMusic{};
    playlist_music::createList(playlistMusic);

    user_playlist::List userPlaylist{};
    user_playlist::createList(userPlaylist);

    insertMusic(library);

    bool exit = false;
    while (!exit) {
        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "WELCOME");
        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "1. Login as admin");
        printf("| %-96s |\n", "2. Login as user");
        printf("| %-96s |\n", "0. Quit program");
        printf("+%s+\n", string(98, '-').c_str());

        int key;
        cin >> key;

        switch (key) {
            case 1:
                admin_menu::home(
                    library,
                    singer,
                    singerMusic,
                    user,
                    userPlaylist,
                    playlistMusic);
                break;
            case 2:
                user_menu::home(
                    user,
                    library,
                    playlist,
                    playlistMusic,
                    userPlaylist,
                    singerMusic,
                    singer);
                break;
            case 0:
                exit = true;
                break;
            default:
                printf("+%s+\n", string(98, '-').c_str());
                printf("| %-96s |\n", "Pick one option!");
                printf("+%s+\n", string(98, '-').c_str());
        }
    }

    return 0;
}
