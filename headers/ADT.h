#ifndef TUBES_STD_ADT_H
#define TUBES_STD_ADT_H

#include <iostream>

using namespace std;

namespace song {
    typedef struct Vertex *addr;
    typedef struct Edge *edge;

    struct Edge {
        addr vertex;
        edge next;
    };

    struct Infotype {
        string title;
        string singer;
        string album;
        int duration;
        string genre;
        string language;
    };

    struct Vertex {
        Infotype info;
        edge next_song;
        edge next_genre;
        edge next_language;
    };

    struct Graph {
        addr first;
    };
}

namespace antrean {
    typedef struct Elm *addr;

    struct Elm {
        song::addr lagu;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

#endif //TUBES_STD_ADT_H
