#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
 
    srand(time(NULL)); // Seed the random generator
    printf("Generate two numbers between 1-6 with total cannot be 7\n");

    int num1, num2;

    do {
        num1 = (rand() % 6) + 1; // 1–6
        num2 = (rand() % 6) + 1; // 1–6
    } while (num1 + num2 == 7);

    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    printf("Sum: %d\n", num1 + num2);

    return 0;
}