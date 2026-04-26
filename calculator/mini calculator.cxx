#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;

    printf("Enter first number, operator (+, -, *, /), and second number: ");
    // Note: the space before %c is important to skip any leftover "Enter" keys
    scanf("%f %c %f", &num1, &op, &num2);

    if (op == '+') {
        result = num1 + num2;
        printf("Result: %.2f\n", result);
    } 
    else if (op == '-') {
        result = num1 - num2;
        printf("Result: %.2f\n", result);
    }
    else if (op == '*') {
        result = num1 * num2;
        printf("Result: %.2f\n", result);
    }
    else if (op == '/') {
        // Handle the Edge Case: Division by zero
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed!\n");
        } else {
            result = num1 / num2;
            printf("Result: %.2f\n", result);
        }
    }
    else {
        printf("Invalid operator!\n");
    }

    return 0;
}
