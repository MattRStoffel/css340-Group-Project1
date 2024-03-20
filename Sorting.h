// Assisted by ChatGPT 4.0
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

namespace MySortingLibrary {

    template<typename T, typename Func>
    void QuickSort(std::vector<T>& input, int low, int high, Func compare);

    template<typename T, typename Func>
    int partitionQuickSort(std::vector<T>& input, int low, int high, Func compare);

    template<typename T, typename Func>
    T QuickSelect(std::vector<T>& input, int low, int high, int k, Func compare);

    template<typename T>
    bool testQuickSort(std::vector<T> input, std::vector<T> expected);

    template<typename T>
    bool testQuickSelect(std::vector<T> input, int k, T expected);

} // namespace MySortingLibrary

#endif // SORTING_H
