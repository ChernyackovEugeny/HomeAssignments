#include "funcheader.hpp"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

void rotate2(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize) {
	std::ofstream rotate2;
    rotate2.open("rotate2.bmp", std::ios::binary | std::ios::out);
    
    uint8_t* rotated2_data = new uint8_t[bitmap->biHeight * rowSize]; 
    
    for (int i = 0; i < bitmap->biHeight; i++) {
        for (int j = 0; j < bitmap->biWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                rotated2_data[(j * bitmap->biHeight + (bitmap->biHeight - 1 - i)) * (bitmap->biBitCount / 8) + k] = biTable[(i * rowSize) + (j * (bitmap->biBitCount / 8)) + k];
            }
        }
    }
    
    int32_t origWidth = bitmap->biWidth;
    int32_t origHeight = bitmap->biHeight;
    uint32_t origbiSizeImage = bitmap->biSizeImage;
    uint32_t origFsize = header->Fsize;
    
    bitmap->biWidth = origHeight;
    bitmap->biHeight = origWidth;
    
    rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;
    
    bitmap->biSizeImage = rowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;
    
    
    write(rotate2, bitmap, header);
    
    
    for (int i = 0; i < bitmap->biHeight; i++) {
        rotate2.write(reinterpret_cast<char*>(&rotated2_data[rowSize*i]), rowSize);
    }
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;
    
    delete[] rotated2_data;
}
