#include "NewCommand.hh"

#include <fstream>
#include <sstream>


NewCommand::Project NewCommand::NewProject() {
    Project project{};

    project.projectName = "";
    project.cmakeVersion = "3.30";
    project.cxxVersion = 23;

    return project;
}

std::string NewCommand::StringifyProject(Project& project) {
    std::ostringstream commandStringStream;

    commandStringStream << "cmake_minimum_required(VERSION " << project.cmakeVersion << ")\n";
    commandStringStream << "project(" << project.projectName << ")\n";
    commandStringStream << "set(CMAKE_CXX_STANDARD " << project.cxxVersion << ")\n";
    commandStringStream << "\n";
    commandStringStream << "include_directories(\"${CMAKE_SOURCE_DIR}/include\")\n";
    commandStringStream << "\n";
    commandStringStream << "add_subdirectory(src)\n";

    return commandStringStream.str();
}

void NewCommand::SrcCMakeFile(Project &project) {
    std::ofstream srcFileStream(project.projectName + "/src/CMakeLists.txt");
    std::ostringstream srcCMakeStringStream;

    srcCMakeStringStream << "add_subdirectory(Main)\n";
    srcFileStream << srcCMakeStringStream.str();

    srcFileStream.close();
}

void NewCommand::MainCMakeFile(Project &project) {
    std::ofstream mainFileStream(project.projectName + "/src/Main/CMakeLists.txt");
    std::ostringstream mainCMakeStringStream;

    mainCMakeStringStream << "add_executable(Main\n";
    mainCMakeStringStream << "\t Main.cc\n";
    mainCMakeStringStream << ")";

    mainFileStream << mainCMakeStringStream.str();
    mainFileStream.close();
}

void NewCommand::WriteMainFile(Project &project) {
    std::ofstream mainFile(project.projectName + "/src/Main/Main.cc");
    mainFile << "int main(int argc, char** argv) {\n";
    mainFile << "\treturn 0;\n";
    mainFile << "}";

    mainFile.close();
}


void NewCommand::WriteFile(Project& project) {
    std::ofstream projectFileStream(project.projectName + "/CMakeLists.txt");
    projectFileStream << StringifyProject(project);
    projectFileStream.close();

    SrcCMakeFile(project);
    MainCMakeFile(project);
    WriteMainFile(project);
}