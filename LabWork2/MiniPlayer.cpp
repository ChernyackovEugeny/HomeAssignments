/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "MiniPlayer.hpp"
#include <iostream>

MiniPlayer::MiniPlayer(std::string name, int mana, int hp) : name(name), mana(mana), hp(hp) {}

/// @brief function describes the adding of ability
void MiniPlayer::addAbility(const MiniAbility& ability) {
    abilities.push_back(ability);
}

/// @brief function describes the usage of ability
void MiniPlayer::useAbility(int index, MiniPlayer& target) {
    if (index >= 0 and index < int(abilities.size()) and mana >= abilities[index].getManaCost()) {
        mana -= abilities[index].getManaCost();
        int damage = abilities[index].getDamage();
        target.takeDamage(damage);
        std::cout << name << " использует " << abilities[index].getName() 
                  << ", нанося " << damage << " урона " << target.getName() << "!" << std::endl;
    } else {
        std::cout << name << " не может использовать эту способность!" << std::endl;
    }
}

int MiniPlayer::getMana() const {
    return mana;
}
int MiniPlayer::getHP() const {
    return hp;
}
const std::vector<MiniAbility>& MiniPlayer::getAbilities() const {
    return abilities;
}

std::string MiniPlayer::getName() const {
    return name;
}

void MiniPlayer::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    std::cout << name << " получает " << damage << " урона! Осталось HP: " << hp << std::endl;
}
