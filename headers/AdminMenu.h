#ifndef TUBES_STD_ADMINMENU_H
#define TUBES_STD_ADMINMENU_H

#include <iostream>
#include "ADT.h"

using namespace std;

namespace admin_menu {
    enum AdminOption {
        QUIT,
        MUSIC_LIBRARY,
        LIST_ARTISTS,
        LIST_USERS,
    };

    enum OptionLibrary {
        L_QUIT,
        L_INESRT,
        L_UPDATE,
        L_DELETE,
    };

    enum OptionArtist {
        A_QUIT,
        A_DELETE,
    };

    enum OptionUpdateMusic {
        UM_NONE,
        UM_TITLE,
        UM_DURATION,
        UM_SINGER,
        UM_GENRE,
        UM_LANGUAGE,
        UM_FILE_PATH,
    };

    enum OptionUser {
        U_QUIT,
        U_DELETE,
    };

    void home(music::Graph &library, artists::List &artists, singer_music::List &artistMusic, user::List &user,
              user_playlist::List &userPlaylist, playlist_music::List &playlistMusic);

    void listLibrary(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic);

    void insertMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic);

    void updateMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic);

    void deleteMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic);

    void listSinger(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                    playlist_music::List &playlistMusic);

    void deleteSinger(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                      playlist_music::List &playlistMusic);

    void listUser(user::List &user, user_playlist::List &userPlaylist);

    void deleteUser(user::List &user, user_playlist::List &userPlaylist);
}

#endif //TUBES_STD_ADMINMENU_H
