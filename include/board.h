#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <stdbool.h>

#define BOARD_SIZE 15

typedef enum { DOUBLE_WORD, TRIPLE_WORD, DOUBLE_LETTER, TRIPLE_LETTER } Multipler;

typedef struct _square {
    Multipler mult;
    Tile *tile;
} Square;

typedef struct _board {
    Square square[BOARD_SIZE][BOARD_SIZE];
} Board;

#endif
