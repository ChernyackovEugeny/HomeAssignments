/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "MiniRogue.hpp"

MiniRogue::MiniRogue() : MiniPlayer("Разбойник", 90, 100) {
    addAbility(MiniAbility("Кинжал", 25, 15));
    addAbility(MiniAbility("Ядовитая атака", 15, 10));
    addAbility(MiniAbility("Скрытность", 0, 10));
    addAbility(MiniAbility("Критический удар", 50, 35));
}
