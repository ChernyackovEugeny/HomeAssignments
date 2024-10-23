#include "Transformer.hpp"


Transformer::Transformer(std::string label, int armor, int ammo, int courage, int hp) {
    label_ = label;
    armor_ = armor;
    ammo_ = ammo;
    courage_ = courage;
    
    healthpoints_ = Hp(hp);
}

void Transformer::setAmmo(int ammo) {
    ammo_ = ammo;
}
int Transformer::getAmmo() {
    return ammo_;
}

void Transformer::setLabel(std::string label) {
    label_ = label;
}
std::string Transformer::getLabel() {
    return label_;
}

void Transformer::setArmor(int armor) {
    armor_ = armor;
}
int Transformer::getArmor() {
    return armor_;
}

void Transformer::setCourage(int courage) {
    courage_ = courage;
}
int Transformer::getCourage() {
    return courage_;
}


void Transformer::setHp(int hp) {
    healthpoints_.setHp(hp);
}
int Transformer::getHp() {
    return healthpoints_.getHp();
}


void Transformer::setGun(Gun* weap) {
    weapon_ = weap;
}
std::string Transformer::getGun() {
    return weapon_->getGun();
}
   

void Transformer::fire() {
    return;
}
bool Transformer::move() {
    return true;
}

Transformer::~Transformer() {}
