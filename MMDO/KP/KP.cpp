#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Введення ефективностей для трьох підприємств
    std::vector<std::vector<double>> g = {
        {0, 1, 2.4, 2.6, 3.4, 4.2}, // g1(x)
        {0, 2.1, 3, 4.2, 4.9, 5},   // g2(x)
        {0, 2.6, 3.5, 4, 4.7, 5.4}  // g3(x)
    };

    int budget = 5; // Загальний бюджет
    int n = 3;      // Кількість підприємств

    // Динамічна таблиця
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(budget + 1, 0));

    // Розрахунок максимального доходу
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= budget; ++j) {
            dp[i][j] = dp[i - 1][j]; // Якщо не вкладати в i-те підприємство
            for (int x = 0; x <= j; ++x) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - x] + g[i - 1][x]);
            }
        }
    }

    // Виведення результату
    std::cout << "Maximum profit: " << dp[n][budget] << std::endl;

    // Відновлення розподілу
    int remaining_budget = budget;
    std::vector<int> allocation(n, 0);
    for (int i = n; i > 0; --i) {
        for (int x = 0; x <= remaining_budget; ++x) {
            if (remaining_budget >= x && dp[i][remaining_budget] == dp[i - 1][remaining_budget - x] + g[i - 1][x]) {
                allocation[i - 1] = x;
                remaining_budget -= x;
                break;
            }
        }
    }

    // Виведення розподілу
    std::cout << "Optimal allocation:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enterprise " << i + 1 << ": " << allocation[i] << " million" << std::endl;
    }

    return 0;
}
