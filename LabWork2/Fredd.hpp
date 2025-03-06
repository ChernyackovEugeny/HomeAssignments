/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef FREDD
#define FREDD

#include "Random.hpp"
#include <array>
#include <chrono>
#include <string>

class Game;

/**
 * @brief class describes the behavior of the animatronic "Freddy"
 */
class Fredd {
    friend class Game;

  public:
    Fredd();
    ~Fredd();

  protected:
    void move_anim(Random &gen_rand_, bool door, bool _4b, int time);

    std::array<std::string, 6> way_;
    /// whether animatronic screams or not
    int place_;
    /// where is the animatronic
    bool scream_;

    int stand_time_;
    /// time, which Freddy must be on 4b
    int _4b_time_;
    int time_before_scream_;
    std::chrono::steady_clock::time_point last_move_time_;

    std::array<int, 6> intellegence_;
};

#endif
