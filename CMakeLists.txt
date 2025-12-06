cmake_minimum_required(VERSION 4.0)
project(tubes_std)

set(CMAKE_CXX_STANDARD 20)

add_executable(tubes_std main.cpp
        Lagu.cpp
        Lagu.h
        Antrean.cpp
        Antrean.h
        Playlist.cpp
        Playlist.h
        User.cpp
        User.h
        Penyanyi.h
        Penyanyi.cpp
        RelasiPlaylist.cpp
        RelasiPlaylist.h
        RelasiUser.cpp
        RelasiUser.h
        RelasiPenyanyi.cpp
        RelasiPenyanyi.h)
