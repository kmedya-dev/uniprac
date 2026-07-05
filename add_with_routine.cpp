#include <stdio.h>

// Sum routine (function) to add two numbers
int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    // Get input from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Call the sum routine and store the result
    int result = sum(num1, num2);

    // Display the sum
    printf("The sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
