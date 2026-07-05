#include <iostream>

// Sum routine (function) to add two numbers
int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    // Get input from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Call the sum routine and store the result
    int result = sum(num1, num2);

    // Display the sum
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}
