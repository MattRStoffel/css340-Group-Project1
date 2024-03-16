//templates are defined in the header file
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <numeric>

namespace Statistics {

    //function calculates the mean of a collection of vector elements
    template<typename T>
    double calculateMean(const std::vector<T>& data) {
        return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    }

    //function calculated the median of a collection of vector elements
    template<typename T>
    double calculateMedian(std::vector<T> data) {
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
        double mean = calculateMean(data);
        double median = calculateMedian(data);
        return std::abs(mean - median) < allowableDifference;
    }

}

#endif // STATISTICS_H
