#ifndef ANIMATRONIC
#define ANIMATRONIC
#include <vector>
#include <string>
#include <chrono>
#include "Random.hpp"

class Game;

class Animatronic {
    friend class Game;
    
    public:
        Animatronic();
        
        ~Animatronic();

    protected:
        void move_anim(Random& gen_rand_, bool left_door);
    
        std::vector<std::string> way_;
        bool scream_;
        int place_;
        
        std::chrono::steady_clock::time_point last_move_time_;
        std::chrono::steady_clock::time_point near_opened_door_;
        int stand_time_;
        int time_before_scream_;
        int near_door_time_;
};


#endif
