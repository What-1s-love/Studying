#include "LinearEquation.h"

LinearEquation::LinearEquation(double a, double b) : a(a), b(b) {}

bool LinearEquation::hasSolution() {
    return a != 0 || b == 0; // Є розв’язок, якщо a ? 0 або b = 0 (випадок нескінченних розв’язків)
}

bool LinearEquation::isInfiniteSolutions() {
    return a == 0 && b == 0; // Нескінченні розв’язки, якщо a = 0 і b = 0
}

void LinearEquation::solveEquation(double* x) {
    if (hasSolution() && !isInfiniteSolutions()) {
        *x = -b / a; // Знаходження кореня
    }
}

void LinearEquation::displayEquation() {
    std::cout << "Equation: " << a << "x + " << b << " = 0" << std::endl;
}
