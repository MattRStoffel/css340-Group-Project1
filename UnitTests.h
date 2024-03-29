//templates are defined in the header file
//assisted by ChatGPT 4.0

#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>

#include "Sorting.h"
#include "RandomGenerators.h"

namespace UNITTESTS {
    // Declare your functions, classes, and variables here

    bool runTests(); // Example function declaration

    // Problem 1: Generating Histogram for Randomly Generated Integer Numbers
    bool test_generateRandomIntegers_1();
    bool test_generateRandomIntegers_2();
    bool test_generateRandomIntegers_3();

    bool test_calculateHistogram_1();
    bool test_calculateHistogram_2();
    bool test_calculateHistogram_3();

    bool test_printHistogram_1();
    bool test_printHistogram_2();
    bool test_printHistogram_3();

    // Problem 2: Generating Histogram for Randomly Generated Floating-Point Numbers
    bool test_generateRandomFloats_1();
    bool test_generateRandomFloats_2();
    bool test_generateRandomFloats_3();

    // Problem 3: Almost Generic Randomized QuickSort Algorithm
    bool test_partition_1();
    bool test_partition_2();
    bool test_partition_3();

    bool test_quickSort_1();
    bool test_quickSort_2();
    bool test_quickSort_3();

    // Problem 4: Randomized QuickSelect Algorithm
    bool test_quickSelect_1();
    bool test_quickSelect_2();
    bool test_quickSelect_3();

    std::string removeWhitespace(const std::string& str);

    template<typename T>
    constexpr bool is_numerical();

    template<typename T>
    void validVectorDataCheck(const std::vector<T>& data);

    template<typename T>
    double calculateMean(const std::vector<T>& data);

    template<typename T>
    double calculateMedian(std::vector<T> data);

    template<typename T>
    bool isApproximatelyNormal(const std::vector<T>& data, double allowableDifference = 0.01);

    template<typename T>
    bool isApproximatelyUniform(const std::vector<T>& data, double allowableDifference = 0.5);

    template<typename T>
    bool testQuickSort(std::vector<T> input, std::vector<T> expected) {
        //write a lambda function to compare the two values
        MySortingLibrary::QuickSort(input, [](T x, T y) { return x < y; });
        if (input == expected) {
            return true;
        } else {
            return false;
        }
    }

    template<typename T>
    bool testQuickSelect(std::vector<T> input, int k, T expected) {
        T quickSelectOutput = MySortingLibrary::QuickSelect(input, k);
        if (quickSelectOutput == expected) {
            return true;
        } else {
            return false;
        }
    }

    template<typename T>
    bool runPartitionTest(std::vector<T> input, std::function<bool(T, T)> compare) {
        int n = input.size();
        bool allTestsPassed = true;
        for (int test = 0; test < 3; ++test) {
            std::vector<T> testInput = input; // Use a copy of the input for each test
            int pivotIndex = MySortingLibrary::partitionQuickSort(testInput, 0, n-1, compare);
            T pivotValue = testInput[pivotIndex];
            // Check elements on the left
            for (int i = 0; i < pivotIndex; ++i) {
                if (!compare(testInput[i], pivotValue)) {
                    allTestsPassed = false;
                    break;
                }
            }
            // Check elements on the right
            for (int i = pivotIndex + 1; i < n && allTestsPassed; ++i) {
                if (compare(testInput[i], pivotValue)) {
                    allTestsPassed = false;
                    break;
                }
            }
            if (!allTestsPassed) {
                return false; // Return false on first failed test
            }
        }
        return true;
    }


} // namespace UNITTESTS

#endif // UNITTESTS_H
