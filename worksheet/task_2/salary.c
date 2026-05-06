#include <stdio.h>

int main(void) {

    // given values
    double salary = 36250.0;
    double ni_rate = 8.0;
    double tax_rate = 15.0;

    // calculations
    double ni = salary * ni_rate;

    double taxable_income = salary - ni - 12500;
    if (taxable_income < 0) {
        taxable_income = 0;
    }

    double tax = taxable_income * tax_rate;

    double take_home = salary - ni - tax;

    // output (use exactly this format)
    printf("Salary £%.2f\n", salary);
    printf("NI contribution £%.2f\n", ni);
    printf("Tax contribution £%.2f\n", tax);
    printf("Take home salary £%.2f\n", take_home);

    return 0;
}