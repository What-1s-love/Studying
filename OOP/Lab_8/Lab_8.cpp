#include <iostream>
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace std;


class Kolo; // ������� ����������

class PravylnyiBagatokutnyk {
private:
    int n;       // ʳ������ �����
    double a;    // ������� �������

public:
    PravylnyiBagatokutnyk(int sides, double sideLength) {
        n = sides;
        a = sideLength;
    }

    // ���������� ������ � ��������� ���� ����
    double createCircleAndReturnArea();

    friend class Kolo;
};

class Kolo {
private:
    double radius;

public:
    Kolo(double r) {
        radius = r;
    }

    double computeArea() {
        return M_PI * radius * radius;
    }

    friend class PravylnyiBagatokutnyk;
};

// ��������� ������ ���� ���� �����
double PravylnyiBagatokutnyk::createCircleAndReturnArea() {
    double radius = a / (2 * sin(M_PI / n));
    Kolo circle(radius);
    return circle.computeArea();
}

int main() {
    // ����������� �� ���������� ������������ � �������� 10
    PravylnyiBagatokutnyk rectangle(4, 10.0);

    // ������ ������, ���� ������� ���� � ������� ���� �����
    double area = rectangle.createCircleAndReturnArea();

    cout << "Area of the circumscribed circle: " << area << endl;

    return 0;
}
