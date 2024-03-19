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
    void histogram(std::ostream& os, const std::vector<T>& v, int width, int bins) {
        if (bins < 1) {
            throw std::invalid_argument("bins must be greater than 0");
        }

        if (width < 1) {
            throw std::invalid_argument("width must be greater than 0");
        }

        if (v.empty()) {
            throw std::invalid_argument("vector must not be empty");
        }

        auto minmax = std::minmax_element(v.begin(), v.end());
        auto min = *minmax.first;
        auto max = *minmax.second;

        auto binWidth = (max - min) / bins;

        std::vector<int> histogram(bins, 0);

        for (auto& value : v) {
            int bin = (value - min) / binWidth;
            if (bin == bins) {
                bin--;
            }
            histogram[bin]++;
        }

        for (int i = 0; i < bins; i++) {
            os << std::setw(width) << min + i * binWidth << " - " << std::setw(width) << min + (i + 1) * binWidth << " | ";
            os << std::string(histogram[i], '*') << std::endl;
        }
    
    }

}

#endif // RANDOM_GENERATORS_H
