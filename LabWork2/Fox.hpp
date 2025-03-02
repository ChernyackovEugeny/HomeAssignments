#ifndef FOX
#define FOX
#include <array>
#include <string>
#include <chrono>
#include "Random.hpp"

class Game;

class Fox {
    friend class Game;
    
    public:
        Fox();
        ~Fox();
    
    protected:
        void move_anim(Random& gen_rand_, bool left_door, int time);
        
        std::array<int, 6> intellegence_;
        std::array<std::string, 2> way_;
        int place_; 
        int stage_; // from 1 to 5 
        bool scream_;
        
        int stand_time_; // время между стадиями
        int running_time_; // время бега на 2A (до смерти)
        std::chrono::steady_clock::time_point last_move_time_; // время перехода на A2
};

#endif
