// header of the primary class

#ifndef TRANSFORMER
#define TRANSFORMER
#include <string>
#include <ostream>
#include "Hp.hpp"
#include "Gun.hpp"

class Transformer
{
public:
    Transformer(std::string label, int armor, int ammo, int courage, int hp);
    Transformer(bool dead);
    void setAmmo(int ammo);
    int getAmmo() const;
    void setLabel(std::string label);
    std::string getLabel() const;
    void setArmor(int armor);
    int getArmor() const;
    void setCourage(int courage);
    int getCourage() const;

    void setHp(int hp);
    int getHp() const;

    void setGun(Gun* weap);
    std::string getGun() const;

    void fire();
    bool move();

    ~Transformer();
private:

    friend std::ostream& operator<<(std::ostream& os, const Transformer& tran);

    friend bool operator<(const Transformer& t1, const Transformer& t2);
    friend bool operator==(const Transformer& t1, const Transformer& t2);

    std::string label_;
    int armor_;
    int ammo_;
    int courage_;

    Hp healthpoints_;

    Gun* weapon_;
};

#endif
