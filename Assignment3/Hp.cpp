#include <iostream>
#include <string>
#include "Hp.hpp"

Hp::Hp(int healthpoints) {
    healthpoints_ = healthpoints;
}
int Hp::getHp() {
    return healthpoints_;
}
void Hp::setHp(int hp) {
    healthpoints_ = hp;
}
Hp::~Hp() {}

int healthpoints_;

