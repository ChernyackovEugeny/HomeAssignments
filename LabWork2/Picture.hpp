#ifndef PICTURE
#define PICTURE
#include <string>

class Game;

class Picture {
    friend class Game;
    
    public:
        Picture();
        ~Picture();
        
    protected:
        void show_picture(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage, bool freddy);
        void show_scream(int scream);
        
        void show_text(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage, bool freddy);
        void show_text_scream(int scream);
    
        bool accept_picture_;
};

#endif
