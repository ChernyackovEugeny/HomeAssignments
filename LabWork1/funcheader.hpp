#ifndef ROTATE1
#define ROTATE1
#include "structs.hpp"
#include <fstream>

void rotate1(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize);

void rotate2(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize);

void init(std::ifstream& input, Bitmapinfo* bitmap, Fileheader* header);

void write(std::ofstream& rotate, Bitmapinfo* bitmap, Fileheader* header);
#endif
