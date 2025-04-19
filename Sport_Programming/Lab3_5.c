#include <stdio.h>

int main() {
    char lower;
    printf("Enter a lowercase letter: ");
    scanf(" %c", &lower); // пробіл перед %c, щоб зчитати символ після попереднього вводу

    if (lower >= 'a' && lower <= 'z') {
        char upper = lower - ('a' - 'A');
        printf("Uppercase: %c\n", upper);
    } else {
        printf("That is not a lowercase letter.\n");
    }

    return 0;
}
