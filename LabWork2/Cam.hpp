#ifndef CAM
#define CAM

#include <string>
class Game;

class Cam {
    friend class Game;
    
    public:
        Cam(std::string name);
        Cam();
        ~Cam();
    protected:
    	std::string get_name();
    	
        void watch_cam();
        void get_entities_here();
        
//        std::string picture;
        std::string name_;
};

#endif
