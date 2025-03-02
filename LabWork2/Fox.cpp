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

void Fox::move_anim(Random& gen_rand_, bool left_door, int time) {
    auto cur_time = std::chrono::steady_clock::now();
    
    //вычисляем скорость аниматроников по их интеллекту, при нуле аниматроник выключен
    if (intellegence_[time] == 0) {
    	return;
    }
    int min_time = 30 - intellegence_[time];
    int max_time = 40 - 2*intellegence_[time];
    
    // для первой итерации
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
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
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
    }

    // изменение стадий на 1C
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= stand_time_) {
        if (stage_ <= 3) {
            stage_ += gen_rand_.get_rand(0, 1); // переход стадии
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
        if (stage_ == 4) {
            place_ = 2;
            last_move_time_ = std::chrono::steady_clock::now(); // начало выхода фокси из 1C
        }
    }
}

Fox::~Fox() {}
