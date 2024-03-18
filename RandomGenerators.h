#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H

#include <vector>
#include <random>

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

}

#endif // RANDOM_GENERATORS_H
