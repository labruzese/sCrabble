#include "../include/tile.h"
#include <stdbool.h>
#include <stdlib.h>

struct _tile {
    int value;
    char letter;
};

char tile_letter(Tile *this) { return this->letter; }

int tile_value(Tile *this) { return this->value; }

bool tile_eq(Tile *one, Tile *two) {
    if (one == two)
        return true;

    if (one->letter != two->letter)
        return false;
    if (one->value != two->value)
        return false;

    return true;
}

Tile *new_tile(int value, char letter) {
    Tile *tile = malloc(sizeof(Tile));
    tile->value = value;
    tile->letter = letter;
    return tile;
}

void free_tile(Tile *this) {
    this->value = 0;
    this->letter = 0;
    this = NULL;
}
