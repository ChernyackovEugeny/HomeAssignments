/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIPLAYER
#define MINIPLAYER

#include "MiniAbility.hpp"
#include <vector>
#include <string>

/**
 * @brief class describes the player
 */
class MiniPlayer {
public:
    MiniPlayer(std::string name, int mana, int hp);
    virtual ~MiniPlayer() = default;

    void addAbility(const MiniAbility& ability);
    void useAbility(int index, MiniPlayer& target);
    int getMana() const;
    int getHP() const;
    const std::vector<MiniAbility>& getAbilities() const;
    
    std::string getName() const;
    void takeDamage(int damage);

protected:
    std::string name;
    int mana;
    int hp;
    std::vector<MiniAbility> abilities;
};

#endif
