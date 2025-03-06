/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef CAM
#define CAM

#include <string>

class Game;

/**
 * @brief class describes cameras
 */
class Cam {
    friend class Game;

  public:
    Cam(std::string name);
    Cam();

    ~Cam();

  protected:
    std::string name_;
};

#endif
