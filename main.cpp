#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

#include "deps/json.hpp"
using json = nlohmann::json;

#include "consts.h"
#include "main.hpp"

int main (int argc, char **argv) {
    return 0;
}


json read_file(char *fp) {
    std::ifstream f(fp);
    return json::parse(f);
}

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


std::string prependHome(std::string path){
    const std::string home = std::getenv("HOME"); 
    return home + "/" + path;
}

fs::path getPath(std::string path, bool isFile, bool create){
    const std::string _path = prependHome(path);
    const fs::path output{_path};
    if(!fs::exists(_path) && create){
        if (isFile) {
            // TODO
        } else {
            fs::create_directories(output);
        }
    }
    return output;
}

fs::path getPath(std::string path, bool isFile){
    return getPath(path, isFile, true);
}

