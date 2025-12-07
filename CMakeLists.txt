cmake_minimum_required(VERSION 4.0)
project(tubes_std)

set(CMAKE_CXX_STANDARD 20)

add_executable(tubes_std main.cpp
        sources/Lagu.cpp
        headers/Lagu.h
        sources/Antrean.cpp
        headers/Antrean.h
        sources/Playlist.cpp
        headers/Playlist.h
        sources/User.cpp
        headers/User.h
        headers/Penyanyi.h
        sources/Penyanyi.cpp
        sources/RelasiPlaylistLagu.cpp
        headers/RelasiPlaylistLagu.h
        sources/RelasiUserPlaylist.cpp
        headers/RelasiUserPlaylist.h
        sources/RelasiPenyanyiLagu.cpp
        headers/RelasiPenyanyiLagu.h
)
