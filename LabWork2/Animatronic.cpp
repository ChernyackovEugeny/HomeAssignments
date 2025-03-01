#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include "Animatronic.hpp"

Animatronic::Animatronic() : place_(1), scream_(false), time_before_scream_(9), near_door_time_(10), stand_time_(0) {}

void Animatronic::move_anim(Random& gen_rand_, bool door) {
    auto cur_time = std::chrono::steady_clock::now();
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(7, 11);
    }
    // если аниматроник у двери
    if (place_ == way_.size()+1 and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() < near_door_time_) {
        // если дверь закрыта, обновить таймер скримера
        if (door) {
            auto near_opened_door = std::chrono::steady_clock::now();
        }
        
        // если таймер скримера дотикал
        if (not door and std::chrono::duration_cast<std::chrono::seconds>(cur_time - near_opened_door_).count() >= time_before_scream_) {
            // screamer
            scream_ = true;
        }
    }
    
    // если не заскримерил, оттащить аниматроника назад
    else if (place_ == way_.size()+1 and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= near_door_time_) {
        place_ = gen_rand_.get_rand(1, way_.size()-1);
        last_move_time_ = std::chrono::steady_clock::now();
        near_door_time_ = gen_rand_.get_rand(5, 20);
        time_before_scream_ = gen_rand_.get_rand(7, 11);
    }
    
    // передвижение до двери
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= stand_time_) {
        if (place_ <= way_.size()-2) {
            place_ += gen_rand_.get_rand(0, 2); // передвижение на такое кол-во единиц
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(9, 16);
        }
        else if (way_.size()-1 <= place_ <= way_.size()) {
            place_ += gen_rand_.get_rand(0, 1); // передвижение на такое кол-во единиц
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(7, 13);
        }
        if (place_ == way_.size()+1) {
            near_opened_door_ = std::chrono::steady_clock::now();
        }
    }
}

Animatronic::~Animatronic() {}
