#include <stdio.h>

#include "shell_funcs.h"
#include "../general_functions/general_funcs.h" 

int main(void)
{
    int array[] = {56, 43, 12, 78, 42, 93, 16, 55};
    int size = sizeof(array) / sizeof(array[0]);

    int comperes = 0;
    int swaps = 0;


    printArrays(array, size, "Source");
    printf("\n");

    shellSort(array, size, &comperes, &swaps);
    
    puts("Shell sort:");
    printf("Compares: %d\n", comperes);
    printf("Swaps: %d\n", swaps);
    printArrays(array, size, "Sorted");

    return 0;
}