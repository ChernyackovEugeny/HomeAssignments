#ifndef MINIABILITY
#define MINIABILITY

#include <string>

class MiniAbility {
public:
    MiniAbility(std::string name, int damage, int manaCost);
    std::string getName() const;
    int getDamage() const;
    int getManaCost() const;
private:
    std::string name;
    int damage;
    int manaCost;
};

#endif
