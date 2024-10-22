#include <iostream>
#include "Hp.hpp"
#include <string>
Hp::Hp() {}
Hp::Hp(int hp) {
    hps_ = hp;
}
int Hp::getHp() {
    return hps_;
}
void Hp::setHp(int hp) {
    hps_ = hp;
}
Hp::~Hp() {}
