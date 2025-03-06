/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Player.hpp"

Player::Player() : cams_status_(false), fan_status_(true) {
}

/// @brief function pushes the Freddy's nose
/// @return returns the Freddy's nose sound
std::string Player::push_nose() {
    return "beep-beep";
}

Player::~Player() {
}
