#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
    double radius;

   
    cout << "Enter radius of the circle (static object): ";
    cin >> radius;

    Circle A;
    A.setRadius(radius);

    cout << "Radius of circle = " << A.getRadius() << endl;
    cout << "Side of inscribed square = " << A.getInscribedSquareSide() << endl;
    cout << "Side of circumscribed square = " << A.getCircumscribedSquareSide() << endl;


    cout << "\nEnter radius of the circle (dynamic object): ";
    cin >> radius;

    Circle* B = new Circle();
    B->setRadius(radius);

    cout << "Radius of circle = " << B->getRadius() << endl;
    cout << "Side of inscribed square = " << B->getInscribedSquareSide() << endl;
    cout << "Side of circumscribed square = " << B->getCircumscribedSquareSide() << endl;

    delete B; // Звільняємо пам'ять для динамічного об'єкта
    return 0;
}