#include <iostream>
#include <string>
#include "Transformer.hpp"
#include "deceptikon.hpp"

int main() {

    Gun gun("Mikich");
	
    Transformer a("BumbleBee", 50, 30, 40, 100);
    std::cout << a.getAmmo() << std::endl;
    a.setAmmo(10);
    std::cout << a.getAmmo() << std::endl;
    
    a.setHp(10);
    
    std::cout << a.getHp() << std::endl;
    a.fire();
    
    a.setGun(&gun);
    std::cout << a.getGun() << std::endl;
    
    Deceptikon b("BumbleBee", 50, 30, 40, 100, 99, 89);
    std::cout << b.getRleg() << " " << b.getHp() << std::endl;
    
    a.~Transformer();

}
