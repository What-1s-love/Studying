#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Стандартний конструктор
    Circle();

    // Додатковий конструктор
    Circle(double r);

    // Сеттер і геттер
    void setRadius(double r);
    double getRadius();

    // Обчислення сторін квадратів
    double getInscribedSquareSide();
    double getCircumscribedSquareSide();

    // Вивід інформації про коло
    void printInfo();
};
