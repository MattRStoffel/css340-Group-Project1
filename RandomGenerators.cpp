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

} // namespace RandomGenerators