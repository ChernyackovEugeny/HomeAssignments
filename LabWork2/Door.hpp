/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef DOOR
#define DOOR

class Game;

class Door {
    friend Game;

  public:
    Door();
    ~Door();

  protected:
    bool door_close_;
    bool door_light_;
};

#endif
