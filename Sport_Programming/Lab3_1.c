#include <stdio.h>

int main() {
    float meters;
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    float centimeters = meters * 100;
    float millimeters = meters * 1000;

    printf("Length: %.2f cm\n", centimeters);
    printf("Length: %.2f mm\n", millimeters);

    return 0;
}
