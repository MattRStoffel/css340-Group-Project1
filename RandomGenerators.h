#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H

#include <vector>

namespace RandomGenerators {

    // Function to create random set of integers based on the Normal distribution
    // returns vector of random integers based that fit a normal distribution
    // using a vector instead of an array to avoid passing array pointer as a parameter (arrays can't be returned directly in c++)
    std::vector<int> generateRandomNormalDistInts(int count, double mean, double std_dev);

}

#endif // RANDOM_GENERATORS_H
