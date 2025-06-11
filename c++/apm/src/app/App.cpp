#include <argumentParser/argumentParser.h>

int main(int argc, char** argv) {
    ArgumentParser parser;
    parser.parseArguments(argc, argv);

    return 0;
}
