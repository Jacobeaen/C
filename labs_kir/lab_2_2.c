#include <stdio.h>

/*
Условие: На вход подается строка вида _._ _ _+_._ _ _
_ - цифра, + - знак сложения. Вывести результат сложения
Нельзя использовать вещественные типы данных
ввод: 2.9900+001.92
вывод: 4.91
*/

int max(int x, int y){
    return (x > y) ? x : y;
}


int main(void)
{
    char string[1000];
    
    int number1_int[100] = {0}, number1_float[100] = {0};
    int number2_int[100] = {0}, number2_float[100] = {0};
    int number3_int[100] = {0}, number3_float[100] = {0};

    fgets(string, 100, stdin);

    int plus = 0;
    int dot_1 = 0, dot_2 = 0;

    int num1_zero_int = 0;
    int num2_zero_int = 0;

    int int2_i = 0;
    int float2_i = 0;
    int int1_i = 0;
    int float1_i = 0;
    int i = 0;
    while (string[i] != '\n'){
        if (string[i] == '.' && !dot_1){
            dot_1 = i;
            i++;
            continue;
        }

        
        if (string[i] == '+'){
            plus = i;
            i++;
            continue;
        }

        if (string[i] == '.' && dot_1){
            dot_2 = i;
            i++;
            continue;
        }


        if (dot_1){
            if (plus){
                if (dot_2)
                    number2_float[float2_i++] = string[i] - 48;
                else{
                    if (num2_zero_int){
                        number2_int[int2_i++] = string[i] - 48;
                    }
                    else if (string[i] != '0' && !num2_zero_int){
                        num2_zero_int = 1;
                        number2_int[int2_i++] = string[i] - 48;
                    }
                }
            }
            else            
                number1_float[float1_i++] = string[i] - 48;

        
        }
        else{
            if (num1_zero_int){
                number1_int[int1_i++] = string[i] - 48;
            }
            else if (string[i] != '0' && !num1_zero_int){
                num1_zero_int = 1;
                number1_int[int1_i++] = string[i] - 48;
            }
        }

    i++;
    }




    int max_float = max(float1_i, float2_i);
    int overflow_float = 0, num3_fl_dig;
    for (int index = max_float - 1; index >= 0; index--){
        num3_fl_dig = (number1_float[index] + number2_float[index] + overflow_float) % 10;
        overflow_float = (number1_float[index] + number2_float[index] + overflow_float) / 10; 

        number3_float[index] = num3_fl_dig;   
    }





    int extra_1 = 0, extra_2 = 0;
    int flag1 = 0, flag2 = 0;

    printf("int1: %d int2: %d\n\n", int1_i, int2_i);

    int max_int = max(int1_i, int2_i);
    if (max_int == int1_i){
        extra_2 = int1_i - int2_i;
        flag2 = 1;
    }
    else {
        extra_1 = int2_i - int1_i;
        flag1 = 1; 
    }

    int num3_in_dig, overflow_int = 0, sum_dig = 0, overflow_float_to_int = 0;
    printf("max int: %d\n", max_int);
    for (int index = max_int - 1; index >= 0; index--, overflow_float_to_int = 0){
        if (index == max_int - 1){
            if (overflow_float)
                overflow_float_to_int++;
        }


        sum_dig = number1_int[index - extra_1 + flag1] + number2_int[index - extra_2 + flag2] + overflow_int + overflow_float_to_int;
        
        num3_in_dig = sum_dig % 10;
        overflow_int = sum_dig / 10;
        printf("1:%d 2:%d o:%d i: %d\n", number1_int[index - extra_1 + flag1], number2_int[index - extra_2 + flag2], overflow_int, index);
        printf("dig: %d sum: %d, over: %d\n\n", num3_in_dig, sum_dig, overflow_int);

        number3_int[index] = num3_in_dig;
    }

    for (int i = 0; i < max_int; i++){}
        //printf("%d", number3_int[i]);
    //printf(".");


    int zero_index = 0, first_dig = 0;
    for (int j = max_float - 1; j >= 0; j--)
        if (number3_float[j] != 0 && !first_dig){
            zero_index = j;
            break;
        }


    for (int k = 0; k <= zero_index; k++)
        //printf("%d", number3_float[k]);
    return 0;

}
