#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <string>

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
        std::cout << "Testing input";
        std::cout << stringFromUser();
    }
    else if (subcommand == cmd_list){
        std::cout << "using list\n";
    }
    else if (subcommand== cmd_switch){

        std::cout << "using switch";
    }
    else{
        std::cout << "Not A Valid Subcommand";
    }

    return 0;
}

std::string stringFromUser(){
    std::string output = "";

    char * c_editor_var = std::getenv("EDITOR");
    char * c_visual_var = std::getenv("VISUAL");

    std::string EDIT_VAR = "vi";
    if (c_editor_var != NULL) {
        EDIT_VAR = c_editor_var;
    } else if (c_visual_var != NULL) {
        EDIT_VAR = c_visual_var;
    }

    std::string fileName = createMemFile();
    free(c_editor_var);
    free(c_visual_var);

    system((EDIT_VAR + " " + fileName).c_str());

    //Reading
    std::fstream file = getFile(fileName);
    output = stringFromFile(file);
    file.close();

    deleteMemFile(fileName);
    return output;
}

std::string stringFromFile(std::fstream &file){
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
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
std::string createMemFile(){
    time_t t;
    time(&t);
    std::string fpath = "/dev/shm/adjourn" + std::to_string(t);
    return fpath;
}

void deleteMemFile(fs::path filePath){
    std::remove(filePath.c_str());
}

