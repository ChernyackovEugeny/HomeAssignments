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

class Game {

    friend class Cam;
    friend class Player;
    friend class Phone;
    friend class Energy;
    friend class Random;
    
	public:
	    Game(int time_mult);
	    void start_game();
        ~Game();	
	private:
	    void create_cams();
	    void create_player();
/*
	    void create_doors();
	    void create_anims();
*/
	    void game();
	    bool energy_lost();
	    
	protected:
	    int time_mult_;
	    
	    std::array<std::string, 11> cam_names_; // создание камер
	    std::array<Cam, 11> cams_;
	    
	    Player player_; // создание игрока
	    
	    Door ldoor_; // создание дверей
	    Door rdoor_;
	    
	    Phone phone_;
	    
	    Energy energy_;
	    
	    Random gen_rand_;
	    
	    std::chrono::steady_clock::time_point start_time_;
	    std::chrono::steady_clock::time_point cur_time_;
};

#endif
