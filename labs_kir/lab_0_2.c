#include <stdio.h>

/*
Условие: на вход подается целое число.
Будем считать его счастливым, если выполнено 2 условия:
1) Количество цифр в числе четно
2) Сумма цифр правой половины числа равна сумме цифр левой половины
Если число счастливое вывести 1, в противном случае вывести 0.
*/
enum {
    unlucky,
    lucky
};

int main(void){
    int half, last;
    int digit_count = 0, left_count = 0, right_count = 0;
    long long number, copy_num_1, copy_num_2;

    scanf("%lld", &number);
    if (number < 0)
        number = -number;
    if (number == 0){
        printf("%d", unlucky);
        return 0;
    }

    copy_num_1 = number;
    copy_num_2 = number;

    while (copy_num_1 > 0){
        copy_num_1 /= 10;
        digit_count += 1;
    }

    if (digit_count % 2){
        printf("%d", unlucky);
        return 0;
    }

    half = digit_count / 2;

    for (int i = 0; i < digit_count; i++){
        last = copy_num_2 % 10;
        if (i < half){
            right_count += last;}
        else{
            left_count += last;}
        
        copy_num_2 /= 10;
    }

    if (left_count == right_count)
        printf("%d", lucky);
    else
        printf("%d", unlucky);

    return 0;
}