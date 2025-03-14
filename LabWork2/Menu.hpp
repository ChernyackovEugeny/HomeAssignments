/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MENU
#define MENU

#include "Game.hpp"
#include "Minigame.hpp"

/**
 * @brief class describes the menu of the game
 */
class Menu {
    friend class Game;

  public:
    Menu();
    void menu();
    ~Menu();

  protected:
    void picture_check();
    void night_check();
    void start_night();
    
    void start_minigame();

    bool show_pict_; // push it in class Game
    int num_night_;  // push it in class Game
};

#endif
