#ifndef MINIENEMY
#define MINIENEMY

#include "MiniPlayer.hpp"

class MiniEnemy : public MiniPlayer {
    public:
        MiniEnemy(std::string name, int mana, int hp);
        void attack(MiniPlayer& target);
};

#endif
