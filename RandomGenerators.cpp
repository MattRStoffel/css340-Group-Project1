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

 

} // namespace RandomGenerators