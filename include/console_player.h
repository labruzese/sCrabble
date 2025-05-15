#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include "board.h"
#include "hand.h"
#include "move.h"

int console_player_get_move(Move *move, Hand *hand);

bool console_player_update_board(Board *board);

bool console_player_update_hand(Hand *hand);

#endif /* end of include guard: HUMAN_H */
