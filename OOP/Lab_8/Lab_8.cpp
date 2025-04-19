#include <iostream>
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace std;


class Kolo; // Наперед оголошення

class PravylnyiBagatokutnyk {
private:
    int n;       // Кількість сторін
    double a;    // Довжина сторони

public:
    PravylnyiBagatokutnyk(int sides, double sideLength) {
        n = sides;
        a = sideLength;
    }

    // Оголошення методу — реалізація буде зовні
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

// Реалізація методу поза тілом класу
double PravylnyiBagatokutnyk::createCircleAndReturnArea() {
    double radius = a / (2 * sin(M_PI / n));
    Kolo circle(radius);
    return circle.computeArea();
}

int main() {
    // Прямокутник як правильний чотирикутник зі стороною 10
    PravylnyiBagatokutnyk rectangle(4, 10.0);

    // Виклик методу, який створює коло і повертає його площу
    double area = rectangle.createCircleAndReturnArea();

    cout << "Area of the circumscribed circle: " << area << endl;

    return 0;
}
