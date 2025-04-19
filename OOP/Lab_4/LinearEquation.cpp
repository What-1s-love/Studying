#include "LinearEquation.h"

LinearEquation::LinearEquation(double a, double b) : a(a), b(b) {}

bool LinearEquation::hasSolution() {
    return a != 0 || b == 0; // � ��������, ���� a ? 0 ��� b = 0 (������� ����������� ��������)
}

bool LinearEquation::isInfiniteSolutions() {
    return a == 0 && b == 0; // ��������� ��������, ���� a = 0 � b = 0
}

void LinearEquation::solveEquation(double* x) {
    if (hasSolution() && !isInfiniteSolutions()) {
        *x = -b / a; // ����������� ������
    }
}

void LinearEquation::displayEquation() {
    std::cout << "Equation: " << a << "x + " << b << " = 0" << std::endl;
}
