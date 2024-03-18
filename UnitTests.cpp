//assisted by ChatGPT 4.0
#include "UnitTests.h"
#include "RandomGenerators.h"

namespace UNITTESTS {
    // Implement your functions, classes, and variables here

    bool runTests() {
        bool allTestsPassed = true;

        // Problem 1: Generating Histogram for Randomly Generated Integer Numbers
        if (!test_generateRandomIntegers_1()) {
            std::cout << "test_generateRandomIntegers_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomIntegers_1 passed" << std::endl;
        }

        if (!test_generateRandomIntegers_2()) {
            std::cout << "test_generateRandomIntegers_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomIntegers_2 passed" << std::endl;
        }

        if (!test_generateRandomIntegers_3()) {
            std::cout << "test_generateRandomIntegers_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomIntegers_3 passed" << std::endl;
        }

        if (!test_calculateHistogram_1()) {
            std::cout << "test_calculateHistogram_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_calculateHistogram_1 passed" << std::endl;
        }

        if (!test_calculateHistogram_2()) {
            std::cout << "test_calculateHistogram_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_calculateHistogram_2 passed" << std::endl;
        }

        if (!test_calculateHistogram_3()) {
            std::cout << "test_calculateHistogram_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_calculateHistogram_3 passed" << std::endl;
        }

        if (!test_printHistogram_1()) {
            std::cout << "test_printHistogram_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_printHistogram_1 passed" << std::endl;
        }

        if (!test_printHistogram_2()) {
            std::cout << "test_printHistogram_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_printHistogram_2 passed" << std::endl;
        }

        if (!test_printHistogram_3()) {
            std::cout << "test_printHistogram_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_printHistogram_3 passed" << std::endl;
        }

        // Problem 2: Generating Histogram for Randomly Generated Floating-Point Numbers
        if (!test_generateRandomFloats_1()) {
            std::cout << "test_generateRandomFloats_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomFloats_1 passed" << std::endl;
        }

        if (!test_generateRandomFloats_2()) {
            std::cout << "test_generateRandomFloats_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomFloats_2 passed" << std::endl;
        }

        if (!test_generateRandomFloats_3()) {
            std::cout << "test_generateRandomFloats_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_generateRandomFloats_3 passed" << std::endl;
        }

        // Problem 3: Almost Generic Randomized QuickSort Algorithm
        if (!test_partition_1()) {
            std::cout << "test_partition_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_partition_1 passed" << std::endl;
        }

        if (!test_partition_2()) {
            std::cout << "test_partition_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_partition_2 passed" << std::endl;
        }

        if (!test_partition_3()) {
            std::cout << "test_partition_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_partition_3 passed" << std::endl;
        }

        if (!test_quickSort_1()) {
            std::cout << "test_quickSort_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSort_1 passed" << std::endl;
        }

        if (!test_quickSort_2()) {
            std::cout << "test_quickSort_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSort_2 passed" << std::endl;
        }

        if (!test_quickSort_3()) {
            std::cout << "test_quickSort_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSort_3 passed" << std::endl;
        }

        return allTestsPassed;
    }


    // Problem 1: Generating Histogram for Randomly Generated Integer Numbers
    bool test_generateRandomIntegers_1() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(20000, 0, 1);
        return Statistics::isApproximatelyNormal(testData);
    }

    bool test_generateRandomIntegers_2() {
        return false;
    }

    bool test_generateRandomIntegers_3() {
        return false;
    }

    bool test_calculateHistogram_1() {
        return false;
    }

    bool test_calculateHistogram_2() {
        return false;
    }

    bool test_calculateHistogram_3() {
        return false;
    }

    bool test_printHistogram_1() {
        return false;
    }

    bool test_printHistogram_2() {
        return false;
    }

    bool test_printHistogram_3() {
        return false;
    }

    // Problem 2: Generating Histogram for Randomly Generated Floating-Point Numbers
    bool test_generateRandomFloats_1() {
        std::vector<float> testData;
        testData = RandomGenerators::generateRandomUniformDistFloats(20000, 10, 100);
        return Statistics::isApproximatelyUniform(testData);
    }

    bool test_generateRandomFloats_2() {
        return false;
    }

    bool test_generateRandomFloats_3() {
        return false;
    }

    // Problem 3: Almost Generic Randomized QuickSort Algorithm
    bool test_partition_1() {
        return false;
    }

    bool test_partition_2() {
        return false;
    }

    bool test_partition_3() {
        return false;
    }

    bool test_quickSort_1() {
        return false;
    }

    bool test_quickSort_2() {
        return false;
    }

    bool test_quickSort_3() {
        return false;
    }

}
