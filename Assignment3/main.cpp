#include <iostream>
#include <string>
#include "Transformer.hpp"

int main() {
    Transformer a("BumbleBee", 50, 30, 40);
    std::cout << a.getAmmo() << std::endl;
    a.setAmmo(10);
    std::cout << a.getAmmo() << std::endl;
    
    std::cout << a.getHp() << std::endl;
    a.fire();
    
    a.~Transformer();
}
