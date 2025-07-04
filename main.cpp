#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

#include "deps/json.hpp"
using json = nlohmann::json;

#include "consts.h"
#include "main.hpp"

int main (int argc, char **argv) {

    if(argc <= 1){
        std::cout << "Please enter a subcommand" << std::endl;
        return 0;
    }
    std::string subcommand = argv[1];

    if(subcommand==cmd_read){
        std::cout << "Using Read\n";
    }
    else if(subcommand == cmd_write){
        std::cout << "Using write\n";
    }
    else if (subcommand == cmd_list){
        std::cout << "using list\n";
    }
    else if (subcommand== cmd_switch){

        std::cout << "using switch\n";
    }
    else{
        std::cout << "Not A Valid Subcommand\n";
    }

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

fs::path getDir(std::string path, bool create){
    const std::string _path = prependHome(path);
    const fs::path fp{_path};
    if(!fs::exists(_path) && create){
        fs::create_directories(fp);
    }
    return fp;
}

fs::path getDir(std::string path){
    return getDir(path, true);
}


std::fstream getFile(std::string path, bool create){
    const std::string _path = prependHome(path);
    const fs::path fp{_path};

    fs::path parent(fp.parent_path());
    if(!fs::exists(parent) && create) {
        fs::create_directories(parent);
    }

    std::fstream f(fp);
    return f;
}

std::fstream getFile(std::string path){
    return getFile(path, true);
}

