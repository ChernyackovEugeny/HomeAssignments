#include "Picture.hpp"
#include <string>
#include <fstream>
#include <iostream>

Picture::Picture() {}

void Picture::show_picture(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage, bool freddy) {
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
    }
    else if (foxy and cam_name == "2A") {
        result = result + "_Fo";
    }
    else if (foxy and cam_name == "1C") {
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

void Picture::show_text(std::string cam_name, bool bonnie, bool chica, bool foxy, int foxy_stage, bool freddy) {
    if (bonnie) {
        std::cout << "Bonnie is here!" << std::endl;
    }
    if (chica) {
        std::cout << "Chica is here!" << std::endl;
    }
    
    if (not foxy and cam_name == "1C") {
        if (foxy_stage == 1) {
            std::cout << "Foxy is behind the curtain" << std::endl;
        }
        else if (foxy_stage == 2) {
            std::cout << "You can see the Foxy's head" << std::endl;
        }
        else if (foxy_stage == 3) {
            std::cout << "Foxy is near the scene" << std::endl;
        }
    }
    else if (foxy and cam_name == "2A") {
        std::cout << "FOXY IS RUNNING!" << std::endl;
    }
    else if (foxy and cam_name == "1C") {
    	std::cout << "FOXY IS OUT!" << std::endl;
    }
    
    if (freddy) {
        std::cout << "Freddy is here!" << std::endl;
    }
}

void Picture::show_scream(int scream) {
    if (scream != 0) {
        std::string result = "arts/Scream_";
        if (scream == 1) {
            result = result + "B.txt";
        }
        else if (scream == 2) {
            result = result + "C.txt";
        }
        else if (scream == 3) {
            result = result + "Fo.txt";
        }
        else if (scream == 4) {
            result = result + "Fr.txt";
        }
        
        std::ifstream file(result);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
}
   
void Picture::show_text_scream(int scream) {
    if (scream != 0) {
        if (scream == 1) {
            std::cout << "Bonnie is screaming, you lost" << std::endl;
        }
        else if (scream == 2) {
            std::cout << "Chica is screaming, you lost" << std::endl;
        }
        else if (scream == 3) {
            std::cout << "Foxy is screaming, you lost" << std::endl;
        }
        else if (scream == 4) {
            std::cout << "Freddy is screaming, you lost" << std::endl;
        }
    }
}

Picture::~Picture() {}
