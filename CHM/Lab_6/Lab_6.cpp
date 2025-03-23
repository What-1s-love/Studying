#include <iostream>
#include <cmath>
#include <iomanip> // Для форматування виводу
using namespace std;

void Simpson(double* x, double* y, double h, int m, int n, double* simpsons, int i);
double R(double* simpsons, int i);
double summ_for_even(int m, double* y);
double summ_for_odd(int m, double* y);
void input(double& a, double& b, double& epsilon);

void function(double a, double b, double epsilon) {
    int m = 1;
    double h = 0;
    int counter = 0;
    double* simpsons = nullptr; // Масив для результатів інтегрування
    double prev_value = 0;  // Попереднє значення інтегралу

    while (true) {
        m *= 2;
        h = (b - a) / (2 * m);
        int n = 2 * m;

        // Виділення пам'яті для масивів
        double* x = new double[n + 1];
        double* y = new double[n + 1];
        if (simpsons) delete[] simpsons; // Очищення попереднього масиву
        simpsons = new double[counter + 1]; // Динамічне збільшення розміру

        // Заповнення масивів x і y
        for (int i = 0; i <= n; ++i) {
            x[i] = a + i * h;
            y[i] = sqrt(1 + pow(x[i], 5));
        }

        // Обчислення методом Сімпсона
        Simpson(x, y, h, m, n, simpsons, counter);
        ++counter;

        // Виведення поточного значення інтегралу для відладки
        cout << "Iteration " << counter << ": Integral value = " << simpsons[counter - 1] << endl;

        // Перевірка умови точності
        if (counter >= 2 && R(simpsons, counter) < epsilon) {
            cout << "Your value of the integral is " << fixed << setprecision(6) << simpsons[counter - 1] << endl;
            delete[] x;
            delete[] y;
            delete[] simpsons;
            break;
        }

        // Перевірка на стабільність значення інтегралу
        if (counter >= 2 && fabs(simpsons[counter - 1] - prev_value) < 1e-6) {
            cout << "The integral has stabilized, stopping iterations." << endl;
            cout << "Your value of the integral is " << fixed << setprecision(6) << simpsons[counter - 1] << endl;
            delete[] x;
            delete[] y;
            delete[] simpsons;
            break;
        }

        // Оновлення попереднього значення інтегралу
        prev_value = simpsons[counter - 1];

        // Очищення пам'яті
        delete[] x;
        delete[] y;

        // Перевірка на максимальну кількість ітерацій
        if (counter > 1000) {
            cout << "Reached maximum iterations. The result may not be fully accurate." << endl;
            cout << "Your value of the integral is " << fixed << setprecision(6) << simpsons[counter - 1] << endl;
            delete[] simpsons;
            break;
        }
    }
}

void Simpson(double* x, double* y, double h, int m, int n, double* simpsons, int i) {
    double sum_odd = summ_for_odd(m, y);
    double sum_even = summ_for_even(m, y);
    simpsons[i] = (h / 3) * (y[0] + y[n] + 2 * sum_even + 4 * sum_odd);
}

double R(double* simpsons, int i) {
    return fabs(simpsons[i - 2] - simpsons[i - 1]) / 15;
}

double summ_for_even(int m, double* y) {
    double sum = 0;
    for (int i = 1; i <= m - 1; ++i) {
        sum += y[2 * i];
    }
    return sum;
}

double summ_for_odd(int m, double* y) {
    double sum = 0;
    for (int i = 0; i <= m - 1; ++i) {
        sum += y[2 * i + 1];
    }
    return sum;
}

void input(double& a, double& b, double& epsilon) {
    cout << "Enter the lower limit (a): ";
    cin >> a;
    cout << "Enter the upper limit (b): ";
    cin >> b;
    cout << "Enter the precision (epsilon): ";
    cin >> epsilon;
}

int main() {
    double epsilon = 0, a = 0, b = 0;

    input(a, b, epsilon);
    function(a, b, epsilon);

    return 0;
}
