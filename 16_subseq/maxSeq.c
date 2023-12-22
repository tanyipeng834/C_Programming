#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    size_t maxSeq = 1;
    size_t currentSeq = 1;
    for (size_t i = 0; i < n - 1; i++) {
        if (array[i] < array[i + 1]) {
            currentSeq++;
        } else {
            if (currentSeq > maxSeq) {
                maxSeq = currentSeq;
            }
            currentSeq = 1;  // Start a new sequence with the current element
        }
    }

    // Check the last element
    if (currentSeq > maxSeq) {
        maxSeq = currentSeq;
    }

    return maxSeq;
}

