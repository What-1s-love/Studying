#include <iostream>
#include "Rectangle.h"

int main() {
    // Створення об'єктів
    Rectangle r1(1, 2, 5, 6);
    Rectangle r2(4, 3);
    Rectangle r3;

    cout << "Initial Rectangles:" << endl;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;

    // Переміщення r1
    r1.move(2, -1);
    cout << "\nr1 after move(2, -1): " << r1 << endl;

    // Дзеркальне відображення r2
    r2.mirrorHorizontal();
    cout << "r2 after mirrorHorizontal(): " << r2 << endl;

    return 0;
}
