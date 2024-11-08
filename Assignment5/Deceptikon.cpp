// realisation of inherited class of Transformer

#include "Deceptikon.hpp"

Deceptikon::Deceptikon(std::string label, int armor, int ammo, int courage, int hp, int rleg, int lleg) : Transformer(label, armor, ammo, courage, hp), rleg_(rleg), lleg_(lleg) {}

Deceptikon::Deceptikon()
{
    Transformer();
}

void Deceptikon::Optransform()
{
    std::cout << "class Deceptikon -> Optransform" << std::endl;
}
void Deceptikon::Opfire()
{
    std::cout << "class Deceptikon -> Opfire" << std::endl;
}
void Deceptikon::Ophide()
{
    std::cout << "class Deceptikon -> Ophide" << std::endl;
}

int Deceptikon::getLleg()
{
    return lleg_;
}
void Deceptikon::setLleg(int lleg)
{
    lleg_ = lleg;
}

int Deceptikon::getRleg()
{
    return rleg_;
}
void Deceptikon::setRleg(int rleg)
{
    rleg_ = rleg;
}


bool Deceptikon::transform()
{
    return true;
}
bool Deceptikon::mikmik()
{
    return false;
}

Deceptikon::~Deceptikon() {}
