#ifndef HAND_H
#define HAND_H
#include "tile.h"
#include <stdbool.h>
#define HAND_SIZE 7

// "here's all the tiles i own" *points to them*
typedef struct _hand {
    // array of pointers to the tiles in the hand
    Tile *tiles[HAND_SIZE];
} Hand;

inline bool hand_isFull(Hand *this);

bool hand_contains(Hand *this, Tile *tile);

/*
 * removes the first occurance
 * true if it removed a tile
 * false if that tile wasn't in the hand
 */
bool hand_remove(Hand *this, Tile *tile);

/*
 * adds tile to hand
 * true if it added, false if the hand is already full
 */
bool hand_add(Hand *this, Tile *tile);

Hand *new_hand();

void free_hand(Hand *this, bool free_tiles);

#endif /* end of include guard: HAND_H */
