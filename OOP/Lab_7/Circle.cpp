#include "Circle.h"

// Стандартний конструктор
Circle::Circle() {
    radius = 1.0;
}

// Додатковий конструктор
Circle::Circle(double r) {
    radius = r;
}

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getInscribedSquareSide() {
    return radius * sqrt(2);
}

double Circle::getCircumscribedSquareSide() {
    return 2 * radius;
}

void Circle::printInfo() {
    cout << "Circle {r = " << radius << "}" << endl;
}
