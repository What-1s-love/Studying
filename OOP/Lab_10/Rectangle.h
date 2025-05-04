#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle {
private:
    int x1, y1; // left-top
    int x2, y2; // right-bottom

public:
    // Конструктор з 4 параметрами
    Rectangle(int x1_, int y1_, int x2_, int y2_);

    // Конструктор з шириною та висотою
    Rectangle(int width, int height);

    // Конструктор без параметрів
    Rectangle();

    // Метод переміщення прямокутника
    void move(int dx, int dy);

    // Метод дзеркального відображення по горизонталі (відносно x1)
    void mirrorHorizontal();

    // Дружня функція для перевантаження << 
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
};

#endif
