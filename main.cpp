#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <iterator>

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
    //later this will need to be rewritten so that it can interface to vim
    char * c_edit_var = std::getenv("EDITOR");
    if(c_edit_var != NULL){
        std::string EDIT_VAR(std::getenv("EDITOR"));
        std::string command(EDIT_VAR);
        
        std::string fileName = createMemFile();

       command += EDIT_VAR = " " + fileName;
        system(command.c_str());
        // system("cat /dev/shm/adjourn");
        
        //Reading
        std::fstream file = getFile(fileName);
        stringFromFile(file);
        file.close();

        deleteMemFile(fileName);
    }
    std::string output = "Temp output";
    // system("$EDITOR test");
    return output;
}

std::string stringFromFile(std::fstream file){
    std::string contents{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    return contents;
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
    fs::path filePath{"/dev/shm/adjourn"}; //TODO ensure that this link is to a unqiue file
    std::string command("touch ");
    command += filePath.string();
    system(command.c_str());
    return filePath;
}

void deleteMemFile(fs::path filePath){
    std::string command("rm ");
    command += filePath.string();
    system(command.c_str());
}

