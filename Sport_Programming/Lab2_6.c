#include <stdio.h>

int main() {
    int number, tens, ones;
    
    // Read a two-digit number
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    
    // Extract tens and ones digits
    tens = number / 10;
    ones = number % 10;
    
    // Display the digits
    printf("Tens: %d, Ones: %d\n", tens, ones);
    
    return 0;
}
