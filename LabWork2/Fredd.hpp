#ifndef FREDD
#define FREDD
#include <array>
#include <string>
#include <chrono>
#include "Random.hpp"

class Game;

class Fredd {
    friend class Game;
    
    public:
        Fredd();
        ~Fredd();
    protected:
        void move_anim(Random& gen_rand_, bool door, bool _4b);
        
        std::array<std::string, 6> way_;
        bool scream_;
        int place_;
        
        int stand_time_;
        int _4b_time_; // время, которое он должен стоять на 4b  
        int time_before_scream_;   
        std::chrono::steady_clock::time_point last_move_time_;
};

#endif
