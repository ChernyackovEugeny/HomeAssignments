// the primary function

#include <iostream>
#include "PZAPIS.hpp"
// Не пиши названия транслитом, пиши на английском
void pzapis() {
	std::string st;
	std::getline(std::cin, st);
	// А если там больше 100 чисел?
	double * q = new double[100];
	int up = 0;
	
	std::string cur;
	// Следует отделить функциональность стека от калькулятора. Получилось слишком громоздко
	for (long unsigned int i = 0; i < st.length(); i++) {
		
		if (st[i] == ' ') {
			if (!(st[i-1] == '+' || st[i-1] == '-' || st[i-1] == '/' || st[i-1] == '*')) {
				q[up] = std::stoi(cur);
				cur = "";
			}
			if (!(st[i+1] == '+' || st[i+1] == '-' || st[i+1] == '/' || st[i+1] == '*')) {
				up += 1;
			}
		}

		else if (st[i] == '+') {
			q[up-1] = q[up-1]+q[up];
			q[up] = 0;
			up -= 1;
		}
		// Минус еще бывает унарный
		else if (st[i] == '-') {
			q[up-1] = q[up-1]-q[up];
			q[up] = 0;
			up -= 1;
		}
		
		else if (st[i] == '/') {
			q[up-1] = q[up-1]/q[up];
			q[up] = 0;
			up -= 1;
		}
		
		else if (st[i] == '*') {
			q[up-1] = q[up-1]*q[up];
			q[up] = 0;
			up -= 1;
		}
		
		else {
			cur += st[i];
		}
	}
	
	std::cout << q[0] << std::endl;
	delete[] q;
}
