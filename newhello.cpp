#include "heading.hpp"
#include <iostream>

void say_hello() {
	using namespace std;
	cout << "Hello, world!" << endl;
	while (true) {
		string x;
		cin >> x;
		cout << "Hello, " << x << "!" << endl;
	}
}
