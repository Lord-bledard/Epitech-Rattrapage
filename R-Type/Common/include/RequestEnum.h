#ifndef R_TYPE_REQUESTENUM_H
#define R_TYPE_REQUESTENUM_H

enum RequestType {
    UNKNOWN,
    INIT_GAME,
    END_GAME,
    LIST_GAMES,
    RESPONSE_LIST_GAME, /* todo maybe split request and response enums ? */
    GAME_STATE,
    STOP,
    CLIENT_ACTION
};

#endif //R_TYPE_REQUESTENUM_H
