#ifndef TUBES_STD_ADT_H
#define TUBES_STD_ADT_H

#include <iostream>

using namespace std;

namespace music {
    enum Category {
        MUSIC,
        GENRE,
        LANGUAGE
    };

    typedef struct Vertex *addr;
    typedef struct Edge *edge;

    struct Edge {
        addr vertex;
        edge next;
    };

    struct Infotype {
        string title;
        string artist;
        string album;
        int duration;
        string genre;
        string language;
        string filePath;
    };

    struct Vertex {
        Infotype info;
        edge nextMusic;
        edge nextGenre;
        edge nextLanguage;
    };

    struct Graph {
        addr first;
    };
}

namespace queue {
    typedef struct Elm *addr;

    struct Elm {
        music::addr music;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace artists {
    typedef struct Elm *addr;

    struct Infotype {
        string name;
        int debutYear;
    };

    struct Elm {
        Infotype info;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace playlist {
    typedef struct Elm *addr;

    struct Elm {
        string title;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace user {
    typedef struct Elm *addr;

    struct Infotype {
        string username;
        string password;
        string fullName;
    };

    struct Elm {
        Infotype info;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace singer_music {
    typedef struct Elm *addr;

    struct Elm {
        music::addr music;
        artists::addr singer;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace playlist_music {
    typedef struct Elm *addr;

    struct Elm {
        playlist::addr playlist;
        music::addr music;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

namespace user_playlist {
    typedef struct Elm *addr;

    struct Elm {
        user::addr user;
        playlist::addr playlist;
        addr next;
        addr prev;
    };

    struct List {
        addr first;
        addr last;
    };
}

#endif //TUBES_STD_ADT_H
