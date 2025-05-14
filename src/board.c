#include <"../include/board.h">
#include <"../include/tile.h">

typedef enum { DOUBLE_WORD, TRIPLE_WORD, DOUBLE_LETTER, TRIPLE_LETTER } Multipler;

typedef struct _square {
    Multipler mult;
    Tile *tile;
} Square;

struct _board {
    Square[BOARD_SIZE][BOARD_SIZE] squares;
};
