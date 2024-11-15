/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/

#ifndef AUTOBOTS
#define AUTOBOTS
#include "Transformer.hpp"

class Autobots : public Transformer
{
public:
    Autobots(std::string label, int armor, int ammo, int courage, int hp, int rarm, int larm);
    Autobots();

    virtual void Optransform();
    virtual void Opfire();
    virtual void Ophide();

    int getRarm();
    void setRarm(int arm);

    int getLarm();
    void setLarm(int arm);

    bool transform();
    bool pikpik();

    ~Autobots();

private:
    int rarm_;
    int larm_;
};

#endif
