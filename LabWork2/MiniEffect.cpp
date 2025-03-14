#include "MiniEffect.hpp"
MiniEffect::MiniEffect(std::string name, int duration) : name(name), duration(duration) {}
std::string MiniEffect::getName() const {
    return name;
}
int MiniEffect::getDuration() const {
    return duration;
}
