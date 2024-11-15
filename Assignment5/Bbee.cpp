/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/

#include "Bbee.hpp"

Bbee::Bbee(std::string label, int armor, int ammo, int courage, int hp, int rear, int lear)
    : Transformer(label, armor, ammo, courage, hp), rear_(rear), lear_(lear) {
}

int Bbee::getRear() {
    return rear_;
}
void Bbee::setRear(int ear) {
    rear_ = ear;
}
int Bbee::getLear() {
    return lear_;
}
void Bbee::setLear(int ear) {
    lear_ = ear;
}

bool Bbee::transform() {
    return true;
}
bool Bbee::pikpik() {
    return false;
}

Bbee::~Bbee() {
}
