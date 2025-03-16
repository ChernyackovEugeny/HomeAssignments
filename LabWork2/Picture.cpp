/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "Picture.hpp"
#include <fstream>
#include <iostream>
#include <string>

Picture::Picture() {
}

/// @brief function shows pictures on the cameras
/// @param cam_name shows the name of the current camera
/// @param bonnie shows whether Bonny is on the current camera or not
/// @param chica shows whether Chica is on the current camera or not
/// @param foxy shows whether Foxy is on the current camera or not
/// @param foxy_stage shows the stage of Foxy
/// @param freddy shows whether Freddy is on the current camera or not
void Picture::show_picture(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage,
                           bool freddy) {
    std::string result = "arts/";
    result = result + cam_name;
    if (bonnie) {
        result = result + "_B";
    }
    if (chica) {
        result = result + "_C";
    }

    if (not foxy and cam_name == "1C") {
        result = result + "_Fo_" + std::to_string(foxy_stage);
    } else if (foxy and cam_name == "2A") {
        result = result + "_Fo";
    } else if (foxy and cam_name == "1C") {
        result = result + "_Fo_4";
    }

    if (freddy) {
        result = result + "_Fr";
    }
    result = result + ".txt";

    std::ifstream file(result);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

/// @brief function text feedback from the game
/// @param cam_name shows the name of the current camera
/// @param bonnie shows whether Bonny is on the current camera or not
/// @param chica shows whether Chica is on the current camera or not
/// @param foxy shows whether Foxy is on the current camera or not
/// @param foxy_stage shows the stage of Foxy
/// @param freddy shows whether Freddy is on the current camera or not
void Picture::show_text(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage,
                        bool freddy) {
    if (bonnie) {
        std::cout << "Bonnie is here!" << std::endl;
    }
    if (chica) {
        std::cout << "Chica is here!" << std::endl;
    }

    if (not foxy and cam_name == "1C") {
        if (foxy_stage == 1) {
            std::cout << "Foxy is behind the curtain" << std::endl;
        } else if (foxy_stage == 2) {
            std::cout << "You can see the Foxy's head" << std::endl;
        } else if (foxy_stage == 3) {
            std::cout << "Foxy is near the scene" << std::endl;
        }
    } else if (foxy and cam_name == "2A") {
        std::cout << "FOXY IS RUNNING!" << std::endl;
    } else if (foxy and cam_name == "1C") {
        std::cout << "FOXY IS OUT!" << std::endl;
    }

    if (freddy) {
        std::cout << "Freddy is here!" << std::endl;
    }
}

/// @brief function screams the player with picture
/// @param scream shows whether the player is screammed or not
void Picture::show_scream(int scream) {
    if (scream != 0) {
        std::string result = "arts/Scream_";
        if (scream == 1) {
            result = result + "B.txt";
        } else if (scream == 2) {
            result = result + "C.txt";
        } else if (scream == 3) {
            result = result + "Fo.txt";
        } else if (scream == 4) {
            result = result + "Fr.txt";
        }

        std::ifstream file(result);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
}

/// @brief function screams the player with text
/// @param scream shows whether the player is screammed or not
void Picture::show_text_scream(int scream) {
    if (scream != 0) {
        if (scream == 1) {
            std::cout << "Bonnie is screaming, you lost" << std::endl;
        } else if (scream == 2) {
            std::cout << "Chica is screaming, you lost" << std::endl;
        } else if (scream == 3) {
            std::cout << "Foxy is screaming, you lost" << std::endl;
        } else if (scream == 4) {
            std::cout << "Freddy is screaming, you lost" << std::endl;
        }
    }
}

/// @brief function shows pictures in the office
/// @param bonnie shows whether Bonny is near the office or not
/// @param chica shows whether Chica is near the office or not
/// @param left_light shows whether the left door light is on or off
/// @param right_light shows whether the right door light is on or off
/// @param left_close shows whether the left door is opened or not
/// @param right_close shows whether the right door is opened or not
void Picture::show_office(int bonnie, int chica, bool left_light, bool right_light, bool left_close, bool right_close) {
    std::string result = "arts/office";
    if (left_light) {
        result = result + "_ll";
    }
    if (right_light) {
        result = result + "_rl";
    }
    if (left_close) {
        result = result + "_lc";
    }
    if (right_close) {
        result = result + "_rc";
    }
    if (bonnie == 7) {
        result = result + "_B";
    }
    if (chica == 7) {
        result = result + "_C";
    }
    result = result + ".txt";

    std::ifstream file(result);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

Picture::~Picture() {
}
