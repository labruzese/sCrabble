#ifndef BAG_H
#define BAG_H

#include "tile.h"

#define A_COUNT 9
#define B_COUNT 2
#define C_COUNT 2
#define D_COUNT 4
#define E_COUNT 12
#define F_COUNT 2
#define G_COUNT 3
#define H_COUNT 2
#define I_COUNT 9
#define J_COUNT 1
#define K_COUNT 1
#define L_COUNT 4
#define M_COUNT 2
#define N_COUNT 6
#define O_COUNT 8
#define P_COUNT 2
#define Q_COUNT 1
#define R_COUNT 6
#define S_COUNT 4
#define T_COUNT 6
#define U_COUNT 4
#define V_COUNT 2
#define W_COUNT 2
#define X_COUNT 1
#define Y_COUNT 2
#define Z_COUNT 1
#define BLANK_COUNT 2
#define BAG_SIZE                                                                                   \
    (A_COUNT + B_COUNT + C_COUNT + D_COUNT + E_COUNT + F_COUNT + G_COUNT + H_COUNT + I_COUNT +     \
     J_COUNT + K_COUNT + L_COUNT + M_COUNT + N_COUNT + O_COUNT + P_COUNT + Q_COUNT + R_COUNT +     \
     S_COUNT + T_COUNT + U_COUNT + V_COUNT + W_COUNT + X_COUNT + Y_COUNT + Z_COUNT +               \
     BLANK_COUNT) // 100
#define A_VALUE 1
#define B_VALUE 3
#define C_VALUE 3
#define D_VALUE 2
#define E_VALUE 1
#define F_VALUE 4
#define G_VALUE 2
#define H_VALUE 4
#define I_VALUE 1
#define J_VALUE 8
#define K_VALUE 5
#define L_VALUE 1
#define M_VALUE 3
#define N_VALUE 1
#define O_VALUE 1
#define P_VALUE 3
#define Q_VALUE 10
#define R_VALUE 1
#define S_VALUE 1
#define T_VALUE 1
#define U_VALUE 1
#define V_VALUE 4
#define W_VALUE 4
#define X_VALUE 8
#define Y_VALUE 4
#define Z_VALUE 10
#define BLANK_VALUE 0

typedef struct _bag Bag;

Tile *draw_tile(Bag *this);

bool insert_tile(Bag *this, Tile *tile);

Bag *new_bag();

void free_bag(Bag *this, bool free_tiles);

#endif /* end of include guard: BAG_H */
