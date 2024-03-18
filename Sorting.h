#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include <iostream>

namespace MySortingLibrary {

    template<typename RandomAccessIterator, typename Compare>
    void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template<typename RandomAccessIterator, typename Compare>
    RandomAccessIterator partitionQuickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template<typename T>
    bool testQuickSort(std::vector<T> input, std::vector<T>expected);
} // namespace MySortingLibrary

#endif // SORTING_H
