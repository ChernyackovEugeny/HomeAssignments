// the realisation of the application of the Gaussian filter

#include "funcheader.hpp"
#include "structs.hpp"

void create_kernel(double** kernel, int kSize, double sigma) {
    double sum = 0.0;
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            double x = i - kSize / 2;
            double y = j - kSize / 2;
            double value = (1 / (2 * M_PI * sigma * sigma) * exp(-(x*x + y*y) / (2 * sigma * sigma)));
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

void gaus(Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize) {
    int kSize = 3;
    double sigma = 1.0;
    
    double** kernel = new double*[kSize];
    
    for (int i = 0; i < kSize; i++) {
        kernel[i] = new double[kSize]; 
    }
    
    create_kernel(kernel, kSize, sigma);
    apply_gaus(kernel, bitmap, header, biTable, rowSize, kSize);
    
    for (int i = 0; i < kSize; i++) {
        delete[] kernel[i]; 
    }
    delete[] kernel; 
}

void apply_gaus(double** kernel, Bitmapinfo* bitmap, Fileheader* header, uint8_t* biTable, int rowSize, int kSize) {
    std::ofstream gau;
    gau.open("gaus.bmp", std::ios::binary | std::ios::out);
    
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

    uint8_t* gaus_data = new uint8_t[bitmap->biHeight * rowSize];
    for (int i = 0; i < origHeight; i++) {
        for (int j = 0; j < origWidth; j++) {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++) {
                gaus_data[(j * origHeight + i) * (bitmap->biBitCount / 8) + k] =
                    biTable[(i * origrowSize) + (origWidth - 1 - j) * (bitmap->biBitCount / 8) + k];
            }
        }
    }
    
    uint8_t* ans = new uint8_t[bitmap->biHeight * rowSize];
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
                        int pixelIndex = curi * rowSize + curj * 3;
                        double kvalue = kernel[halfSize+ki][halfSize+kj];
                        
                        red_sum += gaus_data[pixelIndex] * kvalue;
                        green_sum += gaus_data[pixelIndex] * kvalue;
                        blue_sum += gaus_data[pixelIndex] * kvalue;
                    }
                }
            }
            int outputIndex = i*rowSize + 3*j;
            ans[outputIndex] = static_cast<uint8_t>(std::min(std::max(0, int(red_sum)), 255));
            ans[outputIndex+1] = static_cast<uint8_t>(std::min(std::max(0, int(green_sum)), 255));
            ans[outputIndex+2] = static_cast<uint8_t>(std::min(std::max(0, int(blue_sum)), 255));
        }
    }
    
    write(gau, bitmap, header);
    
    for (int i = 0; i < bitmap->biHeight; i++) {
        gau.write(reinterpret_cast<char*>(&ans[rowSize*i]), rowSize);
    }
    
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;
    
    delete[] gaus_data;
    delete[] ans;
    
}

