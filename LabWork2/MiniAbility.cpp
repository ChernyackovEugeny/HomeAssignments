#include "MiniAbility.hpp"

MiniAbility::MiniAbility(std::string name, int damage, int manaCost) : name(name), damage(damage), manaCost(manaCost) {}

std::string MiniAbility::getName() const {
    return name;
}
int MiniAbility::getDamage() const {
    return damage;
}
int MiniAbility::getManaCost() const {
    return manaCost;
}
