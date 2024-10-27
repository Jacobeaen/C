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

int max(int x, int y){
    return (x > y) ? x : y;
}

int main(void)
{
    char string[100];
    
    int number1_int[100] = {0}, number1_float[100] = {0};
    int number2_int[100] = {0}, number2_float[100] = {0};
    int number3_int[100] = {0}, number3_float[100] = {0};

    fgets(string, 51, stdin);

    int plus = 0;
    int dot_1 = 0, dot_2 = 0;

    int num1_zero_int = 0;
    int num2_zero_int = 0;

    int int1_i = 0, float1_i = 0;
    int float2_i = 0;
    int int2_i = 0;
    int i = 0;
    while (string[i] != '\n' && string[i] != '\0'){
        if (string[i] == '.' && !dot_1){
            dot_1 = i++;
            continue;
        }

        if (string[i] == '+'){
            plus = i++;
            continue;
        }

       if (string[i] == '.' && dot_1){
            dot_2 = i++;
            continue;
        }

        if (dot_1){
            if (plus){
                if (dot_2)
                    number2_float[float2_i++] = (string[i] - 48);
                else{
                    if (num2_zero_int)
                        number2_int[int2_i++] = (string[i] - 48);
                    else if (string[i] != '0' && !num2_zero_int){
                        num2_zero_int = 1;
                        number2_int[int2_i++] = (string[i] - 48);
                    }
                }
            }
            else            
                number1_float[float1_i++] = (string[i] - 48);

        
        }
        else{
            if (num1_zero_int){
                number1_int[int1_i++] = (string[i] - 48);
            }
            else if (string[i] != '0' && !num1_zero_int){
                num1_zero_int = 1;
                number1_int[int1_i++] = (string[i] - 48);
            }
        }
    i++;
    }

    int max_float = max(float1_i, float2_i);
    int overflow_float = 0, num3_fl_dig = 0;
    int sum_dig = 0;

    // printf("%d\n", max_float);
    for (int index = max_float - 1; index >= 0; index--){

        // printf("%d - %d - %d\n", number1_float[index], number2_float[index], overflow_float);
        sum_dig = number1_float[index] + number2_float[index] + overflow_float;
        num3_fl_dig = sum_dig % 10;
        overflow_float = sum_dig / 10; 

        number3_float[index] = num3_fl_dig;   
        // printf("%d\n", num3_fl_dig);
        // printf("%d\n", number3_float[index]);
        
    }

    int extra_1 = 0, extra_2 = 0;
    int flag1 = 0, flag2 = 0;


    int max_int = max(int1_i, int2_i);
    
    if (int1_i == int2_i)
        {}
    else if (max_int == int1_i){
        extra_2 = int1_i - int2_i;
        flag2 = 1;
    }
    else {
        extra_1 = int2_i - int1_i;
        flag1 = 1; 
    }

    int num3_in_dig = 0, overflow_int = 0, overflow_float_to_int = 0;
    int end = 49;
    for (int index = max_int - 1; index >= 0; index--, overflow_float_to_int = 0){
        if (index == max_int - 1){
            if (overflow_float)
                overflow_float_to_int++;
        }

        if (index < extra_1) extra_1 = 0;
        if (index < extra_2) extra_2 = 0;

        sum_dig = number1_int[index - extra_1] + number2_int[index - extra_2] + overflow_int + overflow_float_to_int;
        
        if (extra_1) number1_int[index - extra_1] = 0;
        if (extra_2) number2_int[index - extra_2] = 0;

        num3_in_dig = sum_dig % 10;
        overflow_int = sum_dig / 10;

        number3_int[end--] = num3_in_dig;
    }
    if (overflow_int){
        number3_int[end] = overflow_int;
        end--;
    }


    if (number3_int[end + 1] == 0 && number3_float[0] == 0){
        printf("%d", 0);
        return 0;
    }


    int zero = 1;
    for (int p = end + 1; p < 50; p++){
        printf("%d", number3_int[p]);
        zero = 0;
    } 
    


    int zero_index = 0, first_dig = 0;
    for (int j = max_float - 1; j >= 0; j--)
        if (number3_float[j] != 0 && !first_dig){
            zero_index = j;
            break;
        }

    if (zero_index == 0 && number3_float[zero_index] == 0)
        return 0;
    
    if (zero)
        printf("%d", 0);
    printf(".");
    
    for (int k = 0; k <= zero_index; k++)
        printf("%d", number3_float[k]);


    return 0;

}
