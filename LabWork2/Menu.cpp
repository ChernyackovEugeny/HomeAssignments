/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Menu.hpp"
#include <fstream>
#include <iostream>
#include <string>

Menu::Menu() {
    picture_check();
}

/// @brief menu of the game
void Menu::menu() {
    night_check();
    start_night();
}

/// @brief function check whether the game will show pictures or not
void Menu::picture_check() {
    std::cout << "Welcome to game!" << std::endl;
    std::cout << "Can you, please, extand your terminal to full screan? We need to check a picture"
              << std::endl;
    std::cout << "Enter enything when you are ready to see the picture" << std::endl;
    std::string a;
    std::cin >> a;

    std::ifstream file("arts/test.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "If you see the picture well enter 'Yes', otherwise enter 'No'" << std::endl;

    std::cin >> a;
    while (a != "Yes" and a != "No") {
        std::cout << "If you see the picture well enter 'Yes', otherwise enter 'No'" << std::endl;
        std::cin >> a;
    }

    if (a == "Yes") {
        show_pict_ = true;
    } else if (a == "No") {
        show_pict_ = false;
    }
}

/// @brief function checks the number of night
void Menu::night_check() {
    std::cout << "Enter the number of the night you want to play(the number from 1 to 5)"
              << std::endl;
    std::cout << "The difficulty of the night grows with the number of the night" << std::endl;

    std::string a;
    std::cin >> a;
    while (true) {
        try {
            if (std::stoi(a) >= 1 and std::stoi(a) <= 5) {
                num_night_ = std::stoi(a);
                break;
            } else {
                std::cout << "The number is out of range" << std::endl;
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "It's not a number" << std::endl;
        } catch (const std::out_of_range &e) {
            std::cout << "The number is out of range" << std::endl;
        }
        std::cout << "Enter the number of the night you want to play(the number from 1 to 5)"
                  << std::endl;
        std::cin >> a;
    }
}

/// @brief function starts the night
void Menu::start_night() {
    Game a(num_night_, show_pict_);
    a.start_game();
}

Menu::~Menu() {
}
