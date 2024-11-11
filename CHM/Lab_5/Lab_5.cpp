#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Нові значення x і y
    float x[9] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    float y[9] = { 2.4, 2.9, 3.6, 4.2, 5.1, 5.8, 6.3, 7.8, 9.5 };

    // Змінні для обчислення середніх значень
    float x_ar = 0, x_geo = 0, x_gar = 0, y_ar = 0, y_geo = 0, y_gar = 0;
    float sumX = 0, sumY = 0;
    float dobX = 1, dobY = 1;
    float sum1X = 0, sum1Y = 0;
    float Y[9] = { 0 };
    float xi = 0, xi_1 = 0, yi = 0, yi_1 = 0;
    bool check = false;
    float minusX = 0, minusY = 0;
    float final[9] = { 0 };

    // Обчислення середніх значень
    for (int i = 0; i < 9; i++) {
        sumX += x[i];
        dobX *= x[i];
        sum1X += 1.0 / x[i];
        sumY += y[i];
        dobY *= y[i];
        sum1Y += 1.0 / y[i];
    }

    x_ar = sumX / 9;
    x_geo = pow(dobX, 1.0 / 9);
    x_gar = 9 / sum1X;

    y_ar = sumY / 9;
    y_geo = pow(dobY, 1.0 / 9);
    y_gar = 9 / sum1Y;

    cout << "x_ar = " << x_ar << endl;
    cout << "x_geo = " << x_geo << endl;
    cout << "x_gar = " << x_gar << endl;
    cout << "\n\n";
    cout << "y_ar = " << y_ar << endl;
    cout << "y_geo = " << y_geo << endl;
    cout << "y_gar = " << y_gar << endl;
    cout << "\n\n";

    // Пошук значень xi та xi_1 для інтерполяції
    for (int i = 0; i < 9; i++) {
        if (x[i] > xi && x[i] < x_ar) {
            xi = x[i];
            yi = y[i];
        }
    }

    for (int i = 0; i < 9; i++) {
        if (x[i] > xi_1 && x[i] > x_ar && check == false) {
            xi_1 = x[i];
            yi_1 = y[i];
            check = true;
        }
    }

    cout << "xi = " << xi << endl;
    cout << "xi_1 = " << xi_1 << endl;
    cout << "\n";
    cout << "yi = " << yi << endl;
    cout << "yi_1 = " << yi_1 << endl;
    cout << "\n";

    // Інтерполяція для обчислення Y
    minusX = xi_1 - xi;
    minusY = yi_1 - yi;
    cout << "minusX = " << minusX << endl;
    cout << "minusY = " << minusY << endl;
    cout << "\n";

    Y[0] = yi + (minusY / minusX) * (x_ar - xi);
    Y[1] = yi + (minusY / minusX) * (x_geo - xi);
    Y[2] = yi + (minusY / minusX) * (x_gar - xi);
    Y[3] = yi + (minusY / minusX) * (x_ar - xi);
    Y[4] = yi + (minusY / minusX) * (x_geo - xi);
    Y[5] = yi + (minusY / minusX) * (x_gar - xi);
    Y[6] = yi + (minusY / minusX) * (x_ar - xi);
    Y[7] = yi + (minusY / minusX) * (x_geo - xi);
    Y[8] = yi + (minusY / minusX) * (x_gar - xi);

    for (int i = 0; i < 9; i++) {
        cout << "Y[" << i << "] = " << Y[i] << endl;
    }
    cout << "\n";

    // Обчислення відносної похибки для кожного виду середнього значення
    for (int i = 0; i < 3; i++) {
        final[i] = fabs((y_ar - Y[i]) / Y[i]);
    }

    for (int i = 3; i < 6; i++) {
        final[i] = fabs((y_geo - Y[i]) / Y[i]);
    }

    for (int i = 6; i < 9; i++) {
        final[i] = fabs((y_gar - Y[i]) / Y[i]);
    }

    for (int i = 0; i < 9; i++) {
        cout << "final[" << i << "] = " << final[i] << endl;
    }

    // Пошук мінімальної похибки
    float min = final[0];
    int number = 0;
    for (int i = 0; i < 9; i++) {
        if (min > final[i]) {
            min = final[i];
            number = i + 1;
        }
    }
    cout << "Min equation is " << number << " and value of this equation = " << min << endl;

    return 0;
}
