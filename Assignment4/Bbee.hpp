// header of inherited class of Transformer

#ifndef BBEE
#define BBEE
#include "Transformer.hpp"

class Bbee : public Transformer {
    public:
        Bbee(std::string label, int armor, int ammo, int courage, int hp, int rear, int lear);
        int getRear() const;
        void setRear(int ear);
        
        int getLear() const;
        void setLear(int ear);
        
        bool transform();
        bool pikpik();
        
        ~Bbee();
    
    private:
        int rear_;
        int lear_;
};

#endif
