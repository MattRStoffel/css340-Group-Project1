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

    template<typename T>
    constexpr bool is_numerical();

    template<typename T>
    void validVectorDataCheck(const std::vector<T>& data);

    template<typename T>
    double calculateMean(const std::vector<T>& data);

    template<typename T>
    double calculateMedian(std::vector<T> data);

    template<typename T>
    bool isApproximatelyNormal(const std::vector<T>& data, double allowableDifference = 1e-2);

    template<typename T>
    bool isApproximatelyUniform(const std::vector<T>& data, double allowableDifference = 0.5);


} // namespace UNITTESTS

#endif // UNITTESTS_H
