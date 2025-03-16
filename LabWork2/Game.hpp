/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef GAME
#define GAME

#include <array>
#include <chrono>
#include <string>

#include <atomic>
#include <thread>

#include "Animatronic.hpp"
#include "Cam.hpp"
#include "Door.hpp"
#include "Energy.hpp"
#include "Fox.hpp"
#include "Fredd.hpp"
#include "Phone.hpp"
#include "Picture.hpp"
#include "Player.hpp"
#include "Random.hpp"

class Menu;

/**
 * @brief class describes the game
 */
class Game {

    friend class Cam;
    friend class Player;
    friend class Phone;
    friend class Energy;
    friend class Random;
    friend class Animatronic;
    friend class Fredd;
    friend class Menu;

  public:
    Game(int num_night, bool show_pict);
    void start_game();
    
    void updateGame(); // updating the game state
    
    ~Game();

  private:
    void create_cams();
    void create_anims();

    void game();
    bool energy_lost();
    void look_cams();
    
    std::atomic<bool> running; // flag of the game state
    std::thread updateThread; // thread of updating the game
    
  protected:
    int num_night_;
    bool show_pict_;
    int time_;

    std::array<std::string, 11> cam_names_;
    std::array<Cam, 11> cams_;

    Player player_;

    Door ldoor_;
    Door rdoor_;

    Phone phone_;

    Energy energy_;

    Random gen_rand_;

    Picture picture_;

    // similar animatronics
    Animatronic Bonnie;
    Animatronic Chica;
    // unique animatronics
    Fox Foxy;
    Fredd Freddy;

    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::time_point cur_time_;
};

#endif
