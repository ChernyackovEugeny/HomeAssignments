/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef MENU
#define MENU

#include "Game.hpp"

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

    bool show_pict_; // пихнем в Game
    int num_night_;  // пихнем в Game
};

#endif
