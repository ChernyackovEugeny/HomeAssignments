#include <iostream>
#include <array>
#include <string>
#include <thread>
#include "Game.hpp"
#include "Cam.hpp"

Game::Game() {
    cam_names_ = {"1A", "1B", "5", "7", "1C", "3", "6", "2A", "2B", "4A", "4B"};
}

void Game::start_game() {
    // инструкция
    phone_.introduction();
    
    create_cams();
    create_anims();
    start_time_ = std::chrono::steady_clock::now();
    
	game();
}

void Game::game() {
    std::string entered;
    std::getline(std::cin, entered);
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
        
        // anims actions
        Bonnie.move_anim(gen_rand_, ldoor_.door_close_);
        Chica.move_anim(gen_rand_, rdoor_.door_close_);
        
        // проверка на скример
        if (Bonnie.scream_) {
            std::cout << "Bonnie is screaming, you lost" << std::endl;
            break;
        }
        if (Chica.scream_) {
            std::cout << "Chica is screaming, you lost" << std::endl;
            break;
        }
        
        
        // обновляем текущее время
        cur_time_ = std::chrono::steady_clock::now();
        
        // обновляем множитель эергии
        energy_.energy_mult_ = ldoor_.door_close_ + ldoor_.door_light_ + rdoor_.door_close_ + rdoor_.door_light_ + player_.cams_status_ + 1;
        
        
        // payers action
        
        // cams check
        if (entered == "cams off" or entered == "coff") {
            energy_.energy_mult_ -= 1;
            player_.cams_status_ = false;
        }
        
        if (entered == "cams on" or entered == "con") {
            energy_.energy_mult_ += 1;
            player_.cams_status_ = true;
        }
        
        if (player_.cams_status_) {
            // если убили в камерах, закончить цикл и тут
            if (look_cams()) {
                break;
            }
            player_.cams_status_ = false;
        }
        
        
        //doors light
        
        if (entered == "light left door" or entered == "lld") {
        
            if (Bonnie.place_ == 7) {
                std::cout << "Bonnie is looking at you!" << std::endl;
            }
            // anims check, messege about entities
            ldoor_.door_light_ = true;
        }
        if (entered == "unlight left door" or entered == "unlld") {
            std::cout << "The left light is off" << std::endl;
            ldoor_.door_light_ = false;
        }
        if (entered == "light right door" or entered == "lrd") {
            
            if (Chica.place_ == 7) {
                std::cout << "Chica is looking at you!" << std::endl;
            }
            // anims check, messege about entities
            
            rdoor_.door_light_ = true;
        }
        if (entered == "unlight right door" or entered == "unlrd") {
            std::cout << "The right light is off" << std::endl;
            rdoor_.door_light_ = false;
        }
        
        // doors close
        
        if (entered == "close left door" or entered == "cld") {
            std::cout << "The left door is closed" << std::endl;
            ldoor_.door_close_ = true;
        }
        if (entered == "open left door" or entered == "old") {
            std::cout << "The left door is opened" << std::endl;
            ldoor_.door_close_ = false;
        }
        if (entered == "close right door" or entered == "crd") {
            std::cout << "The right door is closed" << std::endl;
            
            rdoor_.door_close_ = true;
        }
        if (entered == "open right door" or entered == "ord") {
            std::cout << "The right door is opened" << std::endl;
            rdoor_.door_close_ = false;
        }
        
        // info about light, doors, energy, energy consumption
        if (entered == "info") {
            std::cout << "Energy: " << energy_.cur_energy_ << "; Energy consumtion: " << energy_.energy_mult_ << "/6; Left light: " << ldoor_.door_light_ << "; Left close: " << ldoor_.door_close_ << "; Right light: " << rdoor_.door_light_ << "; Right close: " << rdoor_.door_close_ << std::endl;
        }
        
        // push a nose
        if (entered == "push a nose") {
            std::cout << player_.push_nose() << std::endl;
        }
        
        // fan
        if (entered == "fan on") {
            std::cout << "The fan is on" << std::endl;
            player_.fan_status_ == true;
        }
        if (entered == "fan off") {
            std::cout << "The fan is off" << std::endl;
            player_.fan_status_ == false;
        }        
        
        // проверка на победу
        auto current_time = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count() >= 3) {
            std::cout << "You won!" << std::endl;
            break;
        }
        
        std::getline(std::cin, entered);
        
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

bool Game::look_cams() {
    std::cout << "Here are the cams' names, input one to look through it: 1A, 1B, 5, 7, 1C, 3, 6, 2A, 2B, 4A, 4B; to escape cams mode input 'cams off' or 'coff'" << std::endl;
    
    std::string entered_cam;
    std::getline(std::cin, entered_cam);
    
    while (entered_cam != "cams off" and entered_cam != "coff") {
        bool found = false;
        for (int i = 0; i < 11; i++ ) {
            if (cam_names_[i] == entered_cam) {
                // проверка аниматроников на камере
                if (cam_names_[i] == Bonnie.way_[Bonnie.place_-1]) {
                    std::cout << "Bonnie is here!" << std::endl;
                }
                if (cam_names_[i] == Chica.way_[Chica.place_-1]) {
                    std::cout << "Chica is here!" << std::endl;
                }
                // сидим на этой камере cams_[i], нужна проверка на аниматроников
                
                
                // двигаем аниматроников, проверка на скример
                Bonnie.move_anim(gen_rand_, ldoor_.door_close_);
                if (Bonnie.scream_) {
                    std::cout << "Bonnie is screaming, you lost" << std::endl;
                    return true;
                }
                Chica.move_anim(gen_rand_, rdoor_.door_close_);
                if (Chica.scream_) {
                    std::cout << "Chica is screaming, you lost" << std::endl;
                    return true;
                }
                
                // изменяем энергию
                energy_.change_energy(cur_time_);
                
                // проверка на наличие энергии
                if (energy_.cur_energy_ <= 0) {
                    if (energy_lost()) {
                        std::cout << "You lost" << std::endl;
                        return true;
                    }
                    std::cout << "You win!" << std::endl;
                    return true;
                cur_time_ = std::chrono::steady_clock::now();
                }
                
                
                found = true;
                break;
            }   
        }
        if (not found and (entered_cam != "coff" or entered_cam != "cams off")) {
            std::cout << "The cam with that name is not exist, to escape the cams mode input 'cams off' or 'coff'" << std::endl;
        }
        std::getline(std::cin, entered_cam);
    }
    return false;
}

void Game::create_anims() {
    Bonnie.way_ = {"1A", "1B", "5", "3", "2A", "2B"};
    Bonnie.last_move_time_ = std::chrono::steady_clock::now();
    
    Chica.way_ = {"1A", "1B", "7", "6", "4A", "4B"};
    Chica.last_move_time_ = std::chrono::steady_clock::now();
}


void Game::create_cams() {
    for (int i = 0; i < 11; i++) {
        cams_[i] = Cam(cam_names_[i]);
    }
}



Game::~Game() {}
