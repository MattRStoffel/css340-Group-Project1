#include "UnitTests.h"

int main() {
    UNITTESTS::runTests();

    // Normal Distribution Demo
    std::cout << std::endl << "Random Normal Distribution" << std::endl << std::endl;

    std::vector<int> testData;
    std::stringstream ss1;

    testData = RandomGenerators::generateRandomNormalDistInts(100000, 0, 100);
    RandomGenerators::printHistogram(ss1, testData, 100, 10, '0');
    std::cout << ss1.str() << std::endl;

    // Uniform Distribution Demo
    std::cout << "Random Uniform Distribution" << std::endl << std::endl;

    std::vector<float> testDataUniform;
    std::stringstream ss2;

    testDataUniform = RandomGenerators::generateRandomUniformDistFloats(20000, 1, 200);
    RandomGenerators::printHistogram(ss2, testDataUniform, 20, 10, '0');
    std::cout << ss2.str() << std::endl << std::endl;



    // Kth value demo
    std::cout << "Kth value" << std::endl << std::endl;

    std::vector<int> input = {3, 1 ,0, 4, 5, 12};
    std::cout << "Input: {3, 1 ,0, 4, 5, 12}" << std::endl << std::endl;

    int k = 5;
    int val = MySortingLibrary::QuickSelect(input, k);
    std::cout << "The k=" << k << " value is: " << val << std::endl;

    k = 3;
    val = MySortingLibrary::QuickSelect(input, k);
    std::cout << "The k=" << k << " value is: " << val << std::endl;

    return 0;
}
