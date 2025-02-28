#ifndef PHONE
#define PHONE

#include <string>
class Game;

class Phone {
    friend class Game;
    
    public:
        Phone();
        
        bool get_phone_status();
        void set_phone_status(bool status);
        
        std::string introduction();
        
        ~Phone();
    
    protected:
        bool phone_status_;



};





#endif
