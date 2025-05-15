#include "random.h"
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

void randomize_ptr_array(void **arr, size_t size) {
    // Seed the random number generator
    srand(time(NULL));

    // Perform Fisher-Yates shuffle
    for (int i = size - 1; i > 0; i--) {
        // Generate a random index between 0 and i
        int j = rand() % (i + 1);

        // Swap array[i] and array[j]
        void *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
