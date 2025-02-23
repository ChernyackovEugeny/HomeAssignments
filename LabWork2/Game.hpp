#ifndef GAME
#define GAME

#include <array>
#include <string>
#include "Cam.hpp"
#include "Player.hpp"
#include "Door.hpp"

class Game {

    friend class Cam;
    friend class Player;   
    
	public:
	    Game(int time_mult);
	    void start_game();
        ~Game();	
	private:
	    void create_cams();
	    void create_player();
/*
	    void run_time(int time_mult);
	    void create_doors();
	    void create_anims();
*/
	    void game();
	    
	protected:
	    int time_mult_;
	    
	    std::array<std::string, 11> cam_names_; // создание камер
	    std::array<Cam, 11> cams_;
	    
	    Player player_; // создание игрока
	    
	    Door ldoor_; // создание дверей
	    Door rdoor_;
};

#endif
