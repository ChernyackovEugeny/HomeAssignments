// the cpp file of the class

#include "structs.hpp"
#include "Task.hpp"

Task::Task() {

    header = new Fileheader;
    bitmap = new Bitmapinfo;
    read();
}
// То что нельзя ввести свое имя файла не очень хорошо
void Task::read() {
    std::ifstream input;
    
    input.open("example.bmp", std::ios::binary | std::ios::in);
    // Ты же инициализируешь их в конструкторе. Те указатели теряются и происходит утечка памяти
    header = new Fileheader;
    bitmap = new Bitmapinfo;
    
    input.read(reinterpret_cast<char*>(header), sizeof(*header));
    input.read(reinterpret_cast<char*>(bitmap), sizeof(*bitmap));

    rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;
    // Обычно все-таки берут char, который по стандарту должен иметь минимальный адресуемый размер (1 байт)
    biTable = new uint8_t[rowSize*bitmap->biHeight];

    for (int i = 0; i < bitmap->biHeight; i++)
    {
        input.read(reinterpret_cast<char*>(&biTable[rowSize*i]), rowSize);
    }

}
// А один это влево или вправо? 
// "- Извините, а как пройти в библиотеку?
//  - Сначала дойдите до конца улицы, а потом 1
//  - !?"
void Task::rotate1() {
    std::ofstream rotate1;
    rotate1.open("rotate1.bmp", std::ios::binary | std::ios::out);

    int32_t origWidth = bitmap->biWidth;
    int32_t origHeight = bitmap->biHeight;
    uint32_t origbiSizeImage = bitmap->biSizeImage;
    uint32_t origFsize = header->Fsize;
    int origrowSize = rowSize;

    bitmap->biWidth = origHeight;
    bitmap->biHeight = origWidth;
    // А ты сможешь ответить на занятии, что эта строка делает? Я ж спрошу
    rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;
    
    bitmap->biSizeImage = rowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;


    uint8_t* rotated1_data = new uint8_t[bitmap->biHeight * rowSize];
    for (int i = 0; i < origHeight; i++)
    {
        for (int j = 0; j < origWidth; j++)
        {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++)
            {
                rotated1_data[(j * origHeight + i) * (bitmap->biBitCount / 8) + k] =
                    biTable[(i * origrowSize) + (origWidth - 1 - j) * (bitmap->biBitCount / 8) + k];
            }
        }
    }
    
    rotate1.write(reinterpret_cast<char*>(header), sizeof(*header));
    rotate1.write(reinterpret_cast<char*>(bitmap), sizeof(*bitmap));

    for (int i = 0; i < bitmap->biHeight; i++)
    {
        rotate1.write(reinterpret_cast<char*>(&rotated1_data[rowSize*i]), rowSize);
    }
    // Строки ниже дают понять, что нужно как-то иначе использовать класс картинки
    // Если бы я дважды хотел повернуть картинку в одну сторону, то как бы я смог это сделать?
    // Как будто этот метод должен возвращать полноценную копию, к которой в свою очередь снова можно 
    // применить все операции
    rowSize = origrowSize;
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] rotated1_data;
}

void Task::rotate2() {
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


    uint8_t* rotated2_data = new uint8_t[bitmap->biHeight * rowSize];

    for (int i = 0; i < origHeight; i++)
    {
        for (int j = 0; j < origWidth; j++)
        {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++)
            {
                rotated2_data[(j * origHeight + (origHeight - 1 - i)) * (bitmap->biBitCount / 8) + k] = biTable[(i * origrowSize) + (j * (bitmap->biBitCount / 8)) + k];
            }
        }
    }

    rotate2.write(reinterpret_cast<char*>(header), sizeof(*header));
    rotate2.write(reinterpret_cast<char*>(bitmap), sizeof(*bitmap));


    for (int i = 0; i < bitmap->biHeight; i++)
    {
        rotate2.write(reinterpret_cast<char*>(&rotated2_data[rowSize*i]), rowSize);
    }
    rowSize = origrowSize;
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] rotated2_data;
}
// ApplyGaussianBlur -- вот это хорошее название
void Task::gaus() {
    // Мне кажется, это должно быть параметром класса, который задается конструктором
    kSize = 3;
    sigma = 1.0;
    
    kernel = new double*[kSize];
    for (int i = 0; i < kSize; i++)
    {
        kernel[i] = new double[kSize];
    }
    create_kernel();
    apply_gaus();
    // Чтобы не заниматься такой работой, используй стандартные контейнеры или умные указатели
    // Не хочу видеть в вашем коде никаких new или delete
    for (int i = 0; i < kSize; i++)
    {
        delete[] kernel[i];
    }
    delete[] kernel; 
}

