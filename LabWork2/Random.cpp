/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Random.hpp"
#include <random>

Random::Random() : gen(std::random_device{}()) {
}

int Random::get_rand(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

Random::~Random() {
}
