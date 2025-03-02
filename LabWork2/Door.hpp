#ifndef DOOR
#define DOOR

class Game;

class Door {
    friend Game;
    
    public:
        Door();
        ~Door();
        
    protected:
        bool door_close_;
        bool door_light_;
};

#endif
