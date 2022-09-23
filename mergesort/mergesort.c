#include <stdlib.h>

#include "mergesort.h"

void mergeRanges(int values[], int start, int mid, int end) {
    int rangeSize = end - start;
    int *destination = (int *) calloc(rangeSize, sizeof(int));
    int first = start;
    int second = mid;
    int copy = 0;
    while (first < mid && second < end) {
        if (values[first] < values[second]) {
            destination[copy] = values[first];
            ++first;
        } else {
            destination[copy] = values[second];
            ++second;
        }
        ++copy;
    }
    while (first < mid) {
        destination[copy] = values[first];
        ++copy;
        ++first;
    }
    while (second < end) {
        destination[copy] = values[second];
        ++copy;
        ++second;
    }
    for (int i=0; i<rangeSize; ++i) {
        values[i+start] = destination[i];
    }
    free(destination);
}

void mergesortRange(int values[], int start, int end) {
    int rangeSize = end - start;
    if (rangeSize < 2) {
        return;
    }

    int mid = (start + end) / 2;
    mergesortRange(values, start, mid);
    mergesortRange(values, mid, end);
    mergeRanges(values, start, mid, end);
}

void mergesort(int size, int values[]) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.

  mergesortRange(values, 0, size);
}
