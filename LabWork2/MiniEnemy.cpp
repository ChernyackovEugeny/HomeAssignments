#include "MiniEnemy.hpp"
#include <iostream>

MiniEnemy::MiniEnemy(std::string name, int mana, int hp) : MiniPlayer(name, mana, hp) {}

void MiniEnemy::attack(MiniPlayer& target) {
    if (!abilities.empty()) {
        useAbility(0, target);
    }
}
