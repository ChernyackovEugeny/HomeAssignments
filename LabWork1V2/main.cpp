/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork1
*/

#include "Rotatebmp.hpp"
#include "structs.hpp"

int main() {
    Rotatebmp a;
    a.rotate_clockwise();
    a.show();
    a.clear();
    a.rotate_counterclw();
    a.show();
    a.clear();
    a.rotate_clockwise();
    a.create_kernel();
    a.apply_gaussian_blur();
    a.show();
    a.clear();
    return 1;
}
