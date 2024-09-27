#include <stdio.h>

int main(void){
    int x, y, max, step;
    int i = 10;
    int flag = 1;

    scanf("%d %d", &x, &y);
    if (x > y)
        max = x;
    else
        max = y;
    max *= 3;
 
    if (max > i)
        step = 1;
    else
        step = -1;
    
    while (flag){
        if (i == max){
            printf("%d", i);
            return 0;
        }

        printf("%d ", i);
        i += step;
    }


    return 0;
}