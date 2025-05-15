#include "console_player.h"
#include "hand.h"
#include "move.h"
#include "tile.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * Prompts the user for move input and populates the Move struct.
 * Format: [D|A] ROW COL TILES
 * Example: "A 7 8 A B C" means ACROSS at row 7, column 8, using 3 tiles: A, B, and C
 *
 * @param move Pointer to the Move struct to populate
 * @param hand the player's hand
 * @return 1 if input was successfully read, 0 otherwise
 */
int console_player_get_move(Move *move, Hand *hand) {
    char input[100];
    char dir_char;
    char tile_letters[HAND_SIZE];

    printf("Enter your move [D|A] ROW COL TILES:\n");
    printf("[D = DOWN, A = ACROSS] Example: A 7 8 A B C\n");

    if (!fgets(input, sizeof(input), stdin)) {
        return 0;
    }

    // Parse direction, location, and number of tiles
    if (sscanf(input, "%c %d %d", &dir_char, &move->yx_location[0], &move->yx_location[1])) {
        printf("Invalid input format. Please try again.\n");
        return 0;
    }

    // Set direction based on input
    if (toupper(dir_char) == 'D') {
        move->direction = DOWN;
    } else if (toupper(dir_char) == 'A') {
        move->direction = ACROSS;
    } else {
        printf("Invalid direction. Use 'D' for DOWN or 'A' for ACROSS.\n");
        return 0;
    }

    // Parse tile letters
    char *token = input;
    // Skip the first three tokens (direction, row, col)
    for (int i = 0; i < 3; i++) {
        token = strchr(token, ' ');
        if (!token) {
            printf("Not enough parameters provided.\n");
            return 0;
        }
        token++; // Move past the space
    }

    move->num_tiles = 0;
    // Read the tile letters
    for (size_t i = 0; i < HAND_SIZE; i++) {
        // Skip spaces
        while (*token && isspace(*token)) {
            token++;
        }

        if (!*token) {
            break; // Found all our tiles
        }

        move->num_tiles++;
        tile_letters[i] = toupper(*token);
        token++;

        // Find the tile in the hand
        int found = 0;
        for (size_t j = 0; j < HAND_SIZE; j++) {
            if (hand->tiles[j] && toupper(tile_letter(hand->tiles[j])) == tile_letters[i]) {
                move->tiles[i] = hand->tiles[j];
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Tile '%c' not found in your hand.\n", tile_letters[i]);
            return 0;
        }
    }

    printf("Move recorded: %s at (%d,%d) with %zu tiles\n",
           move->direction == DOWN ? "DOWN" : "ACROSS", move->yx_location[0], move->yx_location[1],
           move->num_tiles);

    return 1;
}

// to update a board let's keep track of the last move printed so we don't print stuff twice.
