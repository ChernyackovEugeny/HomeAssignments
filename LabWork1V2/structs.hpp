// the header of the structs

#ifndef STRUCTS
#define STRUCTS
#include <cstdint>

#pragma pack(push, 1)
struct Fileheader
{
    uint16_t Ftype; // file type
    uint32_t Fsize; // file size
    uint16_t Rez1; // reserved zero
    uint16_t Rez2; // reserved zero
    uint32_t Px_begin; // the begining of description of pixels
};

// Px_begin = 138; 138-14=124 => the version of BITMAPINFO is 5 => 32 bits for each variable

struct Bitmapinfo
{
    uint32_t biSize; // the size of bitmapinfo          DWORD
    int32_t biWidth; // the width of picture in pixels         LONG
    int32_t biHeight; // abs(biHeight) - height of the picture in pixels; sign(biHeight) - the order of the rows in 2-D array
    uint16_t biPlanes; // reserved for 1
    uint16_t biBitCount; // amount of bits for 1 pixel (bit depth)
    uint32_t biCompression; // the way to store pixels
    uint32_t biSizeImage; // the size of pixels data in bytes
    int32_t biXPelsPerMeter; // amount of pixels per meter horizontally
    int32_t biYPelsPerMeter; // amount of pixels per meter vertically
    uint32_t biClrUsed; // the size of color table in the cells
    uint32_t biClrImportant; // amount of cells from the begining of the color table to the last used cell(including itself)

    // additions version 4
    uint32_t RMask; // bit masks, the intensity of red, green, blue and the value of the alpha channel
    uint32_t GMask;
    uint32_t BMask;
    uint32_t AMask;

    uint32_t CSType; // the type of the color space, if doesn't includes 0, next 4 variables are not used
    struct
    {
        uint32_t RGamma;
        uint32_t GGamma;
        uint32_t BGamma;
        uint32_t AGamma;
    } Endpoints[3];

    // additions version 5
    uint32_t bIntent;
    uint32_t bProfileData;
    uint32_t bProfileSize;
    uint32_t bReserved; // reserved for 0
};
#pragma pack(pop)

#endif
