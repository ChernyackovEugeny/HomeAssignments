// the main function

#include "funcheader.hpp"
#include "structs.hpp"

int main()
{
    std::ifstream input;

    input.open("example.bmp", std::ios::binary | std::ios::in);

    Fileheader* header = new Fileheader;
    Bitmapinfo* bitmap = new Bitmapinfo;

    init(input, bitmap, header);

    int rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    uint8_t* biTable = new uint8_t[rowSize*bitmap->biHeight];

    for (int i = 0; i < bitmap->biHeight; i++)
    {
        input.read(reinterpret_cast<char*>(&biTable[rowSize*i]), rowSize);
    }

    rotate1(bitmap, header, biTable, rowSize);
    rotate2(bitmap, header, biTable, rowSize);
    gaus(bitmap, header, biTable, rowSize);

    delete[] biTable;
    delete header;
    delete bitmap;
}


