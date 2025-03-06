/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Fox.hpp"
#include <array>
#include <chrono>
#include <string>

Fox::Fox() {
    way_ = {"1C", "2A"};
    place_ = 1;
    stage_ = 1;
    scream_ = false;
    stand_time_ = 0;
    running_time_ = 10;
}

/// @brief function moves the animatronic "Foxy"
/// @param gen_rand_ to get random numbers
/// @param left_door to check whether the door is opened or not
/// @param time for checking the intellegence of animatronic
void Fox::move_anim(Random &gen_rand_, bool left_door, int time) {
    auto cur_time = std::chrono::steady_clock::now();

    // calculation of intellegence of the animatronic, if intellegence equals zero the animatronic
    // is off
    if (intellegence_[time] == 0) {
        return;
    }
    int min_time = 30 - intellegence_[time];
    int max_time = 40 - 2 * intellegence_[time];

    // for the first iteration
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
    }

    // if running time on 2A is out, the player is not on cams
    if (place_ == 2 and
        std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >
            running_time_) {
        // if the door is opened, scream
        if (not left_door) {
            scream_ = true;
        }

        // if the door is closed, move Foxy to 1C
        else if (left_door) {
            place_ = 1;
            last_move_time_ = std::chrono::steady_clock::now();
            stage_ = gen_rand_.get_rand(1, 2);
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
    }

    // changing stages on 1C
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >=
             stand_time_) {
        if (stage_ <= 3) {
            // changing stage
            stage_ += gen_rand_.get_rand(0, 1);
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
        if (stage_ == 4) {
            // Foxy is going to 2A
            place_ = 2;
            last_move_time_ = std::chrono::steady_clock::now();
        }
    }
}

Fox::~Fox() {
}
