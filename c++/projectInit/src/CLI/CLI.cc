#include "CLI.hh"
#include "NewCommand.hh"

#include <filesystem>
#include <limits>
#include <iostream>
#include <string>

namespace CLI {
    std::unordered_map<std::string, Commands> commandMap = {
        {"new", Commands::NEW}
    };
};

void CLI::parseArgs(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "Insufficient arguments!\n";
        return;
    }

    auto command = commandMap[argv[1]];
    switch(command) {
        case Commands::NEW: {
            newCommand();
            break;
        }
    }
}

void CLI::newCommand() {
    NewCommand::Project project;

    std::cout << "ProjectInit - C++ Project Init\n";
    std::cout << "==============================\n";
    std::cout << "\n";
    
    std::cout << "Project name: ";
    std::cin >> project.projectName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "CMake Version (3.30): ";
    std::getline(std::cin, project.cmakeVersion);
    if (project.cmakeVersion.empty()) {
        project.cmakeVersion = "3.30";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    std::cout << "C++ Standard (23): ";
    std::getline(std::cin, line);
    if (line.empty()) {
        project.cxxVersion = 23;
    } else {
        project.cxxVersion = std::stoi(line);
    }

    std::filesystem::create_directories(project.projectName + "/src/Main");
    std::filesystem::create_directories(project.projectName + "/include");
    std::filesystem::create_directories(project.projectName + "/build");

    NewCommand::WriteFile(project);

    std::cout << "Project \"" << project.projectName << "\" created successfully!\n";
}

void CLI::run(int argc, char** argv) {
    parseArgs(argc, argv);
}