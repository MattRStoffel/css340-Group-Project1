#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <iostream>

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
}

#endif // UNITTESTS_H
