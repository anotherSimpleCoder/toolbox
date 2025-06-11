//
// Created by amsakan on 20.05.25.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <string>


class ArgumentParser {
private:
  void help();
public:
    int parseArguments(int argc, char** argv);
};

#endif //ARGUMENTPARSER_H
