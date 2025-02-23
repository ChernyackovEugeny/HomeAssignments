#include <iostream>
#include <array>
#include <string>
#include "Game.hpp"
#include "Cam.hpp"

Game::Game(int time_mult) {
    time_mult_ = time_mult;
    cam_names_ = {"1A", "1B", "5", "7", "1C", "3", "6", "2A", "2B", "4A", "4B"};
}

void Game::start_game() {
    create_cams();
/*
	run_time(time_mult_);
	create_anims();
*/
	game();
}

void Game::game() {
    std::string entered;
    std::cin >> entered;
    while (entered != "end_game") {
//        if ...;
        
//        move_anims()...
        
        std::cin >> entered;
        
    }
}

void Game::create_cams() {
    for (int i = 0; i < 11; i++) {
        cams_[i] = Cam(cam_names_[i]);
        
        std::cout << cams_[i].get_name() << std::endl;
    }
}

Game::~Game() {}
