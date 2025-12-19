#include "../headers/UserMenu.h"

#include <iostream>
#include <thread>

#include <SFML/Audio.hpp>

#include "../headers/Music.h"
#include "../headers/Playlist.h"
#include "../headers/PlaylistMusic.h"
#include "../headers/Queue.h"
#include "../headers/Artists.h"
#include "../headers/SingerMusic.h"
#include "../headers/User.h"
#include "../headers/UserPlaylist.h"

using namespace std;

namespace user_menu {
    void login(user::List &users, user::addr &activeUser, bool &back) {
        while (activeUser == nullptr && !back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "LOGIN");
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "1. Login");
            printf("| %-96s |\n", "2. Signup");
            printf("| %-96s |\n", "0. Go Back");
            printf("+%s+\n", string(98, '-').c_str());

            int key;
            cin >> key;

            string username, password;
            switch (key) {
                case 0:
                    back = true;
                    break;
                case 1:
                    cout << "> Username: ";
                    cin >> username;
                    cout << "> Password: ";
                    cin >> password;

                    activeUser = user::find(users, username, password);
                    if (activeUser == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "User not found");
                        printf("+%s+\n", string(98, '-').c_str());
                    }
                    break;
                case 2:
                    signup(users);
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
                    break;
            }
        }
    }

    void signup(user::List &users) {
        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "SIGNUP");
        printf("+%s+\n", string(98, '-').c_str());

        user::Infotype info;
        bool confirmed = false;
        while (!confirmed) {
            cout << "> Username: ";
            cin >> info.username;
            cout << "> Password: ";
            cin >> info.password;
            cout << "> Full name: ";
            cin >> info.fullName;

            if (user::findAdmin(users, info.username)) {
                cout << "this username is taken" << endl;
                continue;;
            }

            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "ARE YOU SURE?");
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "1. Confirm");
            printf("| %-96s |\n", "2. I made a mistake");
            printf("| %-96s |\n", "0. Cancel");
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            if (ipt == 0) {
                return;
            } else if (ipt == 1) {
                confirmed = true;
            } else if (ipt == 2) {
                continue;
            } else {
                printf("+%s+\n", string(98, '-').c_str());
                printf("| %-96s |\n", "Pick one option!");
                printf("+%s+\n", string(98, '-').c_str());
                break;
            }
        }

        user::addr user = user::allocateElm(info);
        user::insertLast(users, user);

        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "Registered a new user!");
        printf("+%s+\n", string(98, '-').c_str());
    }

    void home(user::List &users, music::Graph library, playlist::List &playlists, playlist_music::List &playlistMusic,
              user_playlist::List &userPlaylist, singer_music::List &singerMusic, artists::List artists) {
        user::addr activeUser = nullptr;
        queue::List musicQueue;
        queue::addr currentSong = nullptr;
        sf::Music music;

        bool back = false;

        while (!back) {
            if (activeUser == nullptr) {
                queue::createList(musicQueue);
                music.stop();
                login(users, activeUser, back);
                continue;
            }

            printf("+%s+\n", string(98, '-').c_str());
            printf("| WELCOME %-88s |\n", activeUser->info.fullName.c_str());
            printf("+%s+\n", string(98, '-').c_str());
            queue::display(musicQueue);
            printf("| %-96s |\n", (to_string(PLAY) + ". Play current music").c_str());
            printf("| %-96s |\n", (to_string(PAUSE) + ". Pause current music").c_str());
            printf("| %-96s |\n", (to_string(PREV) + ". Play prev music").c_str());
            printf("| %-96s |\n", (to_string(NEXT) + ". Play next music").c_str());
            printf("| %-96s |\n", (to_string(DEQUEUE) + ". Dequeue one music").c_str());
            printf("| %-96s |\n", (to_string(CLEAR_QUEUE) + ". Clear queue").c_str());
            printf("| %-96s |\n", (to_string(MUSIC_LIBRARY) + ". Music library").c_str());
            printf("| %-96s |\n", (to_string(PLAYLIST_COLLECTION) + ". Playlist collection").c_str());
            printf("| %-96s |\n", (to_string(QUIT) + ". Logout").c_str());
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            queue::addr eQueue = nullptr;
            string keyword = "";

            switch (ipt) {
                case PLAY:
                    if (queue::isEmpty(musicQueue)) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music queue is still empty");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (currentSong == nullptr || queue::find(musicQueue, currentSong->music->info.title) == nullptr) {
                        currentSong = musicQueue.first;
                    }
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case PAUSE:
                    music.pause();
                    break;
                case NEXT:
                    if (currentSong == nullptr) break;
                    if (currentSong->next == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the end of the queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->next;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case PREV:
                    if (currentSong == nullptr) break;
                    if (currentSong->prev == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the start of the queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->prev;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case DEQUEUE:
                    cout << "> Music title: ";
                    cin >> keyword;
                    eQueue = queue::find(musicQueue, keyword);
                    if (eQueue == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music queue is still empty");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (eQueue == currentSong) {
                        music.stop();
                    }
                    queue::remove(musicQueue, eQueue);
                    break;
                case CLEAR_QUEUE:
                    music.stop();
                    queue::clear(musicQueue);
                    break;
                case MUSIC_LIBRARY:
                    musicCollection(
                        library,
                        currentSong,
                        musicQueue,
                        artists,
                        singerMusic,
                        music);
                    break;
                case PLAYLIST_COLLECTION:
                    listPlaylist(
                        activeUser,
                        currentSong,
                        musicQueue,
                        library,
                        playlists,
                        playlistMusic,
                        userPlaylist,
                        music);
                    break;
                case QUIT:
                    activeUser = nullptr;
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
                    break;
            }
        }
    }

    void musicCollection(music::Graph library, queue::addr &currentSong, queue::List &musicQueue,
                         artists::List &singers, singer_music::List &singerMusic, sf::Music &music) {
        bool back = false;
        while (!back) {
            music::display(library);

            if (currentSong != nullptr && currentSong->prev != nullptr) {
                printf("| Prev: %-90s |\n", currentSong->prev->music->info.title.c_str());
            }
            if (currentSong != nullptr && currentSong->next != nullptr) {
                printf("| Next: %-90s |\n", currentSong->next->music->info.title.c_str());
            }
            if (currentSong != nullptr) {
                printf("| Current: %-87s |\n", currentSong->music->info.title.c_str());
                printf("+%s+\n", string(98, '-').c_str());
            }

            printf("| %-96s |\n", (to_string(M_PLAY) + ". Play current music").c_str());
            printf("| %-96s |\n", (to_string(M_PAUSE) + ". Pause playing music").c_str());
            printf("| %-96s |\n", (to_string(M_PREV) + ". Play prev music").c_str());
            printf("| %-96s |\n", (to_string(M_NEXT) + ". Play next music").c_str());
            printf("| %-96s |\n", (to_string(M_ENQUEUE_ALL) + ". Enqueue the whole library").c_str());
            printf("| %-96s |\n",
                   (to_string(M_ENQUEUE_ONE) + ". Find a song to enqueue right after current song").c_str());
            printf("| %-96s |\n", (to_string(M_ENQUEUE_GENRE) + ". Enqueue all music with similar genre").c_str());
            printf("| %-96s |\n",
                   (to_string(M_ENQUEUE_LANGUAGE) + ". Enqueue all music with similar language").c_str());
            printf("| %-96s |\n", (to_string(M_ENQUEUE_ARTIST) + ". Find an artist to enqueue their music").c_str());
            printf("| %-96s |\n", (to_string(M_SHUFFLE_QUEUE) + ". Shuffle current queue").c_str());
            printf("| %-96s |\n", (to_string(M_DEQUEUE) + ". Find one music to dequeue").c_str());
            printf("| %-96s |\n", (to_string(M_CLEAR_QUEUE) + ". Clear queue").c_str());
            printf("| %-96s |\n", (to_string(M_QUIT) + ". Go back").c_str());
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            queue::List musicList;
            queue::addr eQueue;
            music::addr eMusic;
            artists::addr eArtist;
            string keyword;
            thread tPlaying;

            switch (ipt) {
                case M_PLAY:
                    if (queue::isEmpty(musicQueue)) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music queue is still empty");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (currentSong == nullptr || queue::find(musicQueue, currentSong->music->info.title) == nullptr) {
                        currentSong = musicQueue.first;
                    }
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case M_PAUSE:
                    music.pause();
                    break;
                case M_NEXT:
                    if (currentSong == nullptr) break;
                    if (currentSong->next == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the end of the queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->next;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case M_PREV:
                    if (currentSong == nullptr) break;
                    if (currentSong->prev == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the start of the queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->prev;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case M_ENQUEUE_ALL:
                    if (music::isEmpty(library)) break;
                    musicList = music::listBy(library, library.first, music::MUSIC);
                    queue::joinQueue(musicQueue, musicList);
                    break;
                case M_ENQUEUE_ONE:
                    cout << "> Music title: ";
                    cin >> keyword;
                    eMusic = music::find(library, keyword);
                    if (eMusic == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Title not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    eQueue = queue::allocateElm(eMusic);
                    if (currentSong == nullptr) {
                        queue::insertLast(musicQueue, eQueue);
                    } else {
                        queue::insertAfter(musicQueue, eQueue, currentSong);
                    }
                    break;
                case M_ENQUEUE_GENRE:
                    if (music::isEmpty(library)) break;
                    musicList = music::listBy(library, library.first, music::GENRE);
                    queue::joinQueue(musicQueue, musicList);
                    break;
                case M_ENQUEUE_LANGUAGE:
                    if (music::isEmpty(library)) break;
                    musicList = music::listBy(library, library.first, music::LANGUAGE);
                    queue::joinQueue(musicQueue, musicList);
                    break;
                case M_ENQUEUE_ARTIST:
                    if (music::isEmpty(library)) break;
                    cout << "> Artist name: ";
                    cin >> keyword;
                    eArtist = artists::find(singers, keyword);
                    if (eArtist == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Artist not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    musicList = singer_music::listMusic(singerMusic, eArtist);
                    queue::joinQueue(musicQueue, musicList);
                    break;
                case M_SHUFFLE_QUEUE:
                    if (currentSong != nullptr) {
                        keyword = currentSong->music->info.title;
                        queue::shuffle(musicQueue);
                        currentSong = queue::find(musicQueue, keyword);
                    } else {
                        queue::shuffle(musicQueue);
                    }
                    break;
                case M_DEQUEUE:
                    cout << "> Music title: ";
                    cin >> keyword;
                    eQueue = queue::find(musicQueue, keyword);
                    if (eQueue == currentSong) {
                        music.stop();
                        if (currentSong != nullptr && currentSong->next != nullptr) {
                            currentSong = currentSong->next;
                            music = sf::Music(currentSong->music->info.filePath);
                        } else if (currentSong != nullptr && currentSong->prev != nullptr) {
                            currentSong = currentSong->prev;
                            music = sf::Music(currentSong->music->info.filePath);
                        } else {
                            currentSong = nullptr;
                        }
                    }
                    queue::remove(musicQueue, eQueue);
                    break;
                case M_CLEAR_QUEUE:
                    music.stop();
                    currentSong = nullptr;
                    queue::clear(musicQueue);
                    break;
                case M_QUIT:
                    back = true;
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
            }
        }
    }

    void listPlaylist(user::addr activeUser, queue::addr &currentSong, queue::List &musicQueue,
                      music::Graph library, playlist::List &playlists, playlist_music::List &playlistMusic,
                      user_playlist::List &userPlaylist, sf::Music &music) {
        bool back = false;

        while (!back) {
            user_playlist::displayPlaylist(userPlaylist, activeUser);

            if (currentSong != nullptr && currentSong->prev != nullptr) {
                printf("| Prev: %-90s |\n", currentSong->prev->music->info.title.c_str());
            }
            if (currentSong != nullptr && currentSong->next != nullptr) {
                printf("| Next: %-90s |\n", currentSong->next->music->info.title.c_str());
            }
            if (currentSong != nullptr) {
                printf("| Current: %-87s |\n", currentSong->music->info.title.c_str());
                printf("+%s+\n", string(98, '-').c_str());
            }

            printf("| %-96s |\n", (to_string(P_PLAY) + ". Play current music").c_str());
            printf("| %-96s |\n", (to_string(P_PAUSE) + ". Pause playing music").c_str());
            printf("| %-96s |\n", (to_string(P_PREV) + ". Play prev music").c_str());
            printf("| %-96s |\n", (to_string(P_NEXT) + ". Play next music").c_str());
            printf("| %-96s |\n", (to_string(P_ENQUEUE) + ". Enueue a playlists").c_str());
            printf("| %-96s |\n", (to_string(P_NEW) + ". Create new playlists").c_str());
            printf("| %-96s |\n", (to_string(P_EDIT) + ". Update playlists").c_str());
            printf("| %-96s |\n", (to_string(P_REMOVE) + ". Remove playlists").c_str());
            printf("| %-96s |\n", (to_string(P_QUIT) + ". Go back").c_str());
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            string keyword;
            playlist::addr ePlaylist;
            queue::List musicList;
            thread tPlaying;

            switch (ipt) {
                case P_PLAY:
                    if (queue::isEmpty(musicQueue)) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music queue is still empty");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (currentSong == nullptr || queue::find(musicQueue, currentSong->music->info.title) ==
                        nullptr) {
                        currentSong = musicQueue.first;
                    }
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case P_PAUSE:
                    music.pause();
                    break;
                case P_NEXT:
                    if (currentSong == nullptr) break;
                    if (currentSong->next == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the end of the music queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->next;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case P_PREV:
                    if (currentSong == nullptr) break;
                    if (currentSong->prev == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "It's the start of the music queue");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    music.stop();
                    currentSong = currentSong->prev;
                    music = sf::Music(currentSong->music->info.filePath);
                    music.play();
                    break;
                case P_ENQUEUE:
                    cout << "> Playlist name: ";
                    cin >> keyword;
                    ePlaylist = playlist::find(playlists, keyword);
                    if (ePlaylist == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Title not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    musicList = playlist_music::listMusic(playlistMusic, ePlaylist);
                    queue::joinQueue(musicQueue, musicList);
                    break;
                case P_NEW:
                    cout << "> Playlist name: ";
                    cin >> keyword;
                    ePlaylist = playlist::allocateElm(keyword);
                    playlist::insertLast(playlists, ePlaylist, activeUser, userPlaylist);
                    break;
                case P_EDIT:
                    cout << "> Playlist name: ";
                    cin >> keyword;
                    ePlaylist = playlist::find(playlists, keyword);
                    if (ePlaylist == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Playlist not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (user_playlist::findUser(userPlaylist, ePlaylist) != activeUser) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Playlist not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    updatePlaylist(ePlaylist, library, playlistMusic);
                    break;
                case P_REMOVE:
                    cout << "> Playlist name: ";
                    cin >> keyword;
                    ePlaylist = playlist::find(playlists, keyword);
                    if (ePlaylist == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Title not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    if (user_playlist::findUser(userPlaylist, ePlaylist) != activeUser) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Playlist not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    playlist::remove(playlists, ePlaylist, playlistMusic, userPlaylist);
                    break;
                case P_QUIT:
                    back = true;
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
                    break;
            }
        }
    }

    void updatePlaylist(playlist::addr &ePlaylist, music::Graph library, playlist_music::List &playlistMusic) {
        bool back = false;
        int ipt;

        while (!back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", ("PLAYLIST " + ePlaylist->title).c_str());

            queue::display(playlist_music::listMusic(playlistMusic, ePlaylist));


            printf("| %-96s |\n", "1. Set title");
            printf("| %-96s |\n", "2. Insert song");
            printf("| %-96s |\n", "3. Remove song");
            printf("| %-96s |\n", "0. Go back");
            printf("+%s+\n", string(98, '-').c_str());

            string keyword;
            music::addr eMusic;
            playlist_music::addr ePlaylistMusic;

            cin >> ipt;
            switch (ipt) {
                case 1:
                    cout << "> Playlist name: ";
                    cin >> ePlaylist->title;
                    break;
                case 2:
                    music::display(library);
                    cout << "> Music title: ";
                    cin >> keyword;
                    eMusic = music::find(library, keyword);
                    if (eMusic == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Title not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    ePlaylistMusic = playlist_music::allocateElm(ePlaylist, eMusic);
                    playlist_music::insertLast(playlistMusic, ePlaylistMusic);
                    break;
                case 3:
                    cout << "> Music title: ";
                    cin >> keyword;
                    eMusic = music::find(library, keyword);
                    if (eMusic == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Title not found");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    playlist_music::removeMusic(playlistMusic, eMusic);
                    break;
                case 0:
                    back = true;
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
            }
        }
    }
}
