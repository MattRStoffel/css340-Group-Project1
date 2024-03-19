#include "Sorting.h"

namespace MySortingLibrary {

    template<typename RandomAccessIterator, typename Compare>
    void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
        if (distance(first, last) <= 1) return; // Base case: 0 or 1 element

        // Partition the array
        RandomAccessIterator pivot = partitionQuickSort(first, last, comp);

        // Recursively apply quicksort to the partitions
        quickSort(first, pivot, comp); // Sort the lower part
        quickSort(std::next(pivot), last, comp); // Sort the upper part
    }

    template<typename RandomAccessIterator, typename Compare>
    RandomAccessIterator partitionQuickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
        auto pivot = std::prev(last);
        auto i = first;
        for (auto j = first; j != pivot; j++) {
            if (comp(*j, *pivot)) {
                std::swap(*i, *j);
                i++;
            }
        }
        std::swap(*i, *pivot);
        return i;
    }

    template<typename T>
    bool testQuickSort(std::vector<T> input, std::vector<T> expected) {
        quickSort(input.begin(), input.end(), std::less<T>{});
        if (input == expected) {
            return true;
        } else {
            for (const auto& e : expected) std::cout << e << " ";
            std::cout << "] Got: [";
            for (const auto& i : input) std::cout << i << " ";
            std::cout << "])\n";
            return false;
        }
    }

} // namespace MySortingLibrary