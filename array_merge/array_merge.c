#include <stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"

bool not_contained(int all_values[], int size, int value) {
    for (int i=0; i<size; ++i) {
        if (all_values[i] == value) {
            return false;
        }
    }
    return true;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  // This is obviously broken. It has the right type, though, eh?
  int total_size = 0;
  for (int i=0; i<num_arrays; ++i) {
    total_size += sizes[i];
  }

  int* all_values = (int*) calloc(total_size+1, sizeof(int));

  int k=0;
  for (int i=0; i<num_arrays; ++i) {
    for (int j=0; j<sizes[i]; ++j) {
        int val = values[i][j];
        if (not_contained(all_values, k, val)) {
            all_values[k] = val;
            ++k;
        }
    }
  }

  mergesort(k, all_values);

  int* result = (int*) calloc(k+1, sizeof(int));
  result[0] = k;
  for (int i=0; i<k; ++i) {
    result[i+1] = all_values[i];
  }

  return result;
}
