/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIENEMY
#define MINIENEMY

#include "MiniPlayer.hpp"

/**
 * @brief class describes the enemy
 */
class MiniEnemy : public MiniPlayer {
    public:
        MiniEnemy(std::string name, int mana, int hp);
        void attack(MiniPlayer& target);
};

#endif
