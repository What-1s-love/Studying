#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch); // пробіл перед %c, щоб зчитати навіть після інших scanf

    if (ch >= '0' && ch <= '9') {
        int value = ch - '0'; // перетворення символу в число
        printf("Digit with value: %d\n", value);
    } else if (ch >= 'a' && ch <= 'z') {
        printf("Lowercase letter\n");
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("Uppercase letter\n");
    } else {
        printf("Other symbol\n");
    }

    return 0;
}
