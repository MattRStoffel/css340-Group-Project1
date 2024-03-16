//templates are defined in the header file
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <numeric>
#include <iostream>

namespace Statistics {

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

    //function to check if a value is numerical
    template<typename T>
    constexpr bool is_numerical() {
        return std::is_arithmetic<T>::value;
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

}

#endif // STATISTICS_H
