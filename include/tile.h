#ifndef TILE_H
#define TILE_H

#include <stdbool.h>

typedef struct _tile Tile;

char tile_letter(Tile *this);

int tile_value(Tile *this);

bool tile_eq(Tile *one, Tile *two);

Tile *new_tile(int value, char letter);

void free_tile(Tile *this);

#endif // !TILE_H
