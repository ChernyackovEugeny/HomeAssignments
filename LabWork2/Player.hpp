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

        bool cams_status_;
        bool fan_status_;
};

#endif
