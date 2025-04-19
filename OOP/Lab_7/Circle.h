#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // ����������� �����������
    Circle();

    // ���������� �����������
    Circle(double r);

    // ������ � ������
    void setRadius(double r);
    double getRadius();

    // ���������� ����� ��������
    double getInscribedSquareSide();
    double getCircumscribedSquareSide();

    // ���� ���������� ��� ����
    void printInfo();
};
