#include <iostream>
#include <fstream>
#include <filesystem>
#include "DATAF.hpp"


void dataf() {	
	int size = std::filesystem::file_size("source.pdf");
	char* q = new char[size];
	
	std::ifstream infile;
	infile.open("source.pdf", std::ios::binary | std::ios::in);
	
	infile.read(q, size);
	
	for (int i = 0; i < int(size/2); i++) {
		char tmp = q[i];
		q[i] = q[size-i-1];
		q[size-i-1] = tmp;
}
	
	std::ofstream outfile;
	outfile.open("temppdf.pdf", std::ios::binary | std::ios::out);
	
	outfile.write(q, size);
}	
