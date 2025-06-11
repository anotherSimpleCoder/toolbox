#include "argumentParser/argumentParser.h"

void ArgumentParser::help() {
    std::cout << "apm - a package manager" << std::endl;
    std::cout << "new\t\t" << "Creates a new apm project" << std::endl;
    std::cout << "run\t\t" << "Run apm project" << std::endl;
    std::cout << "test\t" << "Run tests of an apm project" << std::endl;
}

int ArgumentParser::parseArguments(int argc, char** argv) {
    if (argc < 2) {
        help();
        return 0;
    }

    const std::string firstArgument = argv[1];

    if (firstArgument == "new") {
        std::cout << "Creating project" << std::endl;
    } else if (firstArgument == "run") {
        std::cout << "Running" << std::endl;
    } else if (firstArgument == "test") {
        std::cout << "Testing" << std::endl;
    } else {
        std::cerr << "Invalid argument " << firstArgument << std::endl;
        std::cerr << "\n";
        help();
        return 1;
    }
}