// the turn of the picture 90 degrees clockwise

#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>

#include "funcheader.hpp"

void rotate1(Bitmapinfo *bitmap, Fileheader *header, uint8_t *biTable, int rowSize) {
    std::ofstream rotate1;
    rotate1.open("rotate1.bmp", std::ios::binary | std::ios::out);

    int32_t origWidth = bitmap->biWidth;
    int32_t origHeight = bitmap->biHeight;
    uint32_t origbiSizeImage = bitmap->biSizeImage;
    uint32_t origFsize = header->Fsize;
    int origrowSize = rowSize;

    bitmap->biWidth = origHeight;
    bitmap->biHeight = origWidth;

    rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    bitmap->biSizeImage = rowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;

    uint8_t *rotated1_data = new uint8_t[bitmap->biHeight * rowSize];
    for (int i = 0; i < origHeight; i++) {
        for (int j = 0; j < origWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                rotated1_data[(j * origHeight + i) * (bitmap->biBitCount / 8) + k] =
                    biTable[(i * origrowSize) + (origWidth - 1 - j) * (bitmap->biBitCount / 8) + k];
            }
        }
    }

    write(rotate1, bitmap, header);

    for (int i = 0; i < bitmap->biHeight; i++) {
        rotate1.write(reinterpret_cast<char *>(&rotated1_data[rowSize * i]), rowSize);
    }

    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] rotated1_data;
}
