#include "RandomGenerators.h"
#include <random>
#include <iostream>

namespace RandomGenerators {

    // Implement your functions or classes here

    // Function to create random set of integers based on the Normal distribution
    // returns vector of random integers based that fit a normal distribution
    // using a vector instead of an array to avoid passing array pointer as a parameter (arrays can't be returned directly in c++)
    std::vector<int> generateRandomNormalDistInts(int count, double mean, double std_dev) {

        if(count < 1 || std_dev <= 0) {
            std::cerr << "count must be greater than 1 and standard deviation must be greater than 0" << std::endl;
        }

        std::default_random_engine rd;
        std::mt19937 generator(rd());
        std::normal_distribution<> dist(mean, std_dev);

        std::vector<int> numbers(count);

        for (int n = 0; n < count; n++) {
            numbers[n] = static_cast<int>(dist(generator));
        }

        return numbers;
    }

} // namespace RandomGenerators