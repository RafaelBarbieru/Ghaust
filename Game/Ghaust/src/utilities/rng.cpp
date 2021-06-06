#include <stdafx.h>
#include "rng.h"

/*
    @return unsigned short int

    I don't even know what this is, but I took it from:
    https://stackoverflow.com/a/31091422
*/
unsigned short int RNG::btw0And1()
{
    std::mt19937_64 range;

    // Initializing the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
    range.seed(ss);

    // Initializing a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 2);

    // Returning the randomly generated number;
    return unif(range);
}
