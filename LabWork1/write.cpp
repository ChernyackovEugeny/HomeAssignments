// writing into the file

#include "funcheader.hpp"
#include "structs.hpp"

void write(std::ofstream& rotate, Bitmapinfo* bitmap, Fileheader* header)
{
    rotate.write(reinterpret_cast<char*>(&header->Ftype), sizeof(header->Ftype));
    rotate.write(reinterpret_cast<char*>(&header->Fsize), sizeof(header->Fsize));
    rotate.write(reinterpret_cast<char*>(&header->Rez1), sizeof(header->Rez1));
    rotate.write(reinterpret_cast<char*>(&header->Rez2), sizeof(header->Rez2));
    rotate.write(reinterpret_cast<char*>(&header->Px_begin), sizeof(header->Px_begin));

    rotate.write(reinterpret_cast<char*>(&bitmap->biSize), sizeof(bitmap->biSize));
    rotate.write(reinterpret_cast<char*>(&bitmap->biWidth), sizeof(bitmap->biWidth));
    rotate.write(reinterpret_cast<char*>(&bitmap->biHeight), sizeof(bitmap->biHeight));
    rotate.write(reinterpret_cast<char*>(&bitmap->biPlanes), sizeof(bitmap->biPlanes));
    rotate.write(reinterpret_cast<char*>(&bitmap->biBitCount), sizeof(bitmap->biBitCount));
    rotate.write(reinterpret_cast<char*>(&bitmap->biCompression), sizeof(bitmap->biCompression));
    rotate.write(reinterpret_cast<char*>(&bitmap->biSizeImage), sizeof(bitmap->biSizeImage));
    rotate.write(reinterpret_cast<char*>(&bitmap->biXPelsPerMeter), sizeof(bitmap->biXPelsPerMeter));
    rotate.write(reinterpret_cast<char*>(&bitmap->biYPelsPerMeter), sizeof(bitmap->biYPelsPerMeter));
    rotate.write(reinterpret_cast<char*>(&bitmap->biClrUsed), sizeof(bitmap->biClrUsed));
    rotate.write(reinterpret_cast<char*>(&bitmap->biClrImportant), sizeof(bitmap->biClrImportant));

    rotate.write(reinterpret_cast<char*>(&bitmap->RMask), sizeof(bitmap->RMask));
    rotate.write(reinterpret_cast<char*>(&bitmap->GMask), sizeof(bitmap->GMask));
    rotate.write(reinterpret_cast<char*>(&bitmap->BMask), sizeof(bitmap->BMask));
    rotate.write(reinterpret_cast<char*>(&bitmap->AMask), sizeof(bitmap->AMask));
    rotate.write(reinterpret_cast<char*>(&bitmap->CSType), sizeof(bitmap->CSType));
    rotate.write(reinterpret_cast<char*>(&bitmap->Endpoints), sizeof(bitmap->Endpoints));
    rotate.write(reinterpret_cast<char*>(&bitmap->bIntent), sizeof(bitmap->bIntent));
    rotate.write(reinterpret_cast<char*>(&bitmap->bProfileData), sizeof(bitmap->bProfileData));
    rotate.write(reinterpret_cast<char*>(&bitmap->bProfileSize), sizeof(bitmap->bProfileSize));
    rotate.write(reinterpret_cast<char*>(&bitmap->bReserved), sizeof(bitmap->bReserved));
}
