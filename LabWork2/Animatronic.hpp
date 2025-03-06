/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef ANIMATRONIC
#define ANIMATRONIC

#include "Random.hpp"
#include <array>
#include <chrono>
#include <string>
#include <vector>

class Game;

/**
 * @brief class describes the behavior of animatronic
 */
class Animatronic {
    friend class Game;

  public:
    Animatronic();

    ~Animatronic();

  protected:
    void move_anim(Random &gen_rand_, bool door, int time);

    std::array<int, 6> intellegence_;
    std::vector<std::string> way_;
    /// whether animatronic screams or not
    bool scream_;
    /// where is the animatronic
    int place_;

    int time_before_scream_;
    int near_door_time_;
    int stand_time_;
    std::chrono::steady_clock::time_point last_move_time_;
    std::chrono::steady_clock::time_point near_opened_door_;
};

#endif
