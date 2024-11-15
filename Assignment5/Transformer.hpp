/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/

#ifndef TRANSFORMER
#define TRANSFORMER
#include <string>
#include <iostream>
#include "Hp.hpp"
#include "Gun.hpp"

class Transformer
{
public:
    Transformer(std::string label, int armor, int ammo, int courage, int hp);
    Transformer();

    virtual void Optransform();
    virtual void Opfire();
    virtual void Ophide();

    void setAmmo(int ammo);
    int getAmmo();
    void setLabel(std::string label);
    std::string getLabel();
    void setArmor(int armor);
    int getArmor();
    void setCourage(int courage);
    int getCourage();

    void setHp(int hp);
    int getHp();

    void setGun(Gun* weap);
    std::string getGun();

    void fire();
    bool move();

    ~Transformer();
private:
    std::string label_;
    int armor_;
    int ammo_;
    int courage_;

    Hp healthpoints_;

    Gun* weapon_;
};

#endif
