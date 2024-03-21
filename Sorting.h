// Assisted by ChatGPT 4.0
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <random>
namespace MySortingLibrary {

    // Partition Function for Quick Sort
    template<typename T, typename Func>
    int partitionQuickSort(std::vector<T>& input, int low, int high, Func compare) {
        // Set new pivot to the highest index in the vector
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(low, high);
        int randomPivot = distrib(gen);
        std::swap(input[randomPivot], input[high]);
        T pivot = input[high];

        int i = low;
        for (int j = low; j < high; ++j) {
            // Using the given comparison, check if current element is less than the pivot
            if (compare(input[j], pivot)) {
                // Swap if the element is less than the pivot
                std::swap(input[i], input[j]);
                i++;
            }
        }
        // Swap the pivot element to its correct position
        std::swap(input[i], input[high]);
        // Return the pivot's final position
        return i;
    }

    // Quick Sort
    template<typename T, typename Func>
    void QuickSort(std::vector<T>& input, int low, int high, Func compare) {
        // If the lower value is greater than the upper value, it is sorted
        if (compare(low, high)) {

            // Setting the pivot
            int pivot = partitionQuickSort(input, low, high, compare);

            QuickSort(input, low, pivot - 1, compare); // Sort the low up to the pivot
            QuickSort(input, pivot + 1, high, compare); // Sort from the pivot to the high
        }
    }

    // Helper function to initialize function (Used for unit tests)
    template<typename T, typename Func = std::less<T>>
    void QuickSort(std::vector<T>& input, Func compare = Func{}) {
        if (!input.empty()) {
            QuickSort(input, 0, input.size() - 1, compare);
        }
    }

    template<typename T, typename Func>
    T QuickSelect(std::vector<T>& input, int low, int high, int k, Func compare) {
        // If the lower value is greater than the upper value, it is sorted
        if (high < low) {
            // base case: low and high crossed each other,
            // so we return a sentinel value or throw exception
            throw std::runtime_error("Invalid input in QuickSelect function");
        }

        // Setting the pivot
        int pivot = partitionQuickSort(input, low, high, compare);

        // Check if pivot is equals our desired value, then we can return it (Base case)
        if (pivot == k) {
            return input[k];
        } else if (k < pivot) { // If desired value is less than the pivot we recurrsively call QuickSelect
            return QuickSelect(input, low, pivot - 1, k, compare);
        } else { // If desired value is greater than the pivot we recurrsively call QuickSelect
            return QuickSelect(input, pivot + 1, high, k, compare);
        }
    }

    // Helper function to initialize function (Used for tests)
    template<typename T, typename Func = std::less<T>>
    T QuickSelect(std::vector<T>& input, int k, Func compare = Func{}) {
        if (!input.empty()) {
            return QuickSelect(input, 0, input.size() - 1, k, compare);
        } else {
            throw std::runtime_error("Input array is empty");
        }
    }


} // namespace MySortingLibrary

#endif // SORTING_H
