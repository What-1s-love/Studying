#include <stdio.h>

int main() {
    char str[100];
    int len = 0;

    printf("Enter a string (max 99 characters): ");
    fgets(str, 100, stdin);  // безпечне зчитування рядка

    // Обчислюємо довжину вручну (не використовуємо strlen)
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }

    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
