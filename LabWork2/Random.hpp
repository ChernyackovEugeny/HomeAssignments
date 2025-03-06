/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef RANDOM
#define RANDOM

#include <random>

class Game;
class Animatronic;

/**
 * @brief class is used to get random numbers
 */
class Random {
    friend class Game;
    friend class Animatronic;

  public:
    Random();

    int get_rand(int min, int max);

    ~Random();

  protected:
    std::mt19937 gen;
};

#endif
