#include <stdio.h>

int main() {
    float price = 450.0;
    float discount = 15.0;

    float discountedPrice = price * (1 - discount / 100);
    int finalPrice = (int)discountedPrice;

    printf("Price with discount: %d UAH\n", finalPrice);
    return 0;
}