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
        return isApproximatelyNormal(testData, 0.02);
    }

    bool test_generateRandomIntegers_2() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(100000, 0, 100);
        return isApproximatelyNormal(testData, 0.8);
    }

    bool test_generateRandomIntegers_3() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(100000, 100, 1);
        return isApproximatelyNormal(testData, 0.6);
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
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(1000, 10, 1000);
        RandomGenerators::histogram(std::cout, testData, 8, 30);
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
        return isApproximatelyUniform(testData, 1);
    }

    bool test_generateRandomFloats_2() {
        std::vector<float> testData;
        testData = RandomGenerators::generateRandomUniformDistFloats(20000, 1, 200);
        return isApproximatelyUniform(testData, 1.8);
    }

    bool test_generateRandomFloats_3() {
        std::vector<float> testData;
        testData = RandomGenerators::generateRandomUniformDistFloats(20000, 0, 1);
        return isApproximatelyUniform(testData, 0.1);
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

        //function to check if a value is numerical
    template<typename T>
    constexpr bool is_numerical() {
        return std::is_arithmetic<T>::value;
    }

    //function checks validity of input data
    template<typename T>
    void validVectorDataCheck(const std::vector<T>& data) {
        if (data.empty()) {
            throw std::runtime_error("Error: Input vector is empty.");
        }

        if (!is_numerical<T>()) {
            throw std::runtime_error("Error: Input vector contains non-numerical values.");
        }

    }

    //function calculates the mean of a collection of vector elements
    template<typename T>
    double calculateMean(const std::vector<T>& data) {
        validVectorDataCheck(data);
        return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    }

    //function calculated the median of a collection of vector elements
    template<typename T>
    double calculateMedian(std::vector<T> data) {
        validVectorDataCheck(data);

        size_t size = data.size();
        std::sort(data.begin(), data.end());
        if (size % 2 == 0) {
            return (data[size / 2 - 1] + data[size / 2]) / 2.0;
        } else {
            return data[size / 2];
        }
    }

    //function calculates if a collection of vector elements is approx. normal
    //determined by comparing the mean and median.
    //if the two values are approx. equivalent (within specified) threshold,
    //the distribution is considered normal
    template<typename T>
    bool isApproximatelyNormal(const std::vector<T>& data, double allowableDifference) {
        validVectorDataCheck(data);
        double mean = calculateMean(data);
        double median = calculateMedian(data);
        return std::abs(mean - median) < allowableDifference;
    }

    //function calculates if a collection of vector elements is approx. uniform
    //determined by checking if the mean and median are roughly the same value as the midpoint of the range
    //if the two values are approximately equivalent (within specified) threshold,
    //the distribution is considered uniform
    template<typename T>
    bool isApproximatelyUniform(const std::vector<T>& data, double allowableDifference) {
        validVectorDataCheck(data);

        auto lowerBound = *std::min_element(data.begin(), data.end());
        auto upperBound = *std::max_element(data.begin(), data.end());

        T rangeMidPoint = (upperBound + lowerBound) / 2;
        double mean = calculateMean(data);
        double median = calculateMedian(data);

        // Check if the absolute difference between mean and rangeMidPoint is within allowableDifference
        bool meanCheck = std::abs(mean - rangeMidPoint) < allowableDifference;
        // Check if the absolute difference between median and rangeMidPoint is within allowableDifference
        bool medianCheck = std::abs(median - rangeMidPoint) < allowableDifference;

        // Return true if both checks pass
        return meanCheck && medianCheck;
    }

} // namespace UNITTESTS

