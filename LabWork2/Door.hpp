#ifndef DOOR
#define DOOR

class Game;

class Door {
    friend Game;
    
    public:
        Door();
        
        bool get_light_status();
        bool get_close_status();
        
        ~Door();
        
    protected:
    	void set_light_status(bool status);
        void set_close_status(bool status);
    
        bool door_close_;
        bool door_light_;


};

#endif
