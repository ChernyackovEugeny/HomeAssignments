#include <iostream>
#include "Gun.hpp"
#include <string>

Gun::Gun(std::string name) {
    gun_name_ = name;
}
void setGun(std::string gun) {
    gun_name_ = gun;
}
std::string getGun() {
    return gun_name_;
}

