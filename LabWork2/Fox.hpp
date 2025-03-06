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

/**
 * @brief class describes the behavior of the animatronic "Foxy"
 */
class Fox {
    friend class Game;

  public:
    Fox();
    ~Fox();

  protected:
    void move_anim(Random &gen_rand_, bool left_door, int time);

    std::array<int, 6> intellegence_;
    std::array<std::string, 2> way_;
    /// where is the animatronic
    int place_;
    /// the stage of Foxy from 1 to 5
    int stage_;
    /// whether animatronic screams or not
    bool scream_;

    /// time between stages
    int stand_time_;
    /// time of running on 2A (before death)
    int running_time_;
    /// timing of coming to 2A
    std::chrono::steady_clock::time_point last_move_time_;
};

#endif
