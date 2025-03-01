#ifndef PHONE
#define PHONE

#include <string>
class Game;

class Phone {
    friend class Game;
    
    public:
        Phone();
        
        void introduction();
        
        ~Phone();
    
    protected:
        bool phone_status_;
};





#endif
