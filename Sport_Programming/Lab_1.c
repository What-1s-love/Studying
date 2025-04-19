#include <stdio.h>

int main() {
    // Завдання 1: Поділити 5 на 2 і вивести як float
    int a = 5, b = 2;
    float result = (float)a / b;
    printf("Result of 5 / 2 as float: %.2f\n", result);

    // Завдання 2: Оголосити константну змінну float і вивести її
    const float PI = 3.14;
    printf("Constant float value: %.2f\n", PI);

    // Завдання 3: Оголосити змінну char і вивести її ASCII-код
    char ch = 'A';
    printf("Character: %c, ASCII Code: %d\n", ch, ch);

    // Завдання 4: Користувач вводить ціле і дробове число, вивести їх суму
    int intNum;
    float floatNum;
    printf("Enter an integer and a float: ");
    scanf("%d %f", &intNum, &floatNum);
    printf("Sum: %.2f\n", intNum + floatNum);

    // Завдання 5: Зчитати символ і вивести наступний у таблиці ASCII
    char inputChar;
    printf("Enter a character: ");
    scanf(" %c", &inputChar);
    printf("Next character in ASCII: %c\n", inputChar + 1);

    return 0;
}
