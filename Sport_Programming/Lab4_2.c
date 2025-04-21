#include <stdio.h>

int main() {
    int birthYear, currentYear;
    printf("Enter your year of birth: ");
    scanf("%d", &birthYear);

    currentYear = 2025; // або використовуй time.h для динамічного року
    int age = currentYear - birthYear;

    printf("Your age: %d\n", age);
    return 0;
}
