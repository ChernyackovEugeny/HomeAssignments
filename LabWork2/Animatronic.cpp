#include <vector>
#include <string>
#include <chrono>
#include <array>
#include "Animatronic.hpp"

Animatronic::Animatronic() : scream_(false), place_(1), time_before_scream_(9), near_door_time_(12), stand_time_(0) {}

void Animatronic::move_anim(Random& gen_rand_, bool door, int time) {
    auto cur_time = std::chrono::steady_clock::now();
    
    //вычисляем скорость аниматроников по их интеллекту, при нуле аниматроник выключен
    if (intellegence_[time] == 0) {
    	return;
    }
    int min_time = 20 - intellegence_[time];
    int max_time = 30 - 2*intellegence_[time];
    
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
    }
    // если аниматроник у двери
    if (place_ == int(way_.size()+1) and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() < near_door_time_) {
        // если дверь закрыта, обновить таймер скримера
        if (door) {
            near_opened_door_ = std::chrono::steady_clock::now();
        }
        
        // если таймер скримера дотикал
        if (not door and std::chrono::duration_cast<std::chrono::seconds>(cur_time - near_opened_door_).count() >= time_before_scream_) {
            // screamer
            scream_ = true;
        }
    }
    
    // если не заскримерил, оттащить аниматроника назад
    else if (place_ == int(way_.size()+1) and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= near_door_time_) {
        place_ = gen_rand_.get_rand(2, way_.size()-1);
        last_move_time_ = std::chrono::steady_clock::now();
        near_door_time_ = gen_rand_.get_rand(5, 20);
        time_before_scream_ = gen_rand_.get_rand(7, 11);
        stand_time_ = gen_rand_.get_rand(min_time, max_time);
    }
    
    // передвижение до двери
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= stand_time_) {
        if (place_ <= int(way_.size()-2)) {
            place_ += gen_rand_.get_rand(0, 2); // передвижение на такое кол-во единиц
            last_move_time_ = std::chrono::steady_clock::now();
            
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
        else if (int(way_.size()-1) <= place_ and place_ <= int(way_.size())) {
            place_ += gen_rand_.get_rand(0, 1); // передвижение на такое кол-во единиц
            last_move_time_ = std::chrono::steady_clock::now();
            
            stand_time_ = gen_rand_.get_rand(min_time, max_time);
        }
        if (place_ == int(way_.size()+1)) {
            near_opened_door_ = std::chrono::steady_clock::now();
        }
    }
}

Animatronic::~Animatronic() {}
