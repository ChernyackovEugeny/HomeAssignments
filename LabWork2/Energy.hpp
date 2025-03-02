#ifndef ENERGY
#define ENERGY

#include <chrono>

class Game;

class Energy {
    friend class Game;
    
    public:
        Energy();
        ~Energy();
    
    protected:
        void change_energy(std::chrono::steady_clock::time_point last_time);
        
        double cur_energy_;
        double energy_psecond_;
        int energy_mult_;
        
};

#endif
