// the primary function

#include <iostream>
#include <fstream>
#include <filesystem>
#include "DATAF.hpp"

// А если у меня файл не source.pdf называется? Сделай название параметром функции
// Функция должна быть полезной для переиспользования и другими людьми
void dataf() {	
	int size = std::filesystem::file_size("source.pdf");
	// Память очистить можно и забыть. Узнай про умные указатели
	char* q = new char[size];
	
	std::ifstream infile;
	infile.open("source.pdf", std::ios::binary | std::ios::in);
	
	infile.read(q, size);
	for (int i = 0; i < int(size/2); i++) {
		char tmp = q[i];
		q[i] = q[size-i-1];
		q[size-i-1] = tmp;
} // Форматирование кода сделай какое-нибудь (clang-format например)
	
	std::ofstream outfile;
	outfile.open("temppdf.pdf", std::ios::binary | std::ios::out);
	
	outfile.write(q, size);
	
	delete[] q;
}	
