#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

int main() {
    const int SIZE = 5;

    // ��������� ����� ��'���� Circle
    Circle circles[SIZE];

    double inputRadius;

    // �������� ������ ��� ������� ���� ����� ����� � ������������ (����������� �����������)
    cout << "Enter radius for the first circle (default constructor will be overridden): ";
    cin >> inputRadius;
    circles[0].setRadius(inputRadius); // ������������� ���������� ��������

    // �������� ������ ��� ����� �� ����� ���������� �����������
    for (int i = 1; i < SIZE; ++i) {
        cout << "Enter radius for circle #" << i + 1 << ": ";
        cin >> inputRadius;
        circles[i] = Circle(inputRadius);
    }

    // ���� ��� ��'����
    cout << "\nDisplaying all circles:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Circle #" << i + 1 << ": ";
        circles[i].printInfo();
    }

    // ���������� ���������� �������� ����� �������� ��������
    double sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += circles[i].getInscribedSquareSide();
    }
    double average = sum / SIZE;

    cout << "\nAverage side of inscribed square: " << average << endl;

    // ����� ���� � �������� ��������� ��������, ���������� �� ����������
    int closestIndex = 0;
    double minDiff = fabs(circles[0].getInscribedSquareSide() - average);

    for (int i = 1; i < SIZE; ++i) {
        double diff = fabs(circles[i].getInscribedSquareSide() - average);
        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = i;
        }
    }

    // ��������� ���� � ���������� ���������
    cout << "\nThe circle with the inscribed square side closest to the average:\n";
    circles[closestIndex].printInfo();
    cout << "Its inscribed square �side: " << circles[closestIndex].getInscribedSquareSide() << endl;

    return 0;
}
