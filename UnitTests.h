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
}

namespace Statistics {

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
    bool isApproximatelyNormal(const std::vector<T>& data, double allowableDifference = 1e-2) {
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
    bool isApproximatelyUniform(const std::vector<T>& data, double allowableDifference = 0.5) {
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

} // namespace Statistics

#endif // UNITTESTS_H
