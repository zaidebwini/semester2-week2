#include "acutest.h"

int add_values(int a, int b) {
    return a + b;
}

void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

double average(int *arr, int n) {
    return (double)sum_array(arr, n) / n;
}

int find_max(int *arr, int n, int *index) {
    int max = arr[0];
    *index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            *index = i;
        }
    }

    return max;
}