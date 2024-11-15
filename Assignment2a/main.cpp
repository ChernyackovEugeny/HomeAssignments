/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 2a
*/

#include <iostream>
#include <string>

#include "reversedata.hpp"

int main() {
    std::string name;
    std::cout << "Please, enter the name of your file to be reversed." << std::endl;
    std::cin >> name;

    reversedata(name);
    return 1;
}
