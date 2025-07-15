#ifndef CLI_HH
#define CLI_HH

#include <string>
#include <unordered_map>

namespace CLI {
    enum Commands {
        NEW
    };

    extern std::unordered_map<std::string, Commands> commandMap;

    void parseArgs(int argc, char** argv);
    void newCommand();
    void run(int argc, char** argv);
};

#endif