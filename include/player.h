#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "move.h"
#include <stdbool.h>

typedef int (*MoveFunction)(Move *move, Hand *hand);
typedef bool (*BoardUpdateFunction)(Board *currentBoard);
typedef bool (*HandUpdateFunction)(Hand *currentHand);

typedef struct _player {
    char *name;
    int score;
    MoveFunction mfunc;
    BoardUpdateFunction bufunc;
    HandUpdateFunction hufunc;
} Player;

#endif /* end of include guard: PLAYER_H */
