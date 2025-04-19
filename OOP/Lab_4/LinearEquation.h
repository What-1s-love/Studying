#pragma once
#include <iostream>

class LinearEquation {
private:
    double a, b;

public:
    LinearEquation(double a, double b); // Конструктор
    bool hasSolution();                 // Перевірка наявності розв’язку
    bool isInfiniteSolutions();         // Перевірка на нескінченні розв’язки
    void solveEquation(double* x);      // Метод для знаходження кореня
    void displayEquation();             // Виведення рівняння
};
