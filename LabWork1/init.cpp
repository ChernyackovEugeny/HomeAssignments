// the initialising the variables of the structures

#include "funcheader.hpp"
#include "structs.hpp"

void init(std::ifstream &input, Bitmapinfo *bitmap, Fileheader *header) {
    input.read(reinterpret_cast<char *>(&header->Ftype), sizeof(header->Ftype));
    input.read(reinterpret_cast<char *>(&header->Fsize), sizeof(header->Fsize));
    input.read(reinterpret_cast<char *>(&header->Rez1), sizeof(header->Rez1));
    input.read(reinterpret_cast<char *>(&header->Rez2), sizeof(header->Rez2));
    input.read(reinterpret_cast<char *>(&header->Px_begin), sizeof(header->Px_begin));

    input.read(reinterpret_cast<char *>(&bitmap->biSize), sizeof(bitmap->biSize));
    input.read(reinterpret_cast<char *>(&bitmap->biWidth), sizeof(bitmap->biWidth));
    input.read(reinterpret_cast<char *>(&bitmap->biHeight), sizeof(bitmap->biHeight));
    input.read(reinterpret_cast<char *>(&bitmap->biPlanes), sizeof(bitmap->biPlanes));
    input.read(reinterpret_cast<char *>(&bitmap->biBitCount), sizeof(bitmap->biBitCount));
    input.read(reinterpret_cast<char *>(&bitmap->biCompression), sizeof(bitmap->biCompression));
    input.read(reinterpret_cast<char *>(&bitmap->biSizeImage), sizeof(bitmap->biSizeImage));
    input.read(reinterpret_cast<char *>(&bitmap->biXPelsPerMeter), sizeof(bitmap->biXPelsPerMeter));
    input.read(reinterpret_cast<char *>(&bitmap->biYPelsPerMeter), sizeof(bitmap->biYPelsPerMeter));
    input.read(reinterpret_cast<char *>(&bitmap->biClrUsed), sizeof(bitmap->biClrUsed));
    input.read(reinterpret_cast<char *>(&bitmap->biClrImportant), sizeof(bitmap->biClrImportant));

    input.read(reinterpret_cast<char *>(&bitmap->RMask), sizeof(bitmap->RMask));
    input.read(reinterpret_cast<char *>(&bitmap->GMask), sizeof(bitmap->GMask));
    input.read(reinterpret_cast<char *>(&bitmap->BMask), sizeof(bitmap->BMask));
    input.read(reinterpret_cast<char *>(&bitmap->AMask), sizeof(bitmap->AMask));

    input.read(reinterpret_cast<char *>(&bitmap->CSType), sizeof(bitmap->CSType));
    input.read(reinterpret_cast<char *>(&bitmap->Endpoints), sizeof(bitmap->Endpoints));
    input.read(reinterpret_cast<char *>(&bitmap->bIntent), sizeof(bitmap->bIntent));
    input.read(reinterpret_cast<char *>(&bitmap->bProfileData), sizeof(bitmap->bProfileData));
    input.read(reinterpret_cast<char *>(&bitmap->bProfileSize), sizeof(bitmap->bProfileSize));
    input.read(reinterpret_cast<char *>(&bitmap->bReserved), sizeof(bitmap->bReserved));
}
