#include <stdio.h>

int main() {
    float distance1 = 120, time1 = 2, distance2 = 80, time2 = 1;
    float average_speed;
    
    // Calculate the average speed
    average_speed = (distance1 + distance2) / (time1 + time2);
    
    // Display the average speed
    printf("Average speed: %.2f km/h\n", average_speed);
    
    return 0;
}