void Task::create_kernel() {
    double sum = 0.0;
    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            double x = i - kSize / 2;
            double y = j - kSize / 2;
            double value = (1 / (2 * M_PI * sigma * sigma) * exp(-(x*x + y*y) / (2 * sigma * sigma)));
            kernel[i][j] = value;
            sum += value;
        }
    }

    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            kernel[i][j] /= sum;
        }
    }
}

void Task::apply_gaus() {
    std::ofstream gau;
    gau.open("gaus.bmp", std::ios::binary | std::ios::out);

    int32_t origWidth = bitmap->biWidth;
    int32_t origHeight = bitmap->biHeight;
    uint32_t origbiSizeImage = bitmap->biSizeImage;
    uint32_t origFsize = header->Fsize;
    int origrowSize = rowSize;
    // А зачем тут опять происходит поворот? Функция должна делать только что-то одно
    bitmap->biWidth = origHeight;
    bitmap->biHeight = origWidth;

    rowSize = (bitmap->biWidth * bitmap->biBitCount / 8 + 3) & ~3;

    bitmap->biSizeImage = rowSize * bitmap->biHeight;
    header->Fsize = sizeof(Fileheader) + sizeof(Bitmapinfo) + bitmap->biSizeImage;

    uint8_t* gaus_data = new uint8_t[bitmap->biHeight * rowSize];
    for (int i = 0; i < origHeight; i++)
    {
        for (int j = 0; j < origWidth; j++)
        {
            for (int k = 0; k < (bitmap->biBitCount / 8); k++)
            {
                gaus_data[(j * origHeight + i) * (bitmap->biBitCount / 8) + k] =
                    biTable[(i * origrowSize) + (origWidth - 1 - j) * (bitmap->biBitCount / 8) + k];
            }
        }
    }

    uint8_t* ans = new uint8_t[bitmap->biHeight * rowSize];
    int halfSize = kSize / 2;
    for (int i = 0; i < bitmap->biHeight; i++)
    {
        for (int j = 0; j < bitmap->biWidth; j++)
        {
            double red_sum = 0.0;
            double green_sum = 0.0;
            double blue_sum = 0.0;

            for (int ki = -halfSize; ki <= halfSize; ki++)
            {
                for (int kj = -halfSize; kj <= halfSize; kj++)
                {
                    int curi = i + ki;
                    int curj = j + kj;

                    if (curi >= 0 && curi < bitmap->biHeight && curj >= 0 &&
                            curj < bitmap->biWidth)
                    {
                        int pixelIndex = curi * rowSize + curj * 3;
                        double kvalue = kernel[halfSize+ki][halfSize+kj];

                        red_sum += gaus_data[pixelIndex] * kvalue;
                        green_sum += gaus_data[pixelIndex+1] * kvalue;
                        blue_sum += gaus_data[pixelIndex+2] * kvalue;
                    }
                }
            }
            int outputIndex = i*rowSize + 3*j;
            ans[outputIndex] = static_cast<uint8_t>(std::min(std::max(0, int(red_sum)), 255));
            ans[outputIndex+1] = static_cast<uint8_t>(std::min(std::max(0, int(green_sum)), 255));
            ans[outputIndex+2] = static_cast<uint8_t>(std::min(std::max(0, int(blue_sum)), 255));
        }
    }

    gau.write(reinterpret_cast<char*>(header), sizeof(*header));
    gau.write(reinterpret_cast<char*>(bitmap), sizeof(*bitmap));

    for (int i = 0; i < bitmap->biHeight; i++)
    {
        gau.write(reinterpret_cast<char*>(&ans[rowSize*i]), rowSize);
    }
    
    rowSize = origrowSize;
    bitmap->biWidth = origWidth;
    bitmap->biHeight = origHeight;
    bitmap->biSizeImage = origbiSizeImage;
    header->Fsize = origFsize;

    delete[] gaus_data;
    delete[] ans;
}

Task::~Task() {
    delete header;
    delete bitmap;
    delete[] biTable;
}
