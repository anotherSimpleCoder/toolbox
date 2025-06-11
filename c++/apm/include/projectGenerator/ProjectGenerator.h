//
// Created by amsakan on 20.05.25.
//

#ifndef PROJECTGENERATOR_H
#define PROJECTGENERATOR_H
#include <string>

class ProjectGenerator {
private:
  std::string projectName;
  void createProjectDirectory();
public:
  void generate(std::string projectName);
};
#endif //PROJECTGENERATOR_H
