#include <stdio.h>

int main() {
    int number, tens, ones;
    
    // Зчитуємо двоцифрове число
    printf("Введіть двоцифрове число: ");
    scanf("%d", &number);
    
    // Отримуємо десятки і одиниці
    tens = number / 10;
    ones = number % 10;
    
    // Виводимо цифри окремо
    printf("Десятки: %d, Одиниці: %d\n", tens, ones);
    
    return 0;
}
