#include "Transformer.hpp"

class Autobots : public Transformer {
    public:
        Autobots(std::string label, int armor, int ammo, int courage, int hp, int rarm, int larm);
        int getRarm();
        void setRarm(int arm);
        
        int getLarm();
        void setLarm(int arm);
        
        bool transform();
        bool pikpik();
        
        ~Autobots();
    
    private:
        int larm_;
        int rarm_;
};
