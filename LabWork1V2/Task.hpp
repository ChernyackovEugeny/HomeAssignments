// the hpp file of the class

#ifndef TASK
#define TASK
// Правила большинства кодстайлов включают в себя "include what u use", но не больше
// Многие из этих включений в этом файле не нужны
#include "structs.hpp"
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>
// Имя класса должно соответствовать его назначению
class Task {
    public:
        Task();
        void rotate1();
        void rotate2();
        void gaus();
        ~Task();
        
    private:
        Fileheader* header;
        Bitmapinfo* bitmap;
        int rowSize;
        uint8_t* biTable;

        double** kernel;
        int kSize;
        double sigma;
        
        void create_kernel();
        void apply_gaus();

        void read();
        
};


#endif
