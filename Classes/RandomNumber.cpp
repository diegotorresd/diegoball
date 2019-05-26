//
//  RandomNumber.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "RandomNumber.hpp"
#include <random>

float RandomNumber::generate(float a, float b) {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(a, b);
    return dis(gen);
}
