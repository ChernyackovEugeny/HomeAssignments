#ifndef PHONE
#define PHONE

#include <string>
class Game;

class Phone {
    friend class Game;
    
    public:
        Phone();
        ~Phone();
    
    protected:
        void introduction();
};

#endif
