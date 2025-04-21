#include <stdio.h>

int main() {
    float price, discount;

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    float finalPrice = price * (1 - discount / 100);
    printf("Final price: %.2f\n", finalPrice);

    return 0;
}
