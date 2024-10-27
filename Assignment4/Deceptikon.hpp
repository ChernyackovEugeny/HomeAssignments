// header of inherited class of Transformer

#ifndef DECEPTIKON
#define DECEPTIKON
#include <string>
#include "Transformer.hpp"

class Deceptikon: public Transformer
{
public:
    Deceptikon(std::string label, int armor, int ammo, int courage, int hp, int rleg, int lleg);

    int getLleg() const;
    void setLleg(int lleg);

    int getRleg() const;
    void setRleg(int rleg);

    bool transform();
    bool mikmik();

    ~Deceptikon();

private:
    int rleg_;
    int lleg_;
};

#endif
