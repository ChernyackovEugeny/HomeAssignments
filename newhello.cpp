#include "heading.hpp"
#include <iostream>

int say_hello() {
	using namespace std;
	cout << "Hello, world!" << endl;
	while (true) {
		string x;
		cin >> x;
		cout << "Hello, " << x << "!" << endl;
	}
	return 0;
}
