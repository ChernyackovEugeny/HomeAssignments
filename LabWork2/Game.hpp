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

class Game {

    friend class Cam;
    friend class Player;
    friend class Phone;
    friend class Energy;
    friend class Random;
    friend class Animatronic;
    
	public:
	    Game();
	    void start_game();
        ~Game();	
	private:
	    void create_cams();
	    void create_anims();

	    void game();
	    bool energy_lost();
	    bool look_cams();
	    
	protected:
	    std::array<std::string, 11> cam_names_; // создание камер
	    std::array<Cam, 11> cams_;
	    
	    Player player_; // создание игрока
	    
	    Door ldoor_; // создание дверей
	    Door rdoor_;
	    
	    Phone phone_;
	    
	    Energy energy_;
	    
	    Random gen_rand_;
	    
	    // похожие аниматроники
	    Animatronic Bonnie;
	    Animatronic Chica;
	    // непохожие аниматроники
	    Fox Foxy;
	    
	    std::chrono::steady_clock::time_point start_time_;
	    std::chrono::steady_clock::time_point cur_time_;
};

#endif
