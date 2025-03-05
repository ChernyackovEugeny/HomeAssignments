/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Phone.hpp"
#include <fstream>
#include <iostream>
#include <string>

Phone::Phone() {
}

void Phone::introduction() {
    std::cout << "Hello there, check out the conrols:" << std::endl;
    std::cout << "'lld' or 'light left door'; 'lrd' or 'light right door' to check entities near "
                 "the office's doors"
              << std::endl;
    std::cout
        << "'cld' or 'close left door'; 'crd' or 'close right door' to close the office's doors"
        << std::endl;
    std::cout
        << "'unlld' or 'unlight left door'; 'unlrd' or 'unlight right door' to turn off the light"
        << std::endl;
    std::cout << "'old' or 'open left door'; 'ord' or 'open right door' to open the office's doors"
              << std::endl;
    std::cout
        << "'cams on' or 'con' to enter the cams mode; 'cams off' or 'coff' to escape the cams mode"
        << std::endl;
    std::cout << "'info' to check out the information about your energy and doors" << std::endl;
    std::cout << "'push a nose' to push the Freddy's nose!!!" << std::endl;
    std::cout << "'fan on' or 'fan off' to control the fan, maybe it's too cold..." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "That's all about controls, but there is something you have to do..." << std::endl;
    std::cout << "The are 4 animatronics and soon they will go after you: Bonnie, Chica, Freddy "
                 "and Foxy. You can look at them on the cameras. Foxy is different, he can run, "
                 "look after him more careful. Don't forget to light the doors, you will see the "
                 "animatronic near the door, and if you don't close it, you wiil be killed"
              << std::endl;
    std::cout << "And just have fun!" << std::endl;

    std::cout << "To escape the instruction input anything, the game will start." << std::endl;
    std::string a;
    std::cin >> a;
    std::cout << "The game is started, look after animatronics" << std::endl;
}

Phone::~Phone() {
}
