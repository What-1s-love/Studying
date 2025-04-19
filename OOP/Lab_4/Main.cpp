#include <iostream>
#include "LinearEquation.h"

using namespace std;

int main() {
    double a, b;
    cout << "Enter coefficients a and b for equation ax + b = 0: ";
    cin >> a >> b;

    // ��������� ��'���
    LinearEquation eq(a, b);
    eq.displayEquation();

    if (eq.isInfiniteSolutions()) {
        cout << "The equation has infinitely many solutions." << endl;
    }
    else if (eq.hasSolution()) {
        double root;
        eq.solveEquation(&root);
        cout << "Solution: x = " << root << endl;
    }
    else {
        cout << "No real solution." << endl;
    }

    // ��������� ��'���
    LinearEquation* eqPtr = new LinearEquation(a, b);
    eqPtr->displayEquation();

    if (eqPtr->isInfiniteSolutions()) {
        cout << "The equation has infinitely many solutions." << endl;
    }
    else if (eqPtr->hasSolution()) {
        double root;
        eqPtr->solveEquation(&root);
        cout << "Solution (dynamic object): x = " << root << endl;
    }
    else {
        cout << "No real solution (dynamic object)." << endl;
    }

    delete eqPtr; // ��������� ���'��

    return 0;
}
