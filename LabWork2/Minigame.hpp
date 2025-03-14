#ifndef MINIGAME
#define MINIGAME

#include "MiniPlayer.hpp"
#include "MiniEnemy.hpp"
#include "MiniBattleSystem.hpp"

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
