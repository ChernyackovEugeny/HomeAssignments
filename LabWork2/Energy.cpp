#include "Energy.hpp"
#include <chrono>

Energy::Energy() : cur_energy_(100), energy_psecond_(0.1), energy_mult_(1) {}

void Energy::change_energy(std::chrono::steady_clock::time_point last_time) {
    // имеем предыдущее cur_time и energy_psecond
    auto cur_time = std::chrono::steady_clock::now();
    
    cur_energy_ -= (energy_psecond_ * energy_mult_) * (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_time).count() + 1);
}

Energy::~Energy() {}
