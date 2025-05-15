#ifndef MOVE_H
#define MOVE_H

#include "hand.h"
#include <stddef.h>

typedef enum direction { DOWN, ACROSS } Direction;

typedef struct _move {
    Direction direction;
    int yx_location[2];
    size_t num_tiles;
    Tile *tiles[HAND_SIZE];
} Move;

#endif /* end of include guard: MOVE_H */
