/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/

#include "Autobots.hpp"

Autobots::Autobots(std::string label, int armor, int ammo, int courage, int hp, int rarm, int larm)
    : Transformer(label, armor, ammo, courage, hp), rarm_(rarm), larm_(larm) {
}

Autobots::Autobots() {
    Transformer();
}

void Autobots::Optransform() {
    std::cout << "class Autobots -> Optransform" << std::endl;
}
void Autobots::Opfire() {
    std::cout << "class Autobots -> Opfire" << std::endl;
}
void Autobots::Ophide() {
    std::cout << "class Autobots -> Ophide" << std::endl;
}

int Autobots::getRarm() {
    return rarm_;
}
void Autobots::setRarm(int arm) {
    rarm_ = arm;
}
int Autobots::getLarm() {
    return larm_;
}
void Autobots::setLarm(int arm) {
    larm_ = arm;
}

bool Autobots::transform() {
    return true;
}
bool Autobots::pikpik() {
    return false;
}

Autobots::~Autobots() {
}
