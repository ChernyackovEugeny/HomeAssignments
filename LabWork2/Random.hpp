#ifndef RANDOM
#define RANDOM

#include <random>

class Game;

class Random {
    friend class Game;
    
    public:
        Random();
        
        int get_rand(int min, int max);
        
        ~Random();
    
    protected:
        std::mt19937 gen;
};

#endif
