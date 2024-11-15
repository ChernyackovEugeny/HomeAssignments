/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork1
*/

#ifndef ROTATEBMP
#define ROTATEBMP
#include "structs.hpp"
#include <cstdint>

class Rotatebmp {
    public:
        Rotatebmp(int kernelSize, double sigmaa);
        Rotatebmp();
        void rotate_clockwise();
        void rotate_counterclw();
        void create_kernel();
        void apply_gaussian_blur();
        
        void show();
        void clear();
        
        ~Rotatebmp();
        
    private:
        Fileheader* header;
        Bitmapinfo* bitmap;
        int origrowSize;
        int32_t origWidth;
        int32_t origHeight;
        uint32_t origbiSizeImage;
        uint32_t origFsize;
        char* origbiTable;
        
        int currowSize;
        char* curbiTable;

        double** kernel;
        int kSize;
        double sigma;

        void read();
        
};


#endif
