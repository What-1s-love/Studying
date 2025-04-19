#pragma once
#include <iostream>

class LinearEquation {
private:
    double a, b;

public:
    LinearEquation(double a, double b); // �����������
    bool hasSolution();                 // �������� �������� ��������
    bool isInfiniteSolutions();         // �������� �� ��������� ��������
    void solveEquation(double* x);      // ����� ��� ����������� ������
    void displayEquation();             // ��������� �������
};
