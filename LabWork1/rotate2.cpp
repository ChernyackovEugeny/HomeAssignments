// // the turn of the picture 90 degrees counterclockwise

#include "funcheader.hpp"
#include "structs.hpp"

void rotate2(Bitmapinfo *bitmap, Fileheader *header, uint8_t *biTable, int rowSize) {
    std::ofstream rotate2;
    rotate2.open("rotate2.bmp", std::ios::binary | std::ios::out);

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

    uint8_t *rotated2_data = new uint8_t[bitmap->biHeight * rowSize];

    for (int i = 0; i < origHeight; i++) {
        for (int j = 0; j < origWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                rotated2_data[(j * origHeight + (origHeight - 1 - i)) * (bitmap->biBitCount / 8) +
                              k] = biTable[(i * origrowSize) + (j * (bitmap->biBitCount / 8)) + k];
            }
        }
    }

    write(rotate2, bitmap, header);

    for (int i = 0; i < bitmap->biHeight; i++) {
        rotate2.write(reinterpret_cast<char *>(&rotated2_data[rowSize * i]), rowSize);
    }
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] rotated2_data;
}
