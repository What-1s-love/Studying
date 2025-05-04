#include "Rectangle.h"

// Конструктор з 4 параметрами
Rectangle::Rectangle(int x1_, int y1_, int x2_, int y2_) {
    x1 = x1_;
    y1 = y1_;
    x2 = x2_;
    y2 = y2_;
}

// Конструктор з шириною і висотою, верхній лівий кут = (0, 0)
Rectangle::Rectangle(int width, int height) {
    x1 = 0;
    y1 = 0;
    x2 = width;
    y2 = height;
}

// Конструктор без параметрів
Rectangle::Rectangle() {
    x1 = y1 = x2 = y2 = 0;
}

// Метод переміщення
void Rectangle::move(int dx, int dy) {
    x1 += dx;
    x2 += dx;
    y1 += dy;
    y2 += dy;
}

// Метод дзеркального відображення по горизонталі (відносно x1)
void Rectangle::mirrorHorizontal() {
    int width = x2 - x1;
    x2 = x1 - width;
    // Обмін координат, якщо потрібно нормалізувати x1 < x2
    if (x2 > x1) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
}

// Перевантаження оператора виводу
ostream& operator<<(ostream& os, const Rectangle& rect) {
    os << "{(" << rect.x1 << ", " << rect.y1 << "), ("
        << rect.x2 << ", " << rect.y2 << ")}";
    return os;
}
