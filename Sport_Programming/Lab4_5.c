#include <stdio.h>

int main() {
    int number;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    int sum = (number / 100) + ((number / 10) % 10) + (number % 10);
    printf("Sum of digits: %d\n", sum);

    return 0;
}
