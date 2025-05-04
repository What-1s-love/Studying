#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle {
private:
    int x1, y1; // left-top
    int x2, y2; // right-bottom

public:
    // ����������� � 4 �����������
    Rectangle(int x1_, int y1_, int x2_, int y2_);

    // ����������� � ������� �� �������
    Rectangle(int width, int height);

    // ����������� ��� ���������
    Rectangle();

    // ����� ���������� ������������
    void move(int dx, int dy);

    // ����� ������������ ����������� �� ���������� (������� x1)
    void mirrorHorizontal();

    // ������ ������� ��� �������������� << 
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
};

#endif
