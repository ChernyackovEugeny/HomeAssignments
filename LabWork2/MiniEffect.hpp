#ifndef MINIEFFECT
#define MINIEFFECT
#include <string>
class MiniEffect {
public:
    MiniEffect(std::string name, int duration);
    std::string getName() const;
    int getDuration() const;
private:
    std::string name;
    int duration;
};
#endif
