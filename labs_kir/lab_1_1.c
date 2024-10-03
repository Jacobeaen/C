#include <stdio.h>

/*
Условие: Вывести все значения переменной типа int кроме нуля,
которые делятся на 71585 через запятую в порядке убывания.
*/
int main(void){

    int start = 0;
    int end;

    do {
        start = (start * 2) + 1; 
        start += 1;
        if (start < 0)
            break;
        start -= 1;

    } while (start > 0);
    
    end = start;
    start -= 1;
    

    while (start >= end){
        if (start == 0){
            start -= 71585;
            continue;
        }
        if (start % 71585 == 0){ 
            printf("%d", start);
            
            if (start < 0){
                start -= 71585;

                if (start > 0){
                    return 0;
                }
                printf(",");
                continue;
            }

            printf(",");
            start -= 71585;
            continue;
        
        }
    start -= 1;
        
    }

    return 0;
}
