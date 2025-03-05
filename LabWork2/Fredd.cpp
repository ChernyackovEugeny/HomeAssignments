/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Fredd.hpp"
#include <array>
#include <chrono>
#include <string>

Fredd::Fredd()
    : way_({"1A", "1B", "7", "6", "4A", "4B"}), place_(1), scream_(false), stand_time_(0),
      _4b_time_(30), time_before_scream_(10) {
}

void Fredd::move_anim(Random &gen_rand_, bool door, bool _4b, int time) {
    auto cur_time = std::chrono::steady_clock::now();

    // calculation of intellegence of the animatronic, if intellegence equals zero the animatronic
    // is off
    if (intellegence_[time] == 0) {
        return;
    }
    int min_time = 30 - intellegence_[time];
    int max_time = 40 - 2 * intellegence_[time];

    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
    }
    // if player see Freddy on 4B, update last_move_time_, Freddy can be on 4B constantly
    if (place_ == 6 and _4b == true) {
        last_move_time_ = std::chrono::steady_clock::now();
    }

    // if Freddy on 4B
    if (place_ == 6 and
        std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() <
            _4b_time_) {
        // if it's screamer timing and the door is opened
        if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >=
                time_before_scream_ and
            not door) {
            scream_ = true;
        }
        // if Freddy didn't scream, move him back
        else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_)
                         .count() >= time_before_scream_ and
                 door) {
            place_ = gen_rand_.get_rand(3, 4);
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
    }

    // if Freddy stood on 4B all the time and didn't scream, move him back
    else if (place_ == 6 and
             std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >=
                 _4b_time_) {
        place_ = gen_rand_.get_rand(3, 4);
        last_move_time_ = std::chrono::steady_clock::now();
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
    }

    // moving to the door
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >=
             stand_time_) {
        if (place_ < 6) {
            // move
            place_ += 1;
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
        // if Freddy on 4B
        else if (place_ == 6) {
            last_move_time_ = std::chrono::steady_clock::now();
        }
    }
}

Fredd::~Fredd() {
}
