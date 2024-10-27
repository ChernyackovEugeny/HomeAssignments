// realisation of inherited class of Transformer

#include "Deceptikon.hpp"

Deceptikon::Deceptikon(std::string label, int armor, int ammo, int courage, int hp, int rleg, int lleg) : Transformer(label, armor, ammo, courage, hp), rleg_(rleg), lleg_(lleg) {}

int Deceptikon::getLleg() const
{
    return lleg_;
}
void Deceptikon::setLleg(int lleg)
{
    lleg_ = lleg;
}

int Deceptikon::getRleg() const
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
