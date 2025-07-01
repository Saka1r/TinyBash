#include <string>
#include <fstream>
#include <iostream>

std::string Read_file(const std::string& name_file)
{
    std::ifstream file(name_file);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
        }
    }
    file.close();
    return line;
}