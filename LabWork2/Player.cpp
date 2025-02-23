#include "Player.hpp"

Player::Player() : cams_status_(false), fan_status_(true) {}
/*
double Player::get_enegy() {
    return energy_;
}
*/
std::string Player::push_nose() {
    return "beep-beep";
}
std::string Player::get_fan() {
    if (fan_status_) {
        return "fan on";
    } return "fan off";
}
void Player::set_fan(bool status) {
    fan_status_ = status;
}

Player::~Player() {}
