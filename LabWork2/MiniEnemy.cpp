/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "MiniEnemy.hpp"
#include <iostream>

MiniEnemy::MiniEnemy(std::string name, int mana, int hp) : MiniPlayer(name, mana, hp) {}

/// @brief function describes the attack of the enemy
void MiniEnemy::attack(MiniPlayer& target) {
    if (!abilities.empty()) {
        useAbility(0, target);
    }
}
