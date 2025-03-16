/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Game.hpp"
#include "Cam.hpp"
#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <thread>

Game::Game(int num_night, bool show_pict) : num_night_(num_night), show_pict_(show_pict) {
    cam_names_ = {"1A", "1B", "5", "7", "1C", "3", "6", "2A", "2B", "4A", "4B"};
    time_ = 0;
}

/// @brief start of the game
void Game::start_game() {
    // instruction
    phone_.introduction();

    create_cams();
    create_anims();
    start_time_ = std::chrono::steady_clock::now();

    // turning on the game state flag
    running = true;

    game();
}

/// @brief playing the game
void Game::game() {
    cur_time_ = std::chrono::steady_clock::now();

    // turning on the thread of updating the game
    updateThread = std::thread(&Game::updateGame, this);

    while (running) {

        std::string entered;
        std::getline(std::cin, entered);
        if (not running) {
            std::cin.clear();
            std::cin.setstate(std::ios::failbit);
            break;
        }

        // payers action
        // cams check
        if (entered == "cams on" or entered == "con") {
            player_.cams_status_ = true;
            look_cams();
            player_.cams_status_ = false;
        }
        if (not running) {
            std::cin.clear();
            std::cin.setstate(std::ios::failbit);
            break;
        }

        // doors light
        if (entered == "light left door" or entered == "lld") {
            ldoor_.door_light_ = true;
            if (not show_pict_) {
                if (Bonnie.place_ == 7) {
                    std::cout << "Bonnie is looking at you!" << std::endl;
                } else {
                    std::cout << "There is noone here" << std::endl;
                }
            }
        }
        if (entered == "unlight left door" or entered == "unlld") {
            ldoor_.door_light_ = false;
            if (not show_pict_) {
                std::cout << "The left light is off" << std::endl;
            }
        }
        if (entered == "light right door" or entered == "lrd") {
            rdoor_.door_light_ = true;
            if (not show_pict_) {
                if (Chica.place_ == 7) {
                    std::cout << "Chica is looking at you!" << std::endl;
                } else {
                    std::cout << "There is noone here" << std::endl;
                }
            }
        }
        if (entered == "unlight right door" or entered == "unlrd") {
            rdoor_.door_light_ = false;
            if (not show_pict_) {
                std::cout << "The right light is off" << std::endl;
            }
        }

        // doors close
        if (entered == "close left door" or entered == "cld") {
            ldoor_.door_close_ = true;
            if (not show_pict_) {
                std::cout << "The left door is closed" << std::endl;
            }
        }
        if (entered == "open left door" or entered == "old") {
            ldoor_.door_close_ = false;
            if (not show_pict_) {
                std::cout << "The left door is opened" << std::endl;
            }
        }
        if (entered == "close right door" or entered == "crd") {
            rdoor_.door_close_ = true;
            if (not show_pict_) {
                std::cout << "The right door is closed" << std::endl;
            }
        }
        if (entered == "open right door" or entered == "ord") {
            rdoor_.door_close_ = false;
            if (not show_pict_) {
                std::cout << "The right door is opened" << std::endl;
            }
        }

        if (show_pict_) {
            picture_.show_office(Bonnie.place_, Chica.place_, ldoor_.door_light_,
                                 rdoor_.door_light_, ldoor_.door_close_, rdoor_.door_close_);
        }

        // info about light, doors, energy, energy consumption
        if (entered == "info" and not show_pict_) {
            std::cout << "Energy: " << energy_.cur_energy_
                      << "; Energy consumtion: " << energy_.energy_mult_ << "/6; Time: " << time_
                      << " am; Left light: " << ldoor_.door_light_
                      << "; Left close: " << ldoor_.door_close_
                      << "; Right light: " << rdoor_.door_light_
                      << "; Right close: " << rdoor_.door_close_ << std::endl;
        }
        if (show_pict_) {
            std::cout << "Energy: " << energy_.cur_energy_
                      << "; Energy consumtion: " << energy_.energy_mult_ << "/6; Time: " << time_
                      << " am" << std::endl;
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
    }
    updateThread.join(); // turn off the thread
}

/// @brief the thread of updating the game
void Game::updateGame() {
    while (running) {
        // updating every second
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // updating energy and moving animatronics, checking screamers, victory and amount of energy
        // change the energy
        energy_.change_energy(cur_time_);

        // energy check
        if (energy_.cur_energy_ <= 0) {
            running = false;
            fclose(stdin);

            if (energy_lost()) {
                std::cout << "You lost" << std::endl;
            } else {
                std::cout << "You win!" << std::endl;
            }
        }

        // anims actions
        Bonnie.move_anim(gen_rand_, ldoor_.door_close_, time_);
        Chica.move_anim(gen_rand_, rdoor_.door_close_, time_);
        Foxy.move_anim(gen_rand_, ldoor_.door_close_, time_);

        Freddy.move_anim(gen_rand_, rdoor_.door_close_, false,
                         time_); // 'false' because moving freddy out of cameras

        // scream check
        if (Bonnie.scream_) {
            if (show_pict_) {
                picture_.show_scream(1);
            } else {
                picture_.show_text_scream(1);
            }
            running = false;
            fclose(stdin);
        }
        if (Chica.scream_) {
            if (show_pict_) {
                picture_.show_scream(2);
            } else {
                picture_.show_text_scream(2);
            }
            running = false;
            fclose(stdin);
        }
        if (Foxy.scream_) {
            if (show_pict_) {
                picture_.show_scream(3);
            } else {
                picture_.show_text_scream(3);
            }
            running = false;
            fclose(stdin);
        }
        if (Freddy.scream_) {
            if (show_pict_) {
                picture_.show_scream(4);
            } else {
                picture_.show_text_scream(4);
            }
            running = false;
            fclose(stdin);
        }

        // time update
        cur_time_ = std::chrono::steady_clock::now();
        time_ = std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count();

        // energy multiplicator update
        energy_.energy_mult_ = ldoor_.door_close_ + ldoor_.door_light_ + rdoor_.door_close_ +
                               rdoor_.door_light_ + player_.cams_status_ + 1;

        // victory check
        if (std::chrono::duration_cast<std::chrono::minutes>(cur_time_ - start_time_).count() >=
            6) {
            std::cout << "You won!" << std::endl;
            running = false;
            fclose(stdin);
        }
    }
}

/// @brief if player's energy is empty
/// @return returns true if the player wins, if the player looses returns false
bool Game::energy_lost() {
    int seconds_left = gen_rand_.get_rand(7, 15);
    auto current_time = std::chrono::steady_clock::now();

    for (int i = 0; i < seconds_left; i++) {
        std::cout
            << "Your energy is empty, doors are opened, light is off, Freddy is looking at you"
            << std::endl;

        if (std::chrono::duration_cast<std::chrono::minutes>(current_time - start_time_).count() >=
            6) {
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

/// @brief looking cameras
void Game::look_cams() {
    std::cout << "Here are the cams' names, input one to look through it: 1A, 1B, 5, 7, 1C, 3, 6, "
                 "2A, 2B, 4A, 4B; to escape cams mode input 'cams off' or 'coff'"
              << std::endl;

    std::string entered_cam = "";
    while (entered_cam != "cams off" and entered_cam != "coff" and running) {

        std::string entered_cam;
        std::getline(std::cin, entered_cam);
        if (!running) {
            std::cin.clear();
            std::cin.setstate(std::ios::failbit);
            break;
        }
        if (entered_cam == "cams off" or entered_cam == "coff") {
            break;
        }

        // everything will work if player enter 1a instead of 1A
        for (char &c : entered_cam) {
            c = std::toupper(static_cast<unsigned char>(c));
        }
        bool found = false;
        for (int i = 0; i < 11; i++) {
            if (cam_names_[i] == entered_cam) {
                bool bonnie = (cam_names_[i] == Bonnie.way_[Bonnie.place_ - 1]);
                bool chica = (cam_names_[i] == Chica.way_[Chica.place_ - 1]);
                bool foxy = (Foxy.place_ == 2);
                int foxy_stage = Foxy.stage_;
                bool freddy = (cam_names_[i] == Freddy.way_[Freddy.place_ - 1]);

                if (show_pict_) {
                    picture_.show_picture(cam_names_[i], bonnie, chica, foxy, foxy_stage, freddy);
                } else {
                    picture_.show_text(cam_names_[i], bonnie, chica, foxy, foxy_stage, freddy);
                }

                // moving Freddy here, because his moving depends on checking cameras by player
                if (cam_names_[i] == Freddy.way_[Freddy.place_ - 1] and cam_names_[i] == "4B") {
                    Freddy.move_anim(gen_rand_, rdoor_.door_close_, true, time_);
                }

                found = true;
                break;
            }
        }
        if (not found and (entered_cam != "coff" or entered_cam != "cams off")) {
            std::cout << "The cam with that name is not exist, to escape the cams mode input 'cams "
                         "off' or 'coff'"
                      << std::endl;
        }
    }
}

/// @brief creating of the animatronics
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
    } else if (num_night_ == 2) {
        Bonnie.intellegence_ = {3, 3, 3, 4, 5, 6};
        Chica.intellegence_ = {1, 1, 1, 2, 3, 3};
        Foxy.intellegence_ = {0, 0, 0, 2, 3, 3};
        Freddy.intellegence_ = {0, 0, 0, 0, 0, 0};
    } else if (num_night_ == 3) {
        Bonnie.intellegence_ = {0, 1, 1, 2, 2, 3};
        Chica.intellegence_ = {5, 5, 5, 6, 7, 7};
        Foxy.intellegence_ = {2, 2, 2, 3, 4, 4};
        Freddy.intellegence_ = {0, 1, 1, 1, 1, 1};
    } else if (num_night_ == 4) {
        Bonnie.intellegence_ = {2, 3, 4, 4, 5, 5};
        Chica.intellegence_ = {3, 3, 4, 5, 6, 6};
        Foxy.intellegence_ = {4, 4, 5, 6, 7, 8};
        Freddy.intellegence_ = {1, 1, 1, 2, 2, 2};
    } else if (num_night_ == 5) {
        Bonnie.intellegence_ = {5, 5, 6, 6, 7, 8};
        Chica.intellegence_ = {7, 7, 7, 8, 8, 9};
        Foxy.intellegence_ = {5, 5, 6, 6, 7, 7};
        Freddy.intellegence_ = {1, 2, 3, 3, 3, 3};
    }
}

/// @brief creating of the cameras
void Game::create_cams() {
    for (int i = 0; i < 11; i++) {
        cams_[i] = Cam(cam_names_[i]);
    }
}

Game::~Game() {
}
