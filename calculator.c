#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2;
    char cont;

    do {
        printf("\n===== CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Average\n");
        printf("9. Maximum\n");
        printf("10. Minimum\n");

        printf("\nEnter your choice (1-10): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result = %.2lf\n", num1 + num2);
        }
        else if (choice == 2) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result = %.2lf\n", num1 - num2);
        }
        else if (choice == 3) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result = %.2lf\n", num1 * num2);
        }
        else if (choice == 4) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0)
                printf("Result = %.2lf\n", num1 / num2);
            else
                printf("Cannot divide by zero!\n");
        }
        else if (choice == 5) {
            int a, b;
            printf("Enter two integers: ");
            scanf("%d %d", &a, &b);
            if (b != 0)
                printf("Result = %d\n", a % b);
            else
                printf("Cannot divide by zero!\n");
        }
        else if (choice == 6) {
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result = %.2lf\n", pow(num1, num2));
        }
        else if (choice == 7) {
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0)
                printf("Result = %.2lf\n", sqrt(num1));
            else
                printf("Invalid input!\n");
        }
        else if (choice == 8) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Average = %.2lf\n", (num1 + num2) / 2);
        }
        else if (choice == 9) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num1 > num2)
                printf("Maximum = %.2lf\n", num1);
            else
                printf("Maximum = %.2lf\n", num2);
        }
        else if (choice == 10) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num1 < num2)
                printf("Minimum = %.2lf\n", num1);
            else
                printf("Minimum = %.2lf\n", num2);
        }
        else
        {
            printf("Invalid choice!\n");
        }
        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &cont);
    } while (cont == 'Y' || cont == 'y');
    printf("\nCalculator closed.\n");
    return 0;
}