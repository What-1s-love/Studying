#include <iostream>
#include <vector>
#include <algorithm> // для max

int knapsack(int W, int n, std::vector<int>& weights, std::vector<int>& values) {
    // Створення 2D вектора для зберігання dp значень
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Заповнення таблиці dp
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Повертаємо максимальну вартість, яку можна отримати
    return dp[n][W];
}

int main() {
    int n = 4; // Кількість предметів
    int W = 7; // Максимальна вага рюкзака
    std::vector<int> weights = { 1, 3, 4, 5 }; // Ваги предметів
    std::vector<int> values = { 1, 4, 5, 7 };  // Вартість предметів

    int max_value = knapsack(W, n, weights, values);
    std::cout << "Maximum value in knapsack: " << max_value << std::endl;

    return 0;
}
