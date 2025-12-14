cmake_minimum_required(VERSION 4.0)
project(tubes_std)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(tubes_std main.cpp
        sources/Music.cpp
        headers/Music.h
        sources/Queue.cpp
        headers/Queue.h
        sources/artists.cpp
        headers/artists.h
        sources/SingerMusic.cpp
        headers/SingerMusic.h
        sources/User.cpp
        headers/User.h
        sources/Playlist.cpp
        headers/Playlist.h
        sources/PlaylistMusic.cpp
        headers/PlaylistMusic.h
        sources/UserPlaylist.cpp
        headers/UserPlaylist.h
        headers/AdminMenu.h
        sources/AdminMenu.cpp
        headers/UserMenu.h
        sources/UserMenu.cpp
)

target_link_libraries(tubes_std PRIVATE SFML::Audio)