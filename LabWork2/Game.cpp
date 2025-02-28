#include <iostream>
#include <array>
#include <string>
#include <thread>
#include "Game.hpp"
#include "Cam.hpp"

Game::Game(int time_mult) {
    time_mult_ = time_mult;
    cam_names_ = {"1A", "1B", "5", "7", "1C", "3", "6", "2A", "2B", "4A", "4B"};
}

void Game::start_game() {
    create_cams();
    start_time_ = std::chrono::steady_clock::now();
/*
	run_time(time_mult_);
	create_anims();
*/
	game();
}

void Game::game() {
    std::string entered;
    std::cin >> entered;
    cur_time_ = std::chrono::steady_clock::now();
    
    while (entered != "end_game") {
        // изменяем энергию
        energy_.change_energy(cur_time_);
        
        // проверка на наличие энергии
        if (energy_.cur_energy_ <= 0) {
            if (energy_lost()) {
                std::cout << "You lost" << std::endl;
                break;
            }
            std::cout << "You win!" << std::endl;
            break;
        }
        
        // обновляем текущее время
        cur_time_ = std::chrono::steady_clock::now();
        
        // обновляем множитель эергии
        energy_.energy_mult_ = ldoor_.get_light_status() + ldoor_.get_close_status() + rdoor_.get_light_status() + rdoor_.get_close_status() + player_.
        
        
        
        // payers action
        
        
        // проверка на победу
        auto current_time = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count() >= 3) {
            std::cout << "You won!" << std::endl;
            break;
        }
        
        std::cin >> entered;
        
    }
}

bool Game::energy_lost() {
    int seconds_left = gen_rand_.get_rand(7, 15);
    auto current_time = std::chrono::steady_clock::now();
    
    for (int i = 0; i < seconds_left; i++) {
        std::cout << "Your energy is empty, doors are opened, light is off, Freddy is looking at you" << std::endl;
        
        if (std::chrono::duration_cast<std::chrono::minutes>(current_time - start_time_).count() >= 3) {
            return false;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        current_time = std::chrono::steady_clock::now();

    }
    return true;
    
}

void Game::create_cams() {
    for (int i = 0; i < 11; i++) {
        cams_[i] = Cam(cam_names_[i]);
        
        std::cout << cams_[i].get_name() << std::endl;
    }
    std::cout << phone_.introduction() << std::endl;
}



Game::~Game() {}
