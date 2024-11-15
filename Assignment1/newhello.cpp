/* Chernyackov Eugeny st128891@spbu.ru
Assignment 1
*/

#include <iostream>

#include "heading.hpp"

void say_hello()
{
    using namespace std;
    cout << "Hello, world!" << endl;
    while (true)
    {
        string x;
        cin >> x;
        cout << "Hello, " << x << "!" << endl;
    }
}
