/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIBATTLESYSTEM
#define MINIBATTLESYSTEM

#include "MiniPlayer.hpp"
#include "MiniEnemy.hpp"

/**
 * @brief class describes the battle system
 */
class MiniBattleSystem {
    public:
        void startBattle(MiniPlayer& player, MiniEnemy& enemy);
};

#endif
