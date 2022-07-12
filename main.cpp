
#include <iostream>
#include <random>
#include <array>
#include <algorithm>
#include <functional>

/**
 * a function that will generate pseudo random numbers in a normal distribution
 * @param lb  is the lower bound of the distribution (inclusive)
 * @param ub  is the upper bound of the distribution (inclusive)
 * @return  a pseudo random number in the range [lb, ub]
 */
auto generate_random_double(double lb, double ub)
{
    std::random_device rd{};
    std::array<double, std::mt19937::state_size> seed_data{};
    std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937{ seq };
    const auto randDouble = std::uniform_real_distribution<>{ lb,ub };
    return std::bind(randDouble, eng);
}

int main() {
    // use to generate random numbers, 100 of them
    auto rand_double = generate_random_double(0, 100);
    for (int i = 0; i < 100; i++) {
        std::cout << rand_double() << std::endl;
    }
    return 0;
}
