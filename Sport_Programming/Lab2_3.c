#include <stdio.h>

int main() {
    int number;
    
    // Read an integer number
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    // Display the last digit of the number
    printf("Last digit of the number: %d\n", number % 10);
    
    return 0;
}


