# Створюємо порожній масив 7x7
matrix = [[0 for _ in range(7)] for _ in range(7)]

# Заповнюємо масив за зразком
for i in range(7):
    for j in range(7 - i):
        matrix[i][j] = i + j + 1

# Виводимо масив на екран
for row in matrix:
    print(row)

