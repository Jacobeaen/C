#include <stdio.h>

/*
Условие: На вход подается строка вида _._ _ _+_._ _ _
_ - цифра, + - знак сложения. Вывести результат сложения
Нельзя использовать вещественные типы данных
ввод: 2.9900+001.92
вывод: 4.91

ввод: 9.3819+909.99
вывод: 919.3719

ввод: 0.0000+009.01
вывод: 9.01

ввод: 7.1999+902.90
вывод: 910.0999
*/

void FillIntArray(int array[], char *string, int *position, int *counter, char stop)
{
    int is_zero = 1;
    for (int i = 0; string[*position] != stop; (*position)++){
        if (is_zero){
            if (string[*position] != '0'){
                is_zero = 0;
                array[i++] = string[*position] - '0';
                (*counter)++;
            }
        }
        else {
            array[i++] = string[*position] - '0';
            (*counter)++;
        }
    }

    (*position)++;
}

void FillFloatArray(int array[], char *string, int *position, int *counter, char stop)
{
    for (int i = 0; string[*position] != stop && string[*position] != '\0'; (*position)++){
        array[i++] = string[*position] - '0';
        (*counter)++;
    }

    for (int i = (*counter) - 1; i >= 0; i--){
        if (array[i] != 0){
            *counter = i + 1;
            break;
        }
    }

   (*position)++;
}

void ShiftIntArray(int array[], int shift, int size)
{
    for (int i = size - 1; i >= 0; i--){
        array[i + shift] = array[i];
        array[i] = 0;
    }
}

int ShiftLength(int x, int y){
    int result = x - y;
    
    return (result >= 0) ? result : -result;
}

int max(int x, int y){
    return (x > y) ? x : y;
}


int main(void)
{
    char string[100];

    int number1_int[100] = {0}, number1_float[100] = {0};
    int number2_int[100] = {0}, number2_float[100] = {0};
    int number3_int[100] = {0}, number3_float[100] = {0};

    fgets(string, 100, stdin);

    int i = 0;
    int int_1 = 0, int_2 = 0;
    int float_1 = 0, float_2 = 0;

    FillIntArray(number1_int, string, &i, &int_1, '.');
    FillFloatArray(number1_float, string, &i, &float_1, '+');
    FillIntArray(number2_int, string, &i, &int_2, '.');
    FillFloatArray(number2_float, string, &i, &float_2, '\n');


    // Сдвигаем меньший из массивов, для поразрядного сложения цифр
    int shift = ShiftLength(int_1, int_2);
    if (shift != 0){
        if (int_1 > int_2)
            ShiftIntArray(number2_int, shift, int_2);
        else
            ShiftIntArray(number1_int, shift, int_1);
    }

    // Дробная часть
    int longest_float = max(float_1, float_2);
    int stop_f = longest_float;
    int overflow_f = 0;
    int only_zeros_f = 1;


    // Поразрядное сложение, only_zeros_f - первый незначащий ноль
    for (int i = longest_float - 1; i >= 0; i--){

        int sum_dig = number1_float[i] + number2_float[i] + overflow_f;
        overflow_f = sum_dig / 10;

        int digit = sum_dig % 10;
        if (digit == 0 && only_zeros_f){
            stop_f = i;
        }
        else{
            only_zeros_f = 0;
        }

        number3_float[i] = digit; 
    }

    // Целая часть
    int longest_int = max(int_1, int_2);
    int overflow_i = 0;
    int only_zeros_i = 1;

    // only_zeros_i - Если все нули в целой части
    // Оставляем 0-ой элемент массива под переполнение
    for (int i = longest_int - 1; i >= 0; i--, overflow_f = 0){

        int sum_dig = number1_int[i] + number2_int[i] + overflow_f + overflow_i;
        overflow_i = sum_dig / 10;

        int digit = sum_dig % 10;
        
        if (digit != 0){
            only_zeros_i = 0;
        }

        number3_int[i + 1] = digit; 
    }

    // Если переполнение - заполняем 0-ой элемент массива
    int start = 1;
    if (overflow_i > 0){
        start = 0;
        number3_int[0] = overflow_i;
        only_zeros_i = 0;
    }

    // Если нули целая и дробная части - 0
    if (only_zeros_i && only_zeros_f){
        printf("0");
        return 0;
    }

    // Если нули только в целой части (цикл не выполнится)
    if (only_zeros_i && !only_zeros_f)
        printf("0");

    // Вывод целой части
    for (int i = start; i < longest_int + 1; i++){
        printf("%d", number3_int[i]);
    }

    // Если в дробной части одни нули
    if (only_zeros_f)
        return 0;
    printf(".");
    

    // Вывод дробной части
    for (int i = 0; i < stop_f; i++){
        printf("%d", number3_float[i]);
    }
    
    return 0;
}