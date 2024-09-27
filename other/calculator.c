#include <stdio.h>

int main(void)
{

    double num1, num2, count;
    char operation;

    printf("This is a calculator!\n");

    printf("First number: ");
    scanf("%lf", &num1);

    printf("Second number: ");
    scanf("%lf", &num2);

    printf("Operation(+, - , *, /): ");
    scanf(" %c", &operation);
    printf("\n");

    switch (operation)
    {
    case '+':
        count = num1 + num2;
        break;
    case '-':
        count = num1 - num2;
        break;
    case '/':
        if (num2 != 0){
            count = num1 / num2;
            break;
        }
        else{
            printf("Zero division error");
            return 0;
        }
    case '*':
        count = num1 * num2;
        break;
    default:
        printf("Unknown operation!");
    }

    printf("Result is %.2lf\n", count);
    printf("The end of the programm!");
    


    return 0;
}
