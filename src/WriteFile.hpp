#include <string>
#include <fstream>
#include <iostream>

std::string Write_file(const std::string& name_file, const std::string& stringForWrite)
{
    std::ofstream out;
    out.open("name_file");
    if (out.is_open())
    {
        out << stringForWrite << std::endl;
    }
    out.close();
}
