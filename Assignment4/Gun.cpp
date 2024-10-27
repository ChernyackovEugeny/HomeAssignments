// realisation of the class with association

#include "Gun.hpp"

Gun::Gun(std::string name) {
    gun_name_ = name;
}
void Gun::setGun(std::string gun) {
    gun_name_ = gun;
}
std::string Gun::getGun() {
    return gun_name_;
}
Gun::~Gun() {}

