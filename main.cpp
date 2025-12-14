#include <iostream>

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
