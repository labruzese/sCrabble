#include "hand.h"
#include "tile.h"
#include <stdbool.h>
#include <stdlib.h>

inline bool hand_isFull(Hand *this) { return !hand_contains(this, NULL); }

bool hand_contains(Hand *this, Tile *tile) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (tile_eq(this->tiles[i], tile)) {
            return true;
        }
    }
    return false;
}

bool hand_remove(Hand *this, Tile *tile) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (tile_eq(this->tiles[i], tile)) {
            this->tiles[i] = NULL;
            return true;
        }
    }
    return false;
}

bool hand_add(Hand *this, Tile *tile) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (tile_eq(this->tiles[i], NULL)) {
            this->tiles[i] = tile;
            return true;
        }
    }
    return false;
}

Hand *new_hand() {
    Hand *this = malloc(sizeof(Hand));
    return this;
}

void free_hand(Hand *this, bool free_tiles) {
    for (size_t i = 0; i < HAND_SIZE; i++) {
        if (free_tiles) {
            free_tile(this->tiles[i]);
        }
        this->tiles[i] = NULL;
    }
    this = NULL;
}
