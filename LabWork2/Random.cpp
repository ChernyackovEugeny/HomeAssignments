/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Random.hpp"
#include <random>

Random::Random() : gen(std::random_device{}()) {
}

/// @brief function is used to get random numbers
/// @param min left border
/// @param max right border
/// @return random number between left and right borders
int Random::get_rand(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

Random::~Random() {
}
