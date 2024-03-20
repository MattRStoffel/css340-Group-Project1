// Assisted by ChatGPT 4.0
#include "Sorting.h"

namespace MySortingLibrary {

    // Declaration for object types for linker to identify within the library
    template bool MySortingLibrary::testQuickSort<float>(std::vector<float>, std::vector<float>);

    template bool MySortingLibrary::testQuickSort<int>(std::vector<int>, std::vector<int>);

    template bool MySortingLibrary::testQuickSelect<int>(std::vector<int>, int, int);

    // Partition Function for Quick Sort
    template<typename T, typename Func>
    int partitionQuickSort(std::vector<T>& input, int low, int high, Func compare) {
        // Set new pivot to the highest index in the vector
        T pivot = input[high];

        int i = low;
        // Iterate through while j is lower than high
        for (int j = low; j < high; ++j) {
            // Using generic comparison, check if the value at index j is less than the value at index i
            if (compare(input[j], pivot)) {
                // Swap the 2 values and increment i by 1 as the new low
                std::swap(input[i], input[j]);
                ++i;
            }
        }
        // Swap the value at i with the value at the high index
        std::swap(input[i], input[high]);
        // return i as that is where the new pivot is
        return i;
    }

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

    // Helper function to initialize function
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

        if (pivot == k) {
            return input[k];
        } else if (k < pivot) {
            return QuickSelect(input, low, pivot - 1, k, compare);
        } else {
            return QuickSelect(input, pivot + 1, high, k, compare);
        }
    }

    // Helper function to initialize function
    template<typename T, typename Func = std::less<T>>
    T QuickSelect(std::vector<T>& input, int k, Func compare = Func{}) {
        if (!input.empty()) {
            return QuickSelect(input, 0, input.size() - 1, k, compare);
        } else {
            throw std::runtime_error("Input array is empty");
        }
    }

    template<typename T>
    bool testQuickSort(std::vector<T> input, std::vector<T> expected) {
        //write a lambda function to compare the two values
        QuickSort(input, [](T x, T y) { return x < y; });
        if (input == expected) {
            return true;
        } else {
            for (const auto& e: expected) std::cout << e << " ";
            std::cout << "] Got: [";
            for (const auto& i: input) std::cout << i << " ";
            std::cout << "])\n";
            return false;
        }
    }


    template<typename T>
    bool testQuickSelect(std::vector<T> input, int k, T expected) {
        T quickSelectOutput = QuickSelect(input, k);
        if (quickSelectOutput == expected) {
            return true;
        } else {
            return false;
        }
    }
}