#include <iostream>
#include <array>
#include <string>
#include <thread>
#include "Game.hpp"
#include "Cam.hpp"

Game::Game(int num_night, bool show_pict) : num_night_(num_night), show_pict_(show_pict) {
    cam_names_ = {"1A", "1B", "5", "7", "1C", "3", "6", "2A", "2B", "4A", "4B"};
    time_ = 0;
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
        Bonnie.move_anim(gen_rand_, ldoor_.door_close_, time_);
        Chica.move_anim(gen_rand_, rdoor_.door_close_, time_);
        Foxy.move_anim(gen_rand_, ldoor_.door_close_, time_);
        Freddy.move_anim(gen_rand_, rdoor_.door_close_, false, time_); // false тк двигаем не из камер
        
        // проверка на скример
        if (Bonnie.scream_) {
            if (show_pict_) {
                picture_.show_scream(1);
            }
            else {
                picture_.show_text_scream(1);
            }
            break;
        }
        if (Chica.scream_) {
            if (show_pict_) {
                picture_.show_scream(2);
            }
            else {
                picture_.show_text_scream(2);
            }
            break;
        }
        if (Foxy.scream_) {
            if (show_pict_) {
                picture_.show_scream(3);
            }
            else {
                picture_.show_text_scream(3);
            }
            break;
        }
        if (Freddy.scream_) {
            if (show_pict_) {
                picture_.show_scream(4);
            }
            else {
                picture_.show_text_scream(4);
            }
            break;
        }
        
        // обновляем текущее время
        cur_time_ = std::chrono::steady_clock::now();
        time_ = std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count();
        
        // обновляем множитель эергии
        energy_.energy_mult_ = ldoor_.door_close_ + ldoor_.door_light_ + rdoor_.door_close_ + rdoor_.door_light_ + player_.cams_status_ + 1;
        
        
        // payers action
        
        // cams check
        if (entered == "cams on" or entered == "con") {
            player_.cams_status_ = true;
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
            else {
                std::cout << "There is noone here" << std::endl;
            }
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
            else {
                std::cout << "There is noone here" << std::endl;
            }
            
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
            std::cout << "Energy: " << energy_.cur_energy_ << "; Energy consumtion: " << energy_.energy_mult_ << "/6; Time: " << time_ << " am; Left light: " << ldoor_.door_light_ << "; Left close: " << ldoor_.door_close_ << "; Right light: " << rdoor_.door_light_ << "; Right close: " << rdoor_.door_close_ << std::endl;
        }
        
        // push a nose
        if (entered == "push a nose") {
            std::cout << player_.push_nose() << std::endl;
        }
        
        // fan
        if (entered == "fan on") {
            std::cout << "The fan is on" << std::endl;
            player_.fan_status_ = true;
        }
        if (entered == "fan off") {
            std::cout << "The fan is off" << std::endl;
            player_.fan_status_ = false;
        }
        
        // проверка на победу
        if (std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count() >= 6) {
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
        
        if (std::chrono::duration_cast<std::chrono::minutes>(current_time - start_time_).count() >= 6) {
            return false;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        current_time = std::chrono::steady_clock::now();

    }
    if (show_pict_) {
        picture_.show_scream(4);
    }
    return true;
    
}

bool Game::look_cams() {
    std::cout << "Here are the cams' names, input one to look through it: 1A, 1B, 5, 7, 1C, 3, 6, 2A, 2B, 4A, 4B; to escape cams mode input 'cams off' or 'coff'" << std::endl;
    
    std::string entered_cam;
    std::getline(std::cin, entered_cam);
    cur_time_ = std::chrono::steady_clock::now();
    
    while (entered_cam != "cams off" and entered_cam != "coff") {
        bool found = false;
        for (int i = 0; i < 11; i++ ) {
            if (cam_names_[i] == entered_cam) {
            	bool bonnie = (cam_names_[i] == Bonnie.way_[Bonnie.place_-1]);
            	bool chica = (cam_names_[i] == Chica.way_[Chica.place_-1]);
            	bool foxy = (Foxy.place_ == 2);
            	int foxy_stage = Foxy.stage_;
            	bool freddy = (cam_names_[i] == Freddy.way_[Freddy.place_-1]);
            	
                // проверка аниматроников на камере
/*                
                if (cam_names_[i] == Bonnie.way_[Bonnie.place_-1]) {
                    bonny
                  std::cout << "Bonnie is here!" << std::endl;
                }
                if (cam_names_[i] == Chica.way_[Chica.place_-1]) {
                    std::cout << "Chica is here!" << std::endl;
                }
                
                if (cam_names_[i] == "1C") {
                    if (Foxy.stage_ == 1) {
                        std::cout << "Foxy is behind the curtain" << std::endl;
                    }
                    else if (Foxy.stage_ == 2) {
                        std::cout << "You can see the Foxy's head" << std::endl;
                    }
                    else if (Foxy.stage_ == 3) {
                        std::cout << "Foxy is near the scene" << std::endl;
                    }
                    else if (Foxy.stage_ == 4) {
                        std::cout << "FOXY IS OUT!" << std::endl;
                    }
                }
                if (cam_names_[i] == "2A" and Foxy.place_ == 2) {
                    std::cout << "FOXY IS RUNNING!" << std::endl;
                }
*/              if (show_pict_) {
                    picture_.show_picture(cam_names_[i], bonnie, chica, foxy, foxy_stage, freddy);
                }
                else {
                    picture_.show_text(cam_names_[i], bonnie, chica, foxy, foxy_stage, freddy);
                }
                
                // двигаем Фредди тут, а не ниже, зависим от просмотра камеры
                if (cam_names_[i] == Freddy.way_[Freddy.place_-1] and cam_names_[i] != "4B") {
//                    std::cout << "Freddy is here!" << std::endl;
                    Freddy.move_anim(gen_rand_, rdoor_.door_close_, false, time_);
                }
                else if (cam_names_[i] == Freddy.way_[Freddy.place_-1] and cam_names_[i] == "4B") {
//                    std::cout << "Freddy is here!" << std::endl;
                    Freddy.move_anim(gen_rand_, rdoor_.door_close_, true, time_);
                }

                else if (cam_names_[i] != Freddy.way_[Freddy.place_-1]) {
                    // заскримерить может только тут
                    Freddy.move_anim(gen_rand_, rdoor_.door_close_, false, time_);
                    if (Freddy.scream_ and show_pict_) {
//                        std::cout << "Freddy is screaming, you lost" << std::endl;
                        picture_.show_scream(4);
                        return true;
                    }
                    else if (Freddy.scream_ and not show_pict_) {
                        picture_.show_text_scream(4);
                        return true;
                    }   
                }
       
                
                // двигаем аниматроников, проверка на скример
                Bonnie.move_anim(gen_rand_, ldoor_.door_close_, time_);
                if (Bonnie.scream_) {
//                    std::cout << "Bonnie is screaming, you lost" << std::endl;
                    if (show_pict_) {
                        picture_.show_scream(1);
                    }
                    else {
                        picture_.show_text_scream(1);
                    }
                    return true;
                }
                Chica.move_anim(gen_rand_, rdoor_.door_close_, time_);
                if (Chica.scream_) {
//                    std::cout << "Chica is screaming, you lost" << std::endl;

                    if (show_pict_) {
                        picture_.show_scream(2);
                    }
                    else {
                        picture_.show_text_scream(2);
                    }
                    
                    return true;
                }
                Foxy.move_anim(gen_rand_, ldoor_.door_close_, time_);
                if (Foxy.scream_) {
//                    std::cout << "Foxy is screaming, you lost" << std::endl;

                    if (show_pict_) {
                        picture_.show_scream(3);
                    }
                    else {
                        picture_.show_text_scream(3);
                    }
                    
                    return true;
                }
                found = true;
                break;
            }   
        }
        if (not found and (entered_cam != "coff" or entered_cam != "cams off")) {
            std::cout << "The cam with that name is not exist, to escape the cams mode input 'cams off' or 'coff'" << std::endl;
        }
        
        // изменяем энергию
        energy_.energy_mult_ = ldoor_.door_close_ + ldoor_.door_light_ + rdoor_.door_close_ + rdoor_.door_light_ + player_.cams_status_ + 1;
        energy_.change_energy(cur_time_);
        
        // проверка на наличие энергии
        if (energy_.cur_energy_ <= 0) {
            if (energy_lost()) {
                std::cout << "You lost" << std::endl;
                return true;
            }
            std::cout << "You win!" << std::endl;
            return true;
        }
        
        cur_time_ = std::chrono::steady_clock::now();
        time_ = std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count();
        
        std::getline(std::cin, entered_cam);
    }
    return false;
}

void Game::create_anims() {
    Bonnie.way_ = {"1A", "1B", "5", "3", "2A", "2B"};
    Bonnie.last_move_time_ = std::chrono::steady_clock::now();
    
    Chica.way_ = {"1A", "1B", "7", "6", "4A", "4B"};
    Chica.last_move_time_ = std::chrono::steady_clock::now();
    
    Foxy.last_move_time_ = std::chrono::steady_clock::now();
    
    Freddy.last_move_time_ = std::chrono::steady_clock::now();
    
    if (num_night_ == 1) {
        Bonnie.intellegence_ = {1, 1, 2, 3, 3, 3};
        Chica.intellegence_ = {0, 0, 1, 2, 2, 2};
        Foxy.intellegence_ = {0, 0, 0, 0, 0, 1};
        Freddy.intellegence_ = {0, 0, 0, 0, 0, 0};
    }
    else if (num_night_ == 2) {
        Bonnie.intellegence_ = {3, 3, 3, 4, 5, 6};
        Chica.intellegence_ = {1, 1, 1, 2, 3, 3};
        Foxy.intellegence_ = {0, 0, 0, 2, 3, 3};
        Freddy.intellegence_ = {0, 0, 0, 0, 0, 0};
    }
    else if (num_night_ == 3) {
        Bonnie.intellegence_ = {0, 1, 1, 2, 2, 3};
        Chica.intellegence_ = {5, 5, 5, 6, 7, 7};
        Foxy.intellegence_ = {2, 2, 2, 3, 4, 4};
        Freddy.intellegence_ = {0, 1, 1, 1, 1, 1};
    }
    else if (num_night_ == 4) {
        Bonnie.intellegence_ = {2, 3, 4, 4, 5, 5};
        Chica.intellegence_ = {3, 3, 4, 5, 6, 6};
        Foxy.intellegence_ = {4, 4, 5, 6, 7, 8};
        Freddy.intellegence_ = {1, 1, 1, 2, 2, 2};
    }
    else if (num_night_ == 5) {
        Bonnie.intellegence_ = {5, 5, 6, 6, 7, 8};
        Chica.intellegence_ = {7, 7, 7, 8, 8, 9};
        Foxy.intellegence_ = {5, 5, 6, 6, 7, 7};
        Freddy.intellegence_ = {1, 2, 3, 3, 3, 3};
    }
}

void Game::create_cams() {
    for (int i = 0; i < 11; i++) {
        cams_[i] = Cam(cam_names_[i]);
    }
}



Game::~Game() {}
