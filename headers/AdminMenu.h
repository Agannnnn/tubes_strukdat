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

    /**
     * i.s. library, artists, artistMusic, user, userPlaylist, dan playlistMusic terdefinisi.
     *
     * f.s. menampilkan menu admin untuk navigasi fitur administrasi; prosedur dapat memanggil sub-prosedur lain
     * sesuai pilihan admin.
     * @param library graf koleksi musik yang dapat dikelola.
     * @param artists daftar artis yang dapat dikelola.
     * @param artistMusic relasi singer-music yang dapat diperbarui.
     * @param user daftar user yang dapat dikelola.
     * @param userPlaylist relasi user-playlist yang dapat diperbarui.
     * @param playlistMusic relasi playlist-music yang dapat diperbarui.
     */
    void home(music::Graph &library, artists::List &artists, singer_music::List &artistMusic, user::List &user,
              user_playlist::List &userPlaylist, playlist_music::List &playlistMusic);

    /**
     * i.s. library, artists, artistMusic, dan playlistMusic terdefinisi.
     *
     * f.s. menampilkan koleksi musik dan menyediakan opsi pengelolaan musik (insert/update/delete); data musik dapat
     * diubah sesuai aksi admin.
     * @param library graf koleksi musik yang akan dikelola.
     * @param artists daftar artis yang dapat diperbarui.
     * @param artistMusic relasi singer-music yang dapat diperbarui.
     * @param playlistMusic relasi playlist-music yang dapat diperbarui.
     */
    void listLibrary(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic);

    /**
     * i.s. library, artists, dan artistMusic terdefinisi.
     *
     * f.s. musik baru ditambahkan ke library; jika artis belum terdaftar, artis baru dibuat; relasi singer-music
     * dibuat.
     * @param library graf koleksi musik yang akan ditambahi.
     * @param artists daftar artis yang mungkin bertambah.
     * @param artistMusic relasi singer-music yang akan bertambah.
     */
    void insertMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic);

    /**
     * i.s. library, artists, dan artistMusic terdefinisi.
     *
     * f.s. data musik yang dipilih diperbarui sesuai pilihan admin; relasi singer-music dapat berubah jika
     * artis diubah.
     * @param library graf koleksi musik yang akan diperbarui.
     * @param artists daftar artis yang mungkin berubah.
     * @param artistMusic relasi singer-music yang mungkin berubah.
     */
    void updateMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic);

    /**
     * i.s. library, artists, artistMusic, dan playlistMusic terdefinisi.
     *
     * f.s. musik yang dipilih dihapus dari library; jika artis tidak memiliki lagu lain, artis ikut dihapus;
     * semua relasi terkait dihapus.
     * @param library graf koleksi musik yang akan dikurangi.
     * @param artists daftar artis yang mungkin berkurang.
     * @param artistMusic relasi singer-music yang akan diperbarui.
     * @param playlistMusic relasi playlist-music yang akan diperbarui.
     */
    void deleteMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic);

    /**
     * i.s. library, artists, artistMusic, dan playlistMusic terdefinisi.
     *
     * f.s. menampilkan daftar artis dan menyediakan opsi penghapusan artis; data artis dapat berkurang sesuai
     * aksi admin.
     * @param library graf koleksi musik yang mungkin berubah.
     * @param artists daftar artis yang akan ditampilkan dan mungkin berkurang.
     * @param artistMusic relasi singer-music yang mungkin berubah.
     * @param playlistMusic relasi playlist-music yang mungkin berubah.
     */
    void listSinger(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                    playlist_music::List &playlistMusic);

    /**
     * i.s. library, artists, artistMusic, dan playlistMusic terdefinisi.
     *
     * f.s. artis yang dipilih dihapus beserta semua lagu dan relasi terkait; musik artis tersebut ikut dihapus
     * dari library.
     * @param library graf koleksi musik yang akan dikurangi.
     * @param artists daftar artis yang akan berkurang.
     * @param artistMusic relasi singer-music yang akan berkurang.
     * @param playlistMusic relasi playlist-music yang akan diperbarui.
     */
    void deleteSinger(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                      playlist_music::List &playlistMusic);

    /**
     * i.s. user dan userPlaylist terdefinisi.
     *
     * f.s. menampilkan daftar user dan menyediakan opsi penghapusan user; data user dapat berkurang sesuai aksi admin.
     * @param user daftar user yang akan ditampilkan dan mungkin berkurang.
     * @param userPlaylist relasi user-playlist yang mungkin berubah.
     */
    void listUser(user::List &user, user_playlist::List &userPlaylist);

    /**
     * i.s. user dan userPlaylist terdefinisi.
     *
     * f.s. user yang dipilih dihapus beserta semua relasi user-playlist terkait.
     * @param user daftar user yang akan berkurang.
     * @param userPlaylist relasi user-playlist yang akan berkurang.
     */
    void deleteUser(user::List &user, user_playlist::List &userPlaylist);
}

#endif //TUBES_STD_ADMINMENU_H
