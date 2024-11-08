// header of inherited class of Transformer

#ifndef DECEPTIKON
#define DECEPTIKON
#include <string>
#include "Transformer.hpp"

class Deceptikon: public Transformer
{
public:
    Deceptikon(std::string label, int armor, int ammo, int courage, int hp, int rleg, int lleg);
    Deceptikon();

    virtual void Optransform();
    virtual void Opfire();
    virtual void Ophide();

    int getLleg();
    void setLleg(int lleg);

    int getRleg();
    void setRleg(int rleg);

    bool transform();
    bool mikmik();

    ~Deceptikon();

private:
    int rleg_;
    int lleg_;
};

#endif
