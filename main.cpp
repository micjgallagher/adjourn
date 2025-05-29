#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

#include "deps/json.hpp"
using json = nlohmann::json;

#include "consts.h"
#include "main.hpp"

int main (int argc, char **argv) {
    //Checking if if the adjourn directory exists
    if(fs::exists(prependHome(path_local_dir))){
        std::cout << "This exists\n";
    } else{
        std::cout << "Does not exist\n";
    }
    return 0;
}


/*
json read_file() {
    std::ifstream f(fp);
    return json::parse(f);
}
*/

void write_file(char *fp, json j) {
    std::ofstream o(fp);
    o << std::setw(4) << j << std::endl;
}


bool confirm_action(char *msg) {
    std::cout << msg << "(y/n)\n> ";
    std::string in;
    std::cin >> in;
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    return in == "y" || in == "yes";
}

fs::path prependHome(std::string path){
    const std::string home = std::getenv("HOME"); 
    const fs::path output{home + "/" + path};
    return output;
}
