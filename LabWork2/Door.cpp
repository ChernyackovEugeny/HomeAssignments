#include "Door.hpp"

Door::Door() : door_close_(false), door_light_(false) {}

bool Door::get_light_status() {
    return door_light_;
}

bool Door::get_close_status() {
    return door_close_;
}

void Door::set_light_status(bool status) {
    door_light_ = status;
}

void Door::set_close_status(bool status) {
    door_close_ = status;
}

Door::~Door() {}
