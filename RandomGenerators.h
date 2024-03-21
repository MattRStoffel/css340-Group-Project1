#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H

#include <vector>
#include <random>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace RandomGenerators {

    // Function generates a random set of integers based on the Normal distribution
    // returns vector of random integers that fit a normal distribution by calling generateRandomNumbers()
    std::vector<int> generateRandomNormalDistInts(int numCount, double mean, double std_dev);

    // Function generates a random set of floats based on the Uniform distribution
    // returns vector of random floats that fit a normal distribution by calling generateRandomNumbers()
    std::vector<float> generateRandomUniformDistFloats(int numCount, float lowerBound, float upperBound);

    //templated function to generate a vector of random number
    //used as return value for distribution generation functions
    template<typename Number, typename Distribution>
    std::vector<Number> generateRandomNumbers(int numCount, Distribution dist);

    template<typename T>
    std::vector<int> histogram(const std::vector<T>& v, int bins, int binWidth) {
        if (bins < 0) {
            throw std::invalid_argument("bins must be greater than 0");
        }
        if (binWidth < 0) {
            throw std::invalid_argument("binWidth must be greater than or equal to 0");
        }

        if (v.empty()) {
            throw std::invalid_argument("vector must not be empty");
        }

        auto minmax = std::minmax_element(v.begin(), v.end());
        T min = *minmax.first;
        T max = *minmax.second;

        std::vector<int> histogram(bins, 0);

        for (auto& value : v) {
            int bin = (value - min) / binWidth;
            if (bin == bins) {
                bin--;
            }
            histogram[bin]++;
        }

        return histogram;
    }
    
    template<typename T>
    void printHistogram(std::ostream& os, const std::vector<T>& v, int bins, int binWidth, char ch) {
        std::vector<int> histogramVec = histogram(v, bins, binWidth);

        auto minmax = std::minmax_element(v.begin(), v.end());
        T min = *minmax.first;
        T max = *minmax.second;
                
        // scale the  histogram to not print too horizontally
        int maxCount = *std::max_element(histogramVec.begin(), histogramVec.end());
        if (maxCount > 60) {
            for (auto& count : histogramVec) {
                count = count * 60 / maxCount;
            }
        }

        for (int i = 0; i < bins; i++) {
            os << std::setw(6) << min + i * binWidth << " - " << std::setw(6) << min + (i + 1) * binWidth - 1 << " | ";
            os << std::string(histogramVec[i], ch) << std::endl;
        }
    }

}

#endif // RANDOM_GENERATORS_H
