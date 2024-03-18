#include "Sorting.h"

namespace MySortingLibrary {

    // Implement your sorting algorithms here
    template<typename Number>
    void quicksort(Number arr[], int low, int high) {
        
    }

    template<typename Number>
    void partition(Number arr[], int low, int high) {
        Number pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }

    template<typename Number>
    void swap(Number& a, Number& b) {
        Number temp = *a;
        *a = *b;
        *b = temp;
    }
} // namespace MySortingLibrary