/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "MiniBattleSystem.hpp"
#include <iostream>

/// @brief function describes the battle
void MiniBattleSystem::startBattle(MiniPlayer& player, MiniEnemy& enemy) {
    std::cout << "Битва начинается! Ваш противник: " << enemy.getName() << " (HP: " << enemy.getHP() << ")" << std::endl;

    while (player.getHP() > 0 and enemy.getHP() > 0) {
        std::cout << "Выберите способность:" << std::endl;
        for (size_t i = 0; i < player.getAbilities().size(); ++i) {
            std::cout << i << ". " << player.getAbilities()[i].getName() 
                      << " (Мана: " << player.getAbilities()[i].getManaCost() 
                      << ", Урон: " << player.getAbilities()[i].getDamage() << ")" << std::endl;
        }
        int choice;
        std::cin >> choice;
        player.useAbility(choice, enemy);
        if (enemy.getHP() <= 0) {
            std::cout << "Поздравляем! Вы победили" << enemy.getName() << "!";
            break;
        }
        enemy.attack(player);
        if (player.getHP() <= 0) {
            std::cout << "Вы проиграли! " << enemy.getName() << " оказался сильнее.";
            break;
        }
    }
}
