// realisation of inherited class of Transformer

#include "Autobots.hpp"

Autobots::Autobots(std::string label, int armor, int ammo, int courage, int hp, int rarm, int larm) : Transformer(label, armor, ammo, courage, hp), rarm_(rarm), larm_(larm) {}

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

Autobots::~Autobots() {}

