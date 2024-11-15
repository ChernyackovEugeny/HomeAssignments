/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork1
*/

#include "Rotatebmp.hpp"
#include "structs.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>

Rotatebmp::Rotatebmp(int kernelSize, double sigmaa) {
    header = new Fileheader;
    bitmap = new Bitmapinfo;
    kSize = kernelSize;
    sigma = sigmaa;
    kernel = nullptr;
    read();
}
Rotatebmp::Rotatebmp() {
    header = new Fileheader;
    bitmap = new Bitmapinfo;
    kSize = 3;
    sigma = 1.0;
    kernel = nullptr;
    read();
}
void Rotatebmp::read() {
    std::string name;
    std::cout << "Please, enter the name of your bmp file" << std::endl;
    std::cin >> name;

    std::ifstream input;
    input.open(name, std::ios::binary | std::ios::in);

    input.read(reinterpret_cast<char *>(header), sizeof(*header));
    input.read(reinterpret_cast<char *>(bitmap), sizeof(*bitmap));

    origrowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    origbiTable = new char[origrowSize * bitmap->biHeight];

    for (int i = 0; i < bitmap->biHeight; i++) {
        input.read(&origbiTable[origrowSize * i], origrowSize);
    }
    currowSize = origrowSize;
    origWidth = bitmap->biWidth;
    origHeight = bitmap->biHeight;
    origbiSizeImage = bitmap->biSizeImage;
    origFsize = header->Fsize;

    curbiTable = new char[origrowSize * bitmap->biHeight];
    std::copy(origbiTable, origbiTable + origrowSize * bitmap->biHeight, curbiTable);
}

void Rotatebmp::show() {
    std::string name;
    std::cout << "Please, enter the name of file you want to see as a result: ";
    std::cin >> name;

    std::ofstream output;
    output.open(name, std::ios::binary | std::ios::out);

    output.write(reinterpret_cast<char *>(header), sizeof(*header));
    output.write(reinterpret_cast<char *>(bitmap), sizeof(*bitmap));

    for (int i = 0; i < bitmap->biHeight; i++) {
        output.write(&curbiTable[currowSize * i], currowSize);
    }
}

void Rotatebmp::clear() {
    currowSize = origrowSize;
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] curbiTable;
    curbiTable = new char[origrowSize * bitmap->biHeight];
    std::copy(origbiTable, origbiTable + origrowSize * bitmap->biHeight, curbiTable);
}

void Rotatebmp::rotate_clockwise() {
    int32_t tempWidth = bitmap->biWidth;
    int32_t tempHeight = bitmap->biHeight;

    bitmap->biWidth = tempHeight;
    bitmap->biHeight = tempWidth;

    int temprowSize = currowSize;
    currowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    bitmap->biSizeImage = currowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;

    char *rotated1_data = new char[bitmap->biHeight * currowSize];
    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                rotated1_data[(j * tempHeight + i) * (bitmap->biBitCount / 8) + k] =
                    curbiTable[(i * temprowSize) + (tempWidth - 1 - j) * (bitmap->biBitCount / 8) +
                               k];
            }
        }
    }

    delete[] curbiTable;
    curbiTable = new char[bitmap->biHeight * currowSize];
    std::copy(rotated1_data, rotated1_data + currowSize * bitmap->biHeight, curbiTable);

    delete[] rotated1_data;
}

void Rotatebmp::rotate_counterclw() {
    int32_t tempWidth = bitmap->biWidth;
    int32_t tempHeight = bitmap->biHeight;

    bitmap->biWidth = tempHeight;
    bitmap->biHeight = tempWidth;

    int temprowSize = currowSize;
    currowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    bitmap->biSizeImage = currowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;

    char *rotated2_data = new char[bitmap->biHeight * currowSize];

    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                rotated2_data[(j * tempHeight + (tempHeight - 1 - i)) * (bitmap->biBitCount / 8) +
                              k] =
                    curbiTable[(i * temprowSize) + (j * (bitmap->biBitCount / 8)) + k];
            }
        }
    }

    delete[] curbiTable;
    curbiTable = new char[bitmap->biHeight * currowSize];
    std::copy(rotated2_data, rotated2_data + currowSize * bitmap->biHeight, curbiTable);

    delete[] rotated2_data;
}

void Rotatebmp::create_kernel() {
    kernel = new double *[kSize];
    for (int i = 0; i < kSize; i++) {
        kernel[i] = new double[kSize];
    }
    double sum = 0.0;
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            double x = i - kSize / 2;
            double y = j - kSize / 2;
            double value =
                (1 / (2 * M_PI * sigma * sigma) * exp(-(x * x + y * y) / (2 * sigma * sigma)));
            kernel[i][j] = value;
            sum += value;
        }
    }

    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            kernel[i][j] /= sum;
        }
    }
}

void Rotatebmp::apply_gaussian_blur() {
    if (kernel == nullptr) {
        create_kernel();
    }
    char *ans = new char[bitmap->biHeight * currowSize];
    int halfSize = kSize / 2;
    for (int i = 0; i < bitmap->biHeight; i++) {
        for (int j = 0; j < bitmap->biWidth; j++) {
            double red_sum = 0.0;
            double green_sum = 0.0;
            double blue_sum = 0.0;

            for (int ki = -halfSize; ki <= halfSize; ki++) {
                for (int kj = -halfSize; kj <= halfSize; kj++) {
                    int curi = i + ki;
                    int curj = j + kj;

                    if (curi >= 0 && curi < bitmap->biHeight && curj >= 0 &&
                        curj < bitmap->biWidth) {
                        int pixelIndex = curi * currowSize + curj * 3;
                        double kvalue = kernel[halfSize + ki][halfSize + kj];

                        red_sum += static_cast<uint8_t>(curbiTable[pixelIndex]) * kvalue;
                        green_sum += static_cast<uint8_t>(curbiTable[pixelIndex + 1]) * kvalue;
                        blue_sum += static_cast<uint8_t>(curbiTable[pixelIndex + 2]) * kvalue;
                    }
                }
            }
            int outputIndex = i * currowSize + 3 * j;
            ans[outputIndex] = static_cast<char>(std::min(std::max(0, int(red_sum)), 255));
            ans[outputIndex + 1] = static_cast<char>(std::min(std::max(0, int(green_sum)), 255));
            ans[outputIndex + 2] = static_cast<char>(std::min(std::max(0, int(blue_sum)), 255));
        }
    }

    delete[] curbiTable;
    curbiTable = new char[bitmap->biHeight * currowSize];
    std::copy(ans, ans + currowSize * bitmap->biHeight, curbiTable);

    delete[] ans;
}

Rotatebmp::~Rotatebmp() {
    delete header;
    delete bitmap;
    delete[] origbiTable;
    delete[] curbiTable;
    for (int i = 0; i < kSize; i++) {
        delete[] kernel[i];
    }
    delete[] kernel;
}
