#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2;

    printf("Enter coordinates of point A (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter coordinates of point B (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    float distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    printf("Distance between points: %.2f\n", distance);

    return 0;
}
