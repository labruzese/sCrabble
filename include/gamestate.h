#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "bag.h"
#include "board.h"
#include "player.h"

#define MAX_PLAYERS 6

typedef struct _gamestate {
    Board *board;
    Bag *bag;
    int turn_num;
    int pass_count;
    int player_count;
    Player players[MAX_PLAYERS];
} Gamestate;

#endif /* end of include guard: GAMESTATE_H */
