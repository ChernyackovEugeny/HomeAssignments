/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef FOX
#define FOX

#include "Random.hpp"
#include <array>
#include <chrono>
#include <string>

class Game;

class Fox {
    friend class Game;

  public:
    Fox();
    ~Fox();

  protected:
    void move_anim(Random &gen_rand_, bool left_door, int time);

    std::array<int, 6> intellegence_;
    std::array<std::string, 2> way_;
    int place_;
    int stage_; // from 1 to 5
    bool scream_;

    int stand_time_;   // time between stages
    int running_time_; // time of running on 2A (before death)
    std::chrono::steady_clock::time_point last_move_time_; // timing of coming to 2A
};

#endif
