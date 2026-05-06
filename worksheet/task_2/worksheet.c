#include "acutest.h"

/* FUNCTION IMPLEMENTATIONS */

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
    int sum = sum_array(arr, n);
    return (double)sum / n;
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

/* ================= TESTS ================= */

void test_add_values(void) {
    TEST_CHECK(add_values(3, 4) == 7);
    TEST_CHECK(add_values(0, 0) == 0);
    TEST_CHECK(add_values(-5, 5) == 0);
    TEST_CHECK(add_values(-3, -7) == -10);
}

void test_swap_values(void) {
    int a = 5, b = 10;
    swap_values(&a, &b);
    TEST_CHECK(a == 10 && b == 5);
}

void test_sum_array(void) {
    int arr[] = {1,2,3,4,5};
    TEST_CHECK(sum_array(arr, 5) == 15);
}

void test_reverse_array(void) {
    int arr[] = {1,2,3};
    reverse_array(arr, 3);
    TEST_CHECK(arr[0] == 3 && arr[1] == 2 && arr[2] == 1);
}

void test_average(void) {
    int arr[] = {1,2};
    double avg = average(arr, 2);
    TEST_CHECK(avg > 1.49 && avg < 1.51);
}

void test_find_max(void) {
    int arr[] = {3,7,2,9,4};
    int idx;
    int max = find_max(arr, 5, &idx);
    TEST_CHECK(max == 9 && idx == 3);
}

/* TEST LIST */

TEST_LIST = {
    {"add_values", test_add_values},
    {"swap_values", test_swap_values},
    {"sum_array", test_sum_array},
    {"reverse_array", test_reverse_array},
    {"average", test_average},
    {"find_max", test_find_max},
    {NULL, NULL}
};