//assisted by ChatGPT 4.0
#include "UnitTests.h"

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

        // Problem 4: Almost Generic Randomized QuickSelect Algorithm
        if (!test_quickSelect_1()) {
            std::cout << "test_quickSelect_1 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSelect_1 passed" << std::endl;
        }

        if (!test_quickSelect_2()) {
            std::cout << "test_quickSelect_2 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSelect_2 passed" << std::endl;
        }

        if (!test_quickSelect_3()) {
            std::cout << "test_quickSelect_3 failed" << std::endl;
            allTestsPassed = false;
        } else {
            std::cout << "test_quickSelect_3 passed" << std::endl;
        }

        return allTestsPassed;
    }

     // Problem 1: Generating Histogram for Randomly Generated Integer Numbers
    bool test_generateRandomIntegers_1() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(20000, 0, 1);
        // std::stringstream ss;
        // RandomGenerators::printHistogram(ss, testData, 10, 1, '0');
        // std::cout << ss.str() << std::endl;
        return isApproximatelyNormal(testData, 0.02);
    }

    bool test_generateRandomIntegers_2() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(100000, 0, 100);
        // std::stringstream ss;
        // RandomGenerators::printHistogram(ss, testData, 100, 10, '0');
        // std::cout << ss.str() << std::endl;
        return isApproximatelyNormal(testData, 0.8);
    }

    bool test_generateRandomIntegers_3() {
        std::vector<int> testData;
        testData = RandomGenerators::generateRandomNormalDistInts(100000, 100, 1);
        // std::stringstream ss;
        // RandomGenerators::printHistogram(ss, testData, 10, 1, '0');
        // std::cout << ss.str() << std::endl;
        return isApproximatelyNormal(testData, 0.6);
    }

    bool test_calculateHistogram_1() {
        std::vector<int> testData = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> histogram = RandomGenerators::histogram(testData, 10, 1);
        std::vector<int> expected = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        return histogram == expected;
    }

    bool test_calculateHistogram_2() {
        std::vector<int> testData = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> histogram = RandomGenerators::histogram(testData, 5, 2);
        std::vector<int> expected = {2, 2, 2, 2, 2};
        return histogram == expected;
    }

    bool test_calculateHistogram_3() {
        std::vector<int> testData = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> histogram = RandomGenerators::histogram(testData, 5, 3);
        std::vector<int> expected = {3, 3, 3, 1, 0};
        return histogram == expected;
    }

    bool test_printHistogram_1() {
        std::vector<int> testData = {1,1,1,1,2,2,2,2,2,2,4,4,4,4,4,7,7,7,7,7,9,9,9,9,9,9};
        std::stringstream ss;
        RandomGenerators::printHistogram(ss, testData, 4, 3, '0');
        std::string expected = "1-3|00000000004-6|000007-9|0000000000010-12|";
        return removeWhitespace(ss.str()) == removeWhitespace(expected);
    }

    bool test_printHistogram_2() {
        std::vector<int> testData = {1,1,1,1,2,2,2,2,2,2,4,4,4,4,4,7,7,7,7,7,9,9,9,9,9,9};
        std::stringstream ss;
        RandomGenerators::printHistogram(ss, testData, 5, 2, '0');
        std::string expected = "1-2|00000000003-4|000005-6|7-8|000009-10|000000";
        return removeWhitespace(ss.str()) == removeWhitespace(expected);
    }

    bool test_printHistogram_3() {
        std::vector<int> testData = {1,1,1,1,2,2,2,2,2,2,4,4,4,4,4,7,7,7,7,7,9,9,9,9,9,9};
        std::stringstream ss;
        RandomGenerators::printHistogram(ss, testData, 5, 3, '0');
        std::string expected = "1-3|00000000004-6|000007-9|0000000000010-12|13-15|";
        return removeWhitespace(ss.str()) == expected;
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
        // std::stringstream ss;
        // RandomGenerators::printHistogram(ss, testData, 20, 10, '0');
        // std::cout << ss.str() << std::endl;
        return isApproximatelyUniform(testData, 1.8);
    }

    bool test_generateRandomFloats_3() {
        std::vector<float> testData;
        testData = RandomGenerators::generateRandomUniformDistFloats(20000, 0, 1);
        return isApproximatelyUniform(testData, 0.1);
    }

    // Problem 3: Almost Generic Randomized QuickSort Algorithm
    bool test_partition_1() {
        return runPartitionTest<int>({10, 7, 8, 9, 1, 5}, [](int a, int b) { return a < b; });
    }

    bool test_partition_2() {
        return runPartitionTest<float>({10.1f, 7.2f, 8.3f, 7.2f, 1.4f, 5.5f}, [](float a, float b) { return a < b; });

    }

    bool test_partition_3() {
        return runPartitionTest<int>({2, -3, 5, -1, -3, 2, 8, 2, -1, 4}, [](int a, int b) { return a < b; });
    }

    bool test_quickSort_1() {
        std::vector<float> input = {2,3,1,0};
        std::vector<float> expected = {0,1,2,3};
        return UNITTESTS::testQuickSort(input, expected);
    }

    bool test_quickSort_2() {
        std::vector<int> input = {5, 5, 4, 2, 2};
        std::vector<int> expected = {2, 2, 4, 5, 5};
        return UNITTESTS::testQuickSort(input, expected);
    }

    bool test_quickSort_3() {
        std::vector<int> input = {1};
        std::vector<int> expected = {1};
        return UNITTESTS::testQuickSort(input, expected);
    }

    // Problem 4: Almost Generic Randomized QuickSelect Algorithm
    bool test_quickSelect_1() {
        std::vector<int> input = {3,2,1,0};
        int k = 0;
        int expected = 0;
        return UNITTESTS::testQuickSelect(input, k, expected);
    }

    bool test_quickSelect_2() {
        std::vector<int> input = {3,2,1,0};
        int k = 1;
        int expected = 1;
        return UNITTESTS::testQuickSelect(input, k, expected);
    }

    bool test_quickSelect_3() {
        std::vector<int> input = {3,2,1,0};
        int k = 2;
        int expected = 2;
        return UNITTESTS::testQuickSelect(input, k, expected);
    }
    

    std::string removeWhitespace(const std::string& str) {
        std::string result;
        std::copy_if(str.begin(), str.end(), std::back_inserter(result), 
            [](char c){ return !std::isspace(c); });
        return result;
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

