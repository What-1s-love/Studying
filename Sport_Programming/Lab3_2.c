#include <stdio.h>
#define PI 3.14159

int main() {
    float radius;
    printf("Enter radius: ");
    scanf("%f", &radius);

    float area = PI * radius * radius;
    printf("Circle area: %.2f\n", area);

    return 0;
}