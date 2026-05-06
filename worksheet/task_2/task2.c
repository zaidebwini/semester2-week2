#include <stdio.h>
#include <string.h>

int main(void) {

    char hex[9]; // max 8 chars + null terminator
    long decimal = 0;

    scanf("%8s", hex);

    for (int i = 0; i < strlen(hex); i++) {
        decimal *= 16;

        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += hex[i] - 'a' + 10;
        }
        else {
            printf("Error: Invalid Hexadecimal\n");
            return 0;
        }
    }

    printf("%ld\n", decimal);

    return 0;
}