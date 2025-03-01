#include "Fox.hpp"
#include <array>
#include <string>
#include <chrono>

Fox::Fox() {
    way_ = {"1C", "2A"};
    place_ = 1;
    stage_ = 1;
    scream_ = false;
    stand_time_ = 0;
    running_time_ = 10;
}

void Fox::move_anim(Random& gen_rand_, bool left_door) {
    auto cur_time = std::chrono::steady_clock::now();
    // для первой итерации
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(13, 20);
    }
    
    
    // игрок заметил Фокси на камере во время бега?
    
    
    // если время бега на 2A прошло, игрок не на камерах
    if (place_ == 2 and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() > running_time_) {
        // если дверь открыта, конец
        if (not left_door) {
            scream_ = true;
        }
        
        // если закрыта, оттащить Фокси на 1C
        else if (left_door) {
            place_ = 1;
            last_move_time_ = std::chrono::steady_clock::now();
            stage_ = gen_rand_.get_rand(1, 2);
            stand_time_ = gen_rand_.get_rand(13, 20);
        }
    }

    // изменение стадий на 1C
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= stand_time_) {
        if (stage_ <= 3) {
            stage_ += 1; // переход стадии
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(13, 20);
        }
        if (stage_ == 4) {
            place_ = 2;
            last_move_time_ = std::chrono::steady_clock::now(); // начало выхода фокси из 1C
        }
    }
}

Fox::~Fox() {}
