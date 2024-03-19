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
    void histogram(std::ostream& os, const std::vector<T>& v, int ubins = 0, int binWidth = 0);

}

#endif // RANDOM_GENERATORS_H
