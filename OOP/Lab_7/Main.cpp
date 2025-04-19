#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

int main() {
    const int SIZE = 5;

    // Створюємо масив об'єктів Circle
    Circle circles[SIZE];

    double inputRadius;

    // Введення радіусу для першого кола через діалог з користувачем (стандартний конструктор)
    cout << "Enter radius for the first circle (default constructor will be overridden): ";
    cin >> inputRadius;
    circles[0].setRadius(inputRadius); // Перевизначаємо стандартне значення

    // Введення радіусів для інших кіл через додатковий конструктор
    for (int i = 1; i < SIZE; ++i) {
        cout << "Enter radius for circle #" << i + 1 << ": ";
        cin >> inputRadius;
        circles[i] = Circle(inputRadius);
    }

    // Вивід усіх об'єктів
    cout << "\nDisplaying all circles:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Circle #" << i + 1 << ": ";
        circles[i].printInfo();
    }

    // Обчислення середнього значення сторін вписаних квадратів
    double sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += circles[i].getInscribedSquareSide();
    }
    double average = sum / SIZE;

    cout << "\nAverage side of inscribed square: " << average << endl;

    // Пошук кола зі стороною вписаного квадрату, найближчою до середнього
    int closestIndex = 0;
    double minDiff = fabs(circles[0].getInscribedSquareSide() - average);

    for (int i = 1; i < SIZE; ++i) {
        double diff = fabs(circles[i].getInscribedSquareSide() - average);
        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = i;
        }
    }

    // Виведення кола з найближчим значенням
    cout << "\nThe circle with the inscribed square side closest to the average:\n";
    circles[closestIndex].printInfo();
    cout << "Its inscribed square яside: " << circles[closestIndex].getInscribedSquareSide() << endl;

    return 0;
}
