#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int max(int x, int y)
{
    return (x > y) ? x : y;
}

bool check(char *str, char array[][6], size_t size)
{
    for (int x = 0; x < 6; x++){
        if (!strcmp(array[x], str)){
            return true;
        }
    }
    return false;
}

void change(char *str, size_t size)
{
    for (int i = 0; i < size; ++i){
        if (str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }

}

void one_number(char arr[])
{
    printf("Enter number: ");

    char symb = 0;
    int i = 0;

    while (scanf("%c", &symb) == 1 && symb != '\n'){
        arr[i++] = symb - '0';
    }
}

void two_numbers(char arr1[], char arr2[])
{
    printf("Enter first number: ");
    char symb1;
    int i = 0;
    while (scanf("%c", &symb1) == 1 && symb1 != '\n'){
        arr1[i++] = symb1 - '0';
    }

    printf("Enter second number: ");
    char symb2;
    int j = 0;
    while (scanf("%c", &symb2) == 1 && symb2 != '\n'){
        arr2[j++] = symb2 - '0';
    }
}

void get_operation(char *str, size_t size)
{
    printf("Enter the operation (add; sub; mult; pow; fact; sum): ");
    fgets(str, 6, stdin);
}



int* add(int*, int*, size_t, int*);

int* sub(int*, int*, size_t, int*);

int* mult(int*, int*, size_t, int*);

int* fact(int*, int*, size_t, int*);

int* sub(int*, int*, size_t, int*);




int main(void)
{
    char arr1[2000] = {0};
    char arr2[2000] = {0};
    static int arr3[10000000] = {0};

    char operation[6];
    char allowed_operations[6][6] = {"add", "sub", "mult", "pow", "fact", "sum"};

    get_operation(operation, 6);

    change(operation, 6);
    if (!check(operation, allowed_operations, 6)){
        printf("Wrong operation!\nEnd of the programm!");
        return 0;
    }

    if (!strcmp(operation, "fact")){
        one_number(arr1);
    }
    else {
        two_numbers(arr1, arr2);
    }

    return 0;
}

