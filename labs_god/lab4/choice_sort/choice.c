#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "choice_funcs.h" 

int main(void)
{
    srand(time(NULL));

    int array[10];
    int size = sizeof(array) / sizeof(array[0]);

    int num;
    for (int i = 0; i < size; ++i){
        num = (rand() % 200) - 100;
        array[i] = num;
    }

    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }

    int compares = 0;
    int swaps = 0;

    choiceSort(array, size, &compares, &swaps);
    puts("");

    for (int k = 0; k < size; ++k){
        printf("%d ", array[k]);
    }

    return 0;
}