#ifndef GAME
#define GAME

#include <chrono>
#include <array>
#include <string>

#include "Cam.hpp"
#include "Player.hpp"
#include "Door.hpp"
#include "Phone.hpp"
#include "Energy.hpp"
#include "Random.hpp"
#include "Animatronic.hpp"
#include "Fox.hpp"
#include "Fredd.hpp"
#include "Picture.hpp"

class Menu;

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
            ~Game();	
	private:
	    void create_cams();
	    void create_anims();

	    void game();
	    bool energy_lost();
	    bool look_cams();
	    
	protected:
	    int num_night_;
	    bool show_pict_;
	    int time_;
	
	    std::array<std::string, 11> cam_names_; // создание камер
	    std::array<Cam, 11> cams_;
	    
	    Player player_; // создание игрока
	    
	    Door ldoor_; // создание дверей
	    Door rdoor_;
	    
	    Phone phone_;
	    
	    Energy energy_;
	    
	    Random gen_rand_;
	    
	    Picture picture_;
	    
	    // похожие аниматроники
	    Animatronic Bonnie;
	    Animatronic Chica;
	    // непохожие аниматроники
	    Fox Foxy;
	    Fredd Freddy;
	    
	    std::chrono::steady_clock::time_point start_time_;
	    std::chrono::steady_clock::time_point cur_time_;
};

#endif
