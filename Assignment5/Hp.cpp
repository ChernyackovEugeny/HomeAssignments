/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/
// realisation of the class with composition

#include "Hp.hpp"

#include <string>
Hp::Hp() {
}
Hp::Hp(int hp) {
    hps_ = hp;
}
int Hp::getHp() {
    return hps_;
}
void Hp::setHp(int hp) {
    hps_ = hp;
}
Hp::~Hp() {
}
