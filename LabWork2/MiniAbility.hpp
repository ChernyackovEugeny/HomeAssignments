/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIABILITY
#define MINIABILITY

#include <string>

/**
 * @brief class describes the abilities
 */
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
