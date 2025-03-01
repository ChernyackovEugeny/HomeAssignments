#include "Player.hpp"

Player::Player() : cams_status_(false), fan_status_(true) {}

std::string Player::push_nose() {
    return "beep-beep";
}

Player::~Player() {}
