#ifndef DOOR
#define DOOR

class Game;

class Door {
    friend Game;
    
    public:
        Door();
        ~Door();
        
    protected:
        bool get_rdoor_close();
        bool get_ldoor_close();
        
        bool ldoor_close_;
        bool ldoor_light_;
        bool rdoor_close_;
        bool rdoor_light_;

};

#endif
