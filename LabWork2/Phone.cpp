#include "Phone.hpp"
#include <string>

Phone::Phone() : phone_status_(false) {}

bool Phone::get_phone_status() {
    return phone_status_;
}

void Phone::set_phone_status(bool status) {
    phone_status_ = status;
}

std::string Phone::introduction() {
    return "Here is your introduction";
}

Phone::~Phone() {}
