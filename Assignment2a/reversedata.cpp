/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 2a
*/

#include "reversedata.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

void reversedata(std::string name)
{
    int size = std::filesystem::file_size(name);
    std::unique_ptr<char[]> data = std::make_unique<char[]>(size);

    std::ifstream infile;
    infile.open(name, std::ios::binary | std::ios::in);

    infile.read(data.get(), size);

    for (int i = 0; i < int(size / 2); i++)
    {
        char tmp = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = tmp;
    }

    std::ofstream outfile;
    outfile.open("reverseddata.pdf", std::ios::binary | std::ios::out);

    outfile.write(data.get(), size);
}
