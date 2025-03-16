/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIGAME
#define MINIGAME

#include "MiniPlayer.hpp"
#include "MiniEnemy.hpp"
#include "MiniBattleSystem.hpp"

/**
 * @brief class describes the mini-game
 */
class Minigame {
    public:
        Minigame();
        void start();
    private:
        MiniBattleSystem battleSystem;
        MiniPlayer* player;
        MiniEnemy* enemy;
};

#endif
