#include "RandomGenerators.h"

namespace RandomGenerators {

    // Function generates a random set of integers based on the Normal distribution
    // returns vector of random integers that fit a normal distribution
    std::vector<int> generateRandomNormalDistInts(int numCount, double mean, double std_dev) {
        if (std_dev <= 0) {
            throw std::invalid_argument("standard deviation must be greater than 0");
        }

        return generateRandomNumbers<int>(numCount, std::normal_distribution<>(mean, std_dev));
    }

    // Function generates a random set of floats based on the Uniform distribution
    // returns vector of random floats that fit a normal distribution
    std::vector<float> generateRandomUniformDistFloats(int numCount, float lowerBound, float upperBound) {
        if (lowerBound >= upperBound) {
            throw std::invalid_argument("lowerBound must be less than upperBound");
        }

        return generateRandomNumbers<float>(numCount, std::uniform_real_distribution<>(lowerBound, upperBound));
    }

    template<typename Number, typename Distribution>
    std::vector<Number> generateRandomNumbers(int numCount, Distribution dist) {

        if (numCount < 1) {
            throw std::invalid_argument("numCount must be greater than 0");
        }

        std::random_device rd;
        std::mt19937 generator(rd());

        std::vector<Number> randomNumbers(numCount);

        for (int n = 0; n < numCount; n++) {
            randomNumbers[n] = static_cast<Number>(dist(generator));
        }

        return randomNumbers;
    }

    void histogram(std::ostream& os, const std::vector<int>& v, int ubins, int binWidth) {
        histogram<int>(os, v, ubins, binWidth);
    }   //ew owwie oof

    void histogram(std::ostream& os, const std::vector<float>& v, int ubins, int binWidth) {
        histogram<float>(os, v, ubins, binWidth);
    }   //ew owwie oof
    
    template<typename T>
    void histogram(std::ostream& os, const std::vector<T>& v, int ubins, int binWidth) {
        if (ubins < 0) {
            throw std::invalid_argument("bins must be greater than 0");
        }
        if (binWidth < 0) {
            throw std::invalid_argument("binWidth must be greater than or equal to 0");
        }

        if (v.empty()) {
            throw std::invalid_argument("vector must not be empty");
        }

        auto minmax = std::minmax_element(v.begin(), v.end());
        auto min = *minmax.first;
        auto max = *minmax.second;

        int bins = 0;

        if (ubins == 0 && binWidth == 0) {
            bins = 10;
            binWidth = (max - min) / bins;
        } else if (ubins != 0) {
            bins = ubins;
            binWidth = (max - min) / bins;
        } else {
            bins = (max - min) / binWidth;
        }

        std::vector<int> histogram(bins, 0);

        for (auto& value : v) {
            int bin = (value - min) / binWidth;
            if (bin == bins) {
                bin--;
            }
            histogram[bin]++;
        }

        // scale the  histogram to not print too horizontally
        int maxCount = *std::max_element(histogram.begin(), histogram.end());
        for (auto& count : histogram) {
            count = count * 60 / maxCount;
        }
        
        for (int i = 0; i < bins; i++) {
            os << std::setw(6) << min + i * binWidth << " - " << std::setw(6) << min + (i + 1) * binWidth << " | ";
            os << std::string(histogram[i], '0') << std::endl;
        }
    
    }

} // namespace RandomGenerators