#include <stdio.h>

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    // A year is a leap year if it is divisible by 4,
    // except for end-of-century years which must be divisible by 400.
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
