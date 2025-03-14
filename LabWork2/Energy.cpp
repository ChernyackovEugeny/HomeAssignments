/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Energy.hpp"
#include <chrono>

#include <iostream>

Energy::Energy() : cur_energy_(100), energy_psecond_(0.08), energy_mult_(1) {
}

/// @brief function changes the player's energy
/// @param last_time shows the last saved time

void Energy::change_energy(std::chrono::steady_clock::time_point last_time) {
    auto cur_time = std::chrono::steady_clock::now();

    cur_energy_ -=
        (energy_psecond_ * energy_mult_) *
        std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_time).count();
}

Energy::~Energy() {
}
