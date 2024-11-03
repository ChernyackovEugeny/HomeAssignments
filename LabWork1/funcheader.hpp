// the header with used functions

#ifndef ROTATE1
#define ROTATE1
#include "structs.hpp"

void rotate1(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize);

void rotate2(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize);

void init(std::ifstream& input, Bitmapinfo* bitmap, Fileheader* header);

void write(std::ofstream& rotate, Bitmapinfo* bitmap, Fileheader* header);

void gaus(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize);

void create_kernel(double** kernel, int kSize, double sigma);

void apply_gaus(double** kernel, Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize, int kSize);
#endif
