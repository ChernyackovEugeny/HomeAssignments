/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MINIEFFECT
#define MINIEFFECT
#include <string>

/**
 * @brief class describes the abilities' effects
 */
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
