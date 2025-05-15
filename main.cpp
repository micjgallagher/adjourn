#include <iostream>
#include <string.h>

#include "deps/json.hpp"
using json = nlohmann::json;


const char *cmd_write = "write";


bool confirm_action(char *msg) {
    std::cout << msg << "(y/n)\n> ";
    char *in;
    std::cin >> in;
    return strcmp(in, "y");
}



int main (int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << "\n";
    }
    std::cout << "Initial Commit for adjourn\n";
    return 0;
}

