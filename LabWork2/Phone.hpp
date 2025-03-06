/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef PHONE
#define PHONE

#include <string>
class Game;

/**
 * @brief class describes the introduction phone
 */
class Phone {
    friend class Game;

  public:
    Phone();
    ~Phone();

  protected:
    void introduction();
};

#endif
