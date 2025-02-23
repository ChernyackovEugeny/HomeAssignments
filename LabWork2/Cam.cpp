#include <iostream>
#include <string>
#include "Cam.hpp"

Cam::Cam(std::string name) : name_(name) {}
Cam::Cam() : name_("Unknown") {}

std::string Cam::get_name() {
    return name_;
}

Cam::~Cam() {}
