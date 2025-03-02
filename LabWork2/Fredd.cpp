#include <array>
#include <string>
#include <chrono>
#include "Fredd.hpp"

Fredd::Fredd() : way_({"1A", "1B", "7", "6", "4A", "4B"}), place_(1), scream_(false), stand_time_(0), _4b_time_(30), time_before_scream_(10) {}

void Fredd::move_anim(Random& gen_rand_, bool door, bool _4b) {
    auto cur_time = std::chrono::steady_clock::now();
    if (stand_time_ == 0) {
        stand_time_ = gen_rand_.get_rand(15, 30);
    }
    // если увидели его на 4b обновляем last_move_time_, может стоять на 4b хоть до бесконечности
    if (place_ == 6 and _4b == true) {
        last_move_time_ = std::chrono::steady_clock::now();
    }
    
    // если аниматроник на 4b
    if (place_ == 6 and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() < _4b_time_) {
        // если таймер скримера дотикал и дверь открыта, скримерим
        if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= time_before_scream_ and not door) {
            scream_ = true;
        }
        // если заскримерить не получилось, сразу оттащить назад
        else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= time_before_scream_ and door) {
            place_ = gen_rand_.get_rand(3, 4);
            last_move_time_ = std::chrono::steady_clock::now();
        }
    }
    
    // если простоял отведенное время на 4b и не заскримерил, оттащить аниматроника назад
    else if (place_ == 6 and std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= _4b_time_) {
        place_ = gen_rand_.get_rand(3, 4);
        last_move_time_ = std::chrono::steady_clock::now();
    }
    
    // передвижение до двери
    else if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_move_time_).count() >= stand_time_) {
        if (place_ < 6) {
            place_ += 1; // передвижение на такое кол-во единиц
            last_move_time_ = std::chrono::steady_clock::now();
            stand_time_ = gen_rand_.get_rand(15, 30);
        }
        // если стоит на 4B
        else if (place_ == 6) {
            last_move_time_ = std::chrono::steady_clock::now();
        }
    }
}

Fredd::~Fredd() {}
