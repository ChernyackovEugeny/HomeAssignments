/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Minigame.hpp"
#include "MiniGoblin.hpp"
#include "MiniMage.hpp"
#include "MiniRogue.hpp"
#include "MiniWarrior.hpp"
#include <iostream>

Minigame::Minigame() {
    std::cout << "Выберите персонажа:" << std::endl;
    std::cout << "1. Воин - сбалансирован, высокая защита." << std::endl;
    std::cout << "2. Маг - мощные атаки, но высокая стоимость маны." << std::endl;
    std::cout << "3. Разбойник - быстрая атака, уклонение." << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        player = new MiniWarrior();
    } else if (choice == 2) {
        player = new MiniMage();
    } else {
        player = new MiniRogue();
    }
    enemy = new MiniGoblin();
}

/// @brief function describes the start of the game
void Minigame::start() {
    std::cout << "Начинается битва!" << std::endl;
    battleSystem.startBattle(*player, *enemy);
}
