/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "MiniMage.hpp"

MiniMage::MiniMage() : MiniPlayer("Маг", 120, 100) {
    addAbility(MiniAbility("Огненный шар", 40, 30));
    addAbility(MiniAbility("Заморозка", 20, 20));
    addAbility(MiniAbility("Молния", 50, 40));
    addAbility(MiniAbility("Восстановление маны", 0, -20));
}
