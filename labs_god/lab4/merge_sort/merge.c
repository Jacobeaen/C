#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../general_functions/general_funcs.h"
#include "merge_funcs.h"

int main(void){
    int compares = 0;
    int swaps = 0;

    srand(time(NULL));

    int *array = malloc(sizeof(int) * 1000000);

    Welcome();

    char answer[100];
    fgets(answer, 100, stdin);

    // Возвращается fromFile или fromUser в зависимости от ввода
    int (*Fill)(int *) = enterMode(answer);

    if (Fill == NULL)
        return 0;

    int size = Fill(array);

    if (size == -1)
        return 0;

    printArrays(array, size, "Source");
    printf("\n");

    // clock() - количество тиков процессора. Такой способ более предпочтителен,
    // тк исключает такие факторы, как производительность системы
    clock_t start = clock();
    array = mergeSort(array, size, &compares, &swaps);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printArrays(array, size, "Sorted");
    printf("\nTime: %lf", seconds);
    printf("\nCompares: %d", compares);
    printf("\nSwaps: %d", swaps);

    free(array);

    return 0;
}