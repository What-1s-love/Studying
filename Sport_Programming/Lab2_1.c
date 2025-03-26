#include <stdio.h>

int main() {
    int a, b;
    
    // Read two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    // Swap the numbers without using a third variable
    a = a + b;
    b = a - b;
    a = a - b;
    
    // Display the swapped values
    printf("After swapping: a = %d, b = %d\n", a, b);
    
    return 0;
}
