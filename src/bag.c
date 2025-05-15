#include "bag.h"
#include "random.h"
#include <stddef.h>
#include <stdlib.h>

struct _bag {
    Tile *tiles[BAG_SIZE];
    int count;
};

// hopefully not a bug but this doesn't clear memory
// NULL if bag is empty
Tile *draw_tile(Bag *this) {
    if (this->count == 0)
        return NULL;
    return this->tiles[--this->count];
}

// return false if bag was full
bool insert_tile(Bag *this, Tile *tile) {
    if (this->count >= BAG_SIZE)
        return false;

    this->tiles[this->count++] = tile;
    return true;
}

#define ADD_TILES(letter)                                                                          \
    for (int i = 0; i < letter##_COUNT; i++) {                                                     \
        this->tiles[this->count++] = new_tile(letter##_VALUE, #letter[0]);                         \
    }

Bag *new_bag() {
    Bag *this = malloc(sizeof(Bag));

    this->count = 0;
    ADD_TILES(A);
    ADD_TILES(B);
    ADD_TILES(C);
    ADD_TILES(D);
    ADD_TILES(E);
    ADD_TILES(F);
    ADD_TILES(G);
    ADD_TILES(H);
    ADD_TILES(I);
    ADD_TILES(J);
    ADD_TILES(K);
    ADD_TILES(L);
    ADD_TILES(M);
    ADD_TILES(N);
    ADD_TILES(O);
    ADD_TILES(P);
    ADD_TILES(Q);
    ADD_TILES(R);
    ADD_TILES(S);
    ADD_TILES(T);
    ADD_TILES(U);
    ADD_TILES(V);
    ADD_TILES(W);
    ADD_TILES(X);
    ADD_TILES(Y);
    ADD_TILES(Z);
    for (int i = 0; i < BLANK_COUNT; i++) {
        this->tiles[this->count++] = new_tile(BLANK_VALUE, ' ');
    }

    randomize_ptr_array((void **)&this->tiles, BAG_SIZE);

    return this;
}

void free_bag(Bag *this, bool free_tiles) {
    for (size_t i = 0; i < BAG_SIZE; i++) {
        if (free_tiles) {
            free_tile(this->tiles[i]);
        }
        this->tiles[i] = NULL;
    }
    this = NULL;
}
