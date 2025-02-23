#include "Door.hpp"

Door::Door() : ldoor_close_(false), ldoor_light_(false), rdoor_close_(false), rdoor_light_(false) {}

bool Door::get_rdoor_close() {
    return rdoor_close_;
}

bool Door::get_ldoor_close() {
    return ldoor_close_;
}

Door::~Door() {}
