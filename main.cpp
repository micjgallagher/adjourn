#include <iostream>

#include "deps/json.hpp"
using json = nlohmann::json;


int main (int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << "\n";
    }
    std::cout << "Initial Commit for adjourn\n";
    return 0;
}

