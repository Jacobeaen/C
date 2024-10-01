#include <stdio.h>


int main(void)
{

    int amount, count = 1;
    scanf("%d", &amount);

    int number, max_len = 0;
    int last_num = -1;
    int flag = 1;
    for (int i = 0; i < amount; i++){
        scanf("%d", &number);
        
        if (i == 0){
            last_num = number;
            continue;
        }

        if (number > last_num){
            count++;
            flag = 1;
        } else {
            max_len = (max_len < count) ? count : max_len;
            count = 1;
            flag = 0;
        }

        last_num = number;
    }

    if (flag && max_len < count)
        max_len = count;

    printf("%d", max_len);

    return 0;
}