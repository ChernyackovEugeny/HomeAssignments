#ifndef PLAYER
#define PLAYER
#include <string>

class Game;
class Player {
    friend class Game;
    
    public:
        Player();
        
        ~Player();
        
    protected:        
        std::string push_nose();
        std::string get_fan();
        void set_fan(bool status);
/*
        void cams(bool cams_status);
        double get_energy();
        
        std::string get_info();
*/
        double cams_up_time_;
        bool cams_status_;
        bool fan_status_;
};

#endif
