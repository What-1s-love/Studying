#include <iostream>
#include <vector>

double calculateNewtonInterpolation(std::vector<double> x, std::vector<double> y, double point) {
    int n = x.size();

    // Створюємо таблицю різницевих різниць
    std::vector<std::vector<double>> f(n, std::vector<double>(n, 0.0));

    // Заповнюємо перший стовпець таблиці значеннями функції у вузлах
    for (int i = 0; i < n; ++i) {
        f[i][0] = y[i];
    }

    // Заповнюємо решту таблиці
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Обчислюємо значення поліному в точці point за формулою Ньютона
    double result = f[0][0];
    double term = 1.0;

    for (int i = 1; i < n; ++i) {
        term *= (point - x[i - 1]);
        result += f[0][i] * term;
    }

    return result;
}

int main() {
    int n;

    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::vector<double> x(n), y(n);

    std::cout << "Enter the values of nodes (x):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "x[" << i << "] = ";
        std::cin >> x[i];
    }

    std::cout << "Enter the values of the function at the nodes (y):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "y[" << i << "] = ";
        std::cin >> y[i];
    }

    double point;
    std::cout << "Enter the point where you want to evaluate the interpolation: ";
    std::cin >> point;

    // Викликаємо функцію для обчислення значення в точці
    double result = calculateNewtonInterpolation(x, y, point);

    std::cout << "Result at point " << point << " : " << result << std::endl;

    return 0;
}
