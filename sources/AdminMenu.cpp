#include <iostream>
#include "../headers/AdminMenu.h"

#include "../headers/Music.h"
#include "../headers/Queue.h"
#include "../headers/Artists.h"
#include "../headers/PlaylistMusic.h"
#include "../headers/SingerMusic.h"
#include "../headers/User.h"
#include "../headers/UserPlaylist.h"

using namespace std;

namespace admin_menu {
    void home(music::Graph &library, artists::List &artists, singer_music::List &artistMusic, user::List &user,
              user_playlist::List &userPlaylist, playlist_music::List &playlistMusic) {
        bool back = false;
        while (!back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "ADMIN PAGE");
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", (to_string(MUSIC_LIBRARY) + ". Music library").c_str());
            printf("| %-96s |\n", (to_string(LIST_ARTISTS) + ". Artists ").c_str());
            printf("| %-96s |\n", (to_string(LIST_USERS) + ". Users").c_str());
            printf("| %-96s |\n", (to_string(QUIT) + ". Logout").c_str());

            int ipt;
            cin >> ipt;

            switch (ipt) {
                case MUSIC_LIBRARY:
                    listLibrary(library, artists, artistMusic, playlistMusic);
                    break;
                case LIST_ARTISTS:
                    listSinger(library, artists, artistMusic, playlistMusic);
                    break;
                case LIST_USERS:
                    listUser(user, userPlaylist);
                    break;
                case QUIT:
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

    void listLibrary(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic) {
        bool back = false;
        while (!back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "MUSIC LIBRARY");
            printf("+%s+\n", string(98, '-').c_str());

            music::display(library);

            printf("| %-96s |\n", (to_string(L_INESRT) + ". Insert new music").c_str());
            printf("| %-96s |\n", (to_string(L_UPDATE) + ". Update a music").c_str());
            printf("| %-96s |\n", (to_string(L_DELETE) + ". Delete a music").c_str());
            printf("| %-96s |\n", (to_string(L_QUIT) + ". Go back").c_str());
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            switch (ipt) {
                case L_INESRT:
                    insertMusic(library, artists, artistMusic);
                    break;
                case L_UPDATE:
                    if (!music::isEmpty(library)) updateMusic(library, artists, artistMusic);
                    else {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music library is empty!");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    break;
                case L_DELETE:
                    if (!music::isEmpty(library)) deleteMusic(library, artists, artistMusic, playlistMusic);
                    else {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "Music library is empty!");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    break;
                case L_QUIT:
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

    void insertMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic) {
        music::Infotype info;
        bool confirmed = false;

        while (!confirmed) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "INSERT NEW SONG");
            printf("+%s+\n", string(98, '-').c_str());

            cout << "> title: ";
            cin >> info.title;
            cout << "> duration: ";
            cin >> info.duration;
            cout << "> artists: ";
            cin >> info.artist;
            cout << "> genre: ";
            cin >> info.genre;
            cout << "> language: ";
            cin >> info.language;
            cout << "> file path: ";
            cin >> info.filePath;

            try {
                sf::SoundBuffer buffer(info.filePath);
            } catch (sf::Exception e) {
                printf("+%s+\n", string(98, '-').c_str());
                printf("| %-96s |\n", "File is either corrupted or cannot be opened!");
                printf("+%s+\n", string(98, '-').c_str());
                continue;
            }

            printf("+%s+\n", string(98, '-').c_str());
            printf("| 1. %-93s |\n", "Confirm");
            printf("| 2. %-93s |\n", "I made a mistake");
            printf("| 0. %-93s |\n", "Cancel");
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
            }
        }

        music::addr eMusic = music::allocateVertex(info);

        music::insertVertex(library, eMusic, music::MUSIC);
        music::insertVertex(library, eMusic, music::GENRE);
        music::insertVertex(library, eMusic, music::LANGUAGE);

        artists::addr eArtist = artists::find(artists, info.artist);
        if (eArtist == nullptr) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "This song's artist is unregistered!");
            printf("+%s+\n", string(98, '-').c_str());

            int debut;
            cout << "> Debut year: ";
            cin >> debut;

            eArtist = artists::allocateElm({info.artist, debut});
            artists::insertLast(artists, eArtist);
        }
        singer_music::addr eSingerMusic = singer_music::allocateElm(eMusic, eArtist);
        singer_music::insertLast(artistMusic, eSingerMusic);

        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "New music is added!");
        printf("+%s+\n", string(98, '-').c_str());
    }

    void updateMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic) {
        music::addr eMusic = nullptr;
        string title = "";

        cout << "> Music title: " << endl;
        cin >> title;
        eMusic = music::find(library, title);
        if (eMusic == nullptr) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Title not found!");
            printf("+%s+\n", string(98, '-').c_str());
            return;
        }

        bool confirmed = false;
        while (!confirmed) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "UPDATE MUSIC");
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", (to_string(UM_TITLE) + ". To update title").c_str());
            printf("| %-96s |\n", (to_string(UM_DURATION) + ". To update duration").c_str());
            printf("| %-96s |\n", (to_string(UM_SINGER) + ". To update artists").c_str());
            printf("| %-96s |\n", (to_string(UM_GENRE) + ". To update genre").c_str());
            printf("| %-96s |\n", (to_string(UM_LANGUAGE) + ". To update language").c_str());
            printf("| %-96s |\n", (to_string(UM_FILE_PATH) + ". To update file path").c_str());
            printf("| %-96s |\n", (to_string(UM_NONE) + ". To update nothing else").c_str());
            printf("+%s+\n", string(98, '-').c_str());

            int ipt;
            cin >> ipt;

            artists::addr eArtist;
            int debut;
            singer_music::addr sm;

            cout << "> Your update: ";
            switch (ipt) {
                case UM_TITLE:
                    cin >> eMusic->info.title;
                    break;
                case UM_DURATION:
                    cin >> eMusic->info.duration;
                    break;
                case UM_SINGER:
                    eArtist = artists::find(artists, eMusic->info.artist);
                    if (eArtist != nullptr) sm = singer_music::find(artistMusic, eArtist, eMusic);
                    if (eArtist != nullptr && sm != nullptr) {
                        singer_music::remove(artistMusic, sm);
                        if (queue::isEmpty(singer_music::listMusic(artistMusic, eArtist))) {
                            artists::remove(artists, eArtist, artistMusic);
                        }
                    }

                    cin >> eMusic->info.artist;
                    eArtist = artists::find(artists, eMusic->info.artist);
                    if (eArtist == nullptr) {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "This song's artist is unregistered!");
                        printf("+%s+\n", string(98, '-').c_str());

                        cout << "> Debut year: ";
                        cin >> debut;

                        eArtist = artists::allocateElm({eMusic->info.title, debut});
                        artists::insertLast(artists, eArtist);
                    }

                    sm = singer_music::allocateElm(eMusic, eArtist);
                    singer_music::insertLast(artistMusic, sm);
                    break;
                case UM_GENRE:
                    music::deleteVertex(library, eMusic, music::GENRE);
                    cin >> eMusic->info.genre;
                    music::insertVertex(library, eMusic, music::GENRE);
                    break;
                case UM_LANGUAGE:
                    music::deleteVertex(library, eMusic, music::LANGUAGE);
                    cin >> eMusic->info.language;
                    music::insertVertex(library, eMusic, music::LANGUAGE);
                    break;
                case UM_FILE_PATH:
                    cin >> eMusic->info.filePath;
                    break;
                case UM_NONE:
                    confirmed = true;
                    break;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
                    break;
            }
        }
    }

    void deleteMusic(music::Graph &library, artists::List &artists, singer_music::List &artistMusic,
                     playlist_music::List &playlistMusic) {
        music::addr eMusic = nullptr;
        string title = "";
        cout << "> Music title: ";
        cin >> title;
        eMusic = music::find(library, title);
        if (eMusic == nullptr) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Title not found!");
            printf("+%s+\n", string(98, '-').c_str());
            return;
        }

        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "Are you sure to delete this music?");
        printf("+%s+\n", string(98, '-').c_str());
        printf("| 1. %-93s |\n", "Confirm");
        printf("| 0. %-93s |\n", "Cancel");
        printf("+%s+\n", string(98, '-').c_str());

        int ipt;
        cin >> ipt;
        if (ipt == 1) {
            artists::addr eArtist = artists::find(artists, eMusic->info.artist);
            singer_music::addr eSingerMusic = singer_music::find(artistMusic, eArtist, eMusic);
            singer_music::remove(artistMusic, eSingerMusic);

            playlist_music::removeMusic(playlistMusic, eMusic);

            if (queue::isEmpty(singer_music::listMusic(artistMusic, eArtist))) {
                artists::remove(artists, eArtist, artistMusic);
            }

            music::deleteVertex(library, eMusic, music::GENRE);
            music::deleteVertex(library, eMusic, music::LANGUAGE);
            music::deleteVertex(library, eMusic, music::MUSIC);

            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Music is deleted!");
            printf("+%s+\n", string(98, '-').c_str());
        } else {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Understandable");
            printf("+%s+\n", string(98, '-').c_str());
        }
    }

    void listSinger(music::Graph &music, artists::List &artists, singer_music::List &artistMusic,
                    playlist_music::List &playlistMusic) {
        bool back = false;
        while (!back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "ARTISTS");
            printf("+%s+\n", string(98, '-').c_str());

            artists::display(artists);

            printf("| %-96s |\n", (to_string(A_DELETE) + ". Delete an artists").c_str());
            printf("| %-96s |\n", (to_string(A_QUIT) + ". Go back").c_str());

            int ipt;
            cin >> ipt;

            switch (ipt) {
                case A_DELETE:
                    if (!artists::isEmpty(artists)) deleteSinger(music, artists, artistMusic, playlistMusic);
                    else {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "There are no registered artist!");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                    break;
                case A_QUIT:
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

    void deleteSinger(music::Graph &music, artists::List &artists, singer_music::List &artistMusic,
                      playlist_music::List &playlistMusic) {
        artists::addr eArtist = nullptr;
        string name = "";
        cout << "> Artist's name: ";
        cin >> name;

        eArtist = artists::find(artists, name);
        if (eArtist == nullptr) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Artist not found!");
            printf("+%s+\n", string(98, '-').c_str());
            return;
        }

        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "Are you sure to delete this artist?");
        printf("+%s+\n", string(98, '-').c_str());
        printf("| 1. %-93s |\n", "Confirm");
        printf("| 0. %-93s |\n", "Cancel");
        printf("+%s+\n", string(98, '-').c_str());

        int ipt;
        cin >> ipt;

        if (ipt == 1) {
            queue::List q = singer_music::listMusic(artistMusic, eArtist);
            if (!queue::isEmpty(q)) {
                queue::addr qElm = q.first;
                while (qElm != nullptr) {
                    music::deleteVertex(music, qElm->music, music::MUSIC);
                    music::deleteVertex(music, qElm->music, music::GENRE);
                    music::deleteVertex(music, qElm->music, music::LANGUAGE);

                    playlist_music::removeMusic(playlistMusic, qElm->music);
                    qElm = qElm->next;
                }
            }
            artists::remove(artists, eArtist, artistMusic);

            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Artist is deleted");
            printf("+%s+\n", string(98, '-').c_str());
        } else {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Understandable");
            printf("+%s+\n", string(98, '-').c_str());
        }
    }

    void listUser(user::List &user, user_playlist::List &userPlaylist) {
        bool back = false;
        while (!back) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "USERS");
            printf("+%s+\n", string(98, '-').c_str());

            user::list(user);

            printf("| %-96s |\n", (to_string(U_DELETE) + ". Delete a user").c_str());
            printf("| %-96s |\n", (to_string(U_QUIT) + ". Go back").c_str());

            int ipt;
            cin >> ipt;

            switch (ipt) {
                case U_DELETE:
                    if (!user::isEmpty(user))deleteUser(user, userPlaylist);
                    else {
                        printf("+%s+\n", string(98, '-').c_str());
                        printf("| %-96s |\n", "There are no registered user!");
                        printf("+%s+\n", string(98, '-').c_str());
                        break;
                    }
                case U_QUIT:
                    back = true;
                default:
                    printf("+%s+\n", string(98, '-').c_str());
                    printf("| %-96s |\n", "Pick one option!");
                    printf("+%s+\n", string(98, '-').c_str());
                    break;
            }
        }
    }

    void deleteUser(user::List &user, user_playlist::List &userPlaylist) {
        user::addr eUser = nullptr;
        string username = "";
        cout << "> User's username: ";
        cin >> username;

        eUser = user::findAdmin(user, username);
        if (eUser == nullptr) {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "User not found!");
            printf("+%s+\n", string(98, '-').c_str());
            return;
        }

        printf("+%s+\n", string(98, '-').c_str());
        printf("| %-96s |\n", "Are you sure to delete this user?");
        printf("+%s+\n", string(98, '-').c_str());
        printf("| 1. %-93s |\n", "Confirm");
        printf("| 0. %-93s |\n", "Cancel");
        printf("+%s+\n", string(98, '-').c_str());

        int ipt;
        cin >> ipt;

        if (ipt == 1) {
            user::remove(user, eUser, userPlaylist);

            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "User is deleted");
            printf("+%s+\n", string(98, '-').c_str());
        } else {
            printf("+%s+\n", string(98, '-').c_str());
            printf("| %-96s |\n", "Understandable");
            printf("+%s+\n", string(98, '-').c_str());
        }
    }
}
