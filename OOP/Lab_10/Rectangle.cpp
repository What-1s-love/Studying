#include "Rectangle.h"

// ����������� � 4 �����������
Rectangle::Rectangle(int x1_, int y1_, int x2_, int y2_) {
    x1 = x1_;
    y1 = y1_;
    x2 = x2_;
    y2 = y2_;
}

// ����������� � ������� � �������, ������ ���� ��� = (0, 0)
Rectangle::Rectangle(int width, int height) {
    x1 = 0;
    y1 = 0;
    x2 = width;
    y2 = height;
}

// ����������� ��� ���������
Rectangle::Rectangle() {
    x1 = y1 = x2 = y2 = 0;
}

// ����� ����������
void Rectangle::move(int dx, int dy) {
    x1 += dx;
    x2 += dx;
    y1 += dy;
    y2 += dy;
}

// ����� ������������ ����������� �� ���������� (������� x1)
void Rectangle::mirrorHorizontal() {
    int width = x2 - x1;
    x2 = x1 - width;
    // ���� ���������, ���� ������� ������������ x1 < x2
    if (x2 > x1) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
}

// �������������� ��������� ������
ostream& operator<<(ostream& os, const Rectangle& rect) {
    os << "{(" << rect.x1 << ", " << rect.y1 << "), ("
        << rect.x2 << ", " << rect.y2 << ")}";
    return os;
}
