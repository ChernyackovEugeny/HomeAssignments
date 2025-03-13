/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef PICTURE
#define PICTURE
#include <string>

class Game;

/**
 * @brief class is used to get feedback from the game
 */
class Picture {
    friend class Game;

  public:
    Picture();
    ~Picture();

  protected:
    void show_picture(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage,
                      bool freddy);
    void show_scream(int scream);

    void show_text(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage,
                   bool freddy);
    void show_text_scream(int scream);
    
    void show_office(int bonnie, int chica, bool left_light, bool right_light, bool left_close, bool right_close);
    
    /// whether the game will show pictures or not
    bool accept_picture_;
};

#endif
