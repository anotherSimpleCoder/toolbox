#pragma once

#include <string>

namespace NewCommand {
    struct Project {
        std::string projectName;
        std::string cmakeVersion;
        int cxxVersion = -1;
    };

    Project NewProject();
    std::string StringifyProject(Project& project);
    void SrcCMakeFile(Project& project);
    void MainCMakeFile(Project& project);
    void WriteMainFile(Project& project);
    void WriteFile(Project& project);
};