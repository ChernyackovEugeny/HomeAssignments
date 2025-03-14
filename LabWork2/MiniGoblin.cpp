#include "MiniGoblin.hpp"

MiniGoblin::MiniGoblin() : MiniEnemy("Гоблин", 80, 100) {
    addAbility(MiniAbility("Удар дубиной", 20, 15));
    addAbility(MiniAbility("Злобный крик", 0, 5));
    addAbility(MiniAbility("Коварный выпад", 30, 20));
    addAbility(MiniAbility("Песчаная завеса", 0, 10));
}
