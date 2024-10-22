#ifndef DECEPTIKON
#define DECEPTIKON
#include <string>
#include "Transformer.hpp"

class Deceptikon: public Transformer {
	public:
	    Deceptikon(std::string label, int armor, int ammo, int courage, int hp, int rleg, int lleg);
	    
	    int getLleg();
	    void setLleg(int lleg);
	    
	    int getRleg();
	    void setRleg(int rleg);
	    
	    bool transform();
	    bool mikmik();
        
        ~Deceptikon();
        
	private:
	    int lleg_;
	    int rleg_;
};

#endif
