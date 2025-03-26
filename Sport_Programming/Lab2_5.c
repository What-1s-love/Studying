#include <stdio.h>

int main() {
    int number;
    
    // Read a three-digit number
    printf("Enter a three-digit number: ");
    scanf("%d", &number);
    
    // Display the number in reverse order
    printf("Reversed number: %d\n", (number % 10) * 100 + ((number / 10) % 10) * 10 + (number / 100));
    
    return 0;
}
