#ifndef TUBES_STD_USERMENU_H
#define TUBES_STD_USERMENU_H

#include <iostream>

#include "ADT.h"

#include <SFML/Audio.hpp>

using namespace std;

namespace user_menu {
    enum UserOption {
        QUIT,
        DEQUEUE,
        CLEAR_QUEUE,
        MUSIC_LIBRARY,
        PLAYLIST_COLLECTION,
    };

    enum OptionMusic {
        M_QUIT,
        M_PLAY,
        M_PAUSE,
        M_PREV,
        M_NEXT,
        M_ENQUEUE_ALL,
        M_ENQUEUE_ONE,
        M_ENQUEUE_GENRE,
        M_ENQUEUE_LANGUAGE,
        M_ENQUEUE_ARTIST,
        M_SHUFFLE_QUEUE,
        M_DEQUEUE,
        M_CLEAR_QUEUE,
    };

    enum OptionPlaylist {
        P_QUIT,
        P_PLAY,
        P_PAUSE,
        P_PREV,
        P_NEXT,
        P_ENQUEUE,
        P_NEW,
        P_EDIT,
        P_REMOVE,
    };

    enum OptionPlaylistUpdate {
        PU_QUIT,
        PU_SET_TITLE,
        PU_ADD_MUSIC,
        PU_REMOVE_MUSIC,
    };

    /**
     * i.s. daftar user terdefinisi, activeUser dan back mungkin belum diinisialisasi.
     *
     * f.s. jika login berhasil, activeUser diisi dengan address user yang sesuai; jika pengguna memilih kembali, back diset true.
     * @param users daftar user yang akan diperiksa.
     * @param activeUser address user aktif yang akan diubah ketika login berhasil.
     * @param back flag untuk kembali ke menu sebelumnya.
     */
    void login(user::List &users, user::addr &activeUser, bool &back);

    /**
     * i.s. daftar user terdefinisi.
     *
     * f.s. user baru ditambahkan ke daftar users bila pendaftaran sukses.
     * @param users daftar user yang akan ditambahkan.
     */
    void signup(user::List &users);

    /**
     * i.s. users, library, playlists, playlistMusic, userPlaylist, singerMusic, dan artists terdefinisi.
     *
     * f.s. menampilkan menu home untuk navigasi fitur pengguna; prosedur dapat memanggil sub-prosedur lain dan mengubah state (mis. currentSong atau queue) sesuai aksi pengguna.
     * @param users daftar user.
     * @param library graf koleksi musik.
     * @param playlists daftar playlist.
     * @param playlistMusic relasi playlist-music.
     * @param userPlaylist relasi user-playlist.
     * @param singerMusic relasi singer-music.
     * @param artists daftar artis.
     */
    void home(user::List &users, music::Graph library, playlist::List &playlists,
              playlist_music::List &playlistMusic, user_playlist::List &userPlaylist, singer_music::List &singerMusic,
              artists::List artists);

    /**
     * i.s. library, currentSong, musicQueue, singers, singerMusic, dan music terdefinisi.
     *
     * f.s. menampilkan koleksi musik dan mengizinkan kontrol pemutaran; currentSong dan musicQueue dapat diubah sesuai aksi (enqueue/dequeue/play/pause dll.).
     * @param library graf koleksi musik.
     * @param currentSong address lagu yang sedang/akan diputar.
     * @param musicQueue antrian musik pengguna yang dapat dimodifikasi.
     * @param singers daftar artis.
     * @param singerMusic relasi singer-music.
     * @param music objek sf::Music yang dikontrol untuk pemutaran.
     */
    void musicCollection(music::Graph library, queue::addr &currentSong, queue::List &musicQueue,
                         artists::List &singers, singer_music::List &singerMusic, sf::Music &music);

    /**
     * i.s. activeUser, currentSong, musicQueue, library, playlists, playlistMusic, userPlaylist, dan music terdefinisi.
     *
     * f.s. menampilkan daftar playlist milik user dan menyediakan opsi pemutaran atau pengelolaan playlist; prosedur dapat mengubah currentSong, musicQueue, dan data playlist sesuai aksi pengguna.
     * @param activeUser user yang sedang aktif.
     * @param currentSong address lagu yang sedang/akan diputar.
     * @param musicQueue antrian musik yang dapat dimodifikasi.
     * @param library graf koleksi musik.
     * @param playlists daftar playlist.
     * @param playlistMusic relasi playlist-music.
     * @param userPlaylist relasi user-playlist.
     * @param music objek sf::Music yang dikontrol untuk pemutaran.
     */
    void listPlaylist(user::addr activeUser, queue::addr &currentSong, queue::List &musicQueue, music::Graph library,
                      playlist::List &playlists, playlist_music::List &playlistMusic, user_playlist::List &userPlaylist,
                      sf::Music &music);

    /**
     * i.s. ePlaylist, library, dan playlistMusic terdefinisi.
     *
     * f.s. memungkinkan perubahan pada ePlaylist (judul, penambahan/penghapusan musik) dan memperbarui playlistMusic sesuai perubahan.
     * @param ePlaylist address playlist yang akan diubah.
     * @param library graf koleksi musik.
     * @param playlistMusic relasi playlist-music yang mungkin diperbarui.
     */
    void updatePlaylist(playlist::addr &ePlaylist, music::Graph library, playlist_music::List &playlistMusic);
}

#endif //TUBES_STD_USERMENU_H
