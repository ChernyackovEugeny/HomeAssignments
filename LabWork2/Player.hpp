/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef PLAYER
#define PLAYER

#include <string>

class Game;

/**
 * @brief class describes special functions of the player
 */
class Player {
    friend class Game;

  public:
    Player();

    ~Player();

  protected:
    std::string push_nose();
	
    /// shows whether the player watch cameras or not
    bool cams_status_;
    /// shows whether the fan is on or off
    bool fan_status_;
};

#endif
