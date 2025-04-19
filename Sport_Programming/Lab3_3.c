#include <stdio.h>

int main() {
    int totalSeconds;
    printf("Enter total seconds: ");
    scanf("%d", &totalSeconds);

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    printf("Time: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    return 0;
}
