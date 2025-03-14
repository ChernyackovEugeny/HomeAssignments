#ifndef MINIBATTLESYSTEM
#define MINIBATTLESYSTEM

#include "MiniPlayer.hpp"
#include "MiniEnemy.hpp"

class MiniBattleSystem {
public:
    void startBattle(MiniPlayer& player, MiniEnemy& enemy);
};

#endif
