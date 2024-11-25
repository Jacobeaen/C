#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "general_functions/general_funcs.h"

#include "merge_sort/merge_funcs.h"
#include "choice_sort/choice_funcs.h"
#include "shell_sort/shell_funcs.h"

#define MAX_SIZE    1000000

int main(void){
    srand(time(NULL));

    int *array_choice = malloc(sizeof(int) * MAX_SIZE);
    int *array_merge = malloc(sizeof(int) * MAX_SIZE);
    int *array_shell = malloc(sizeof(int) * MAX_SIZE);

    Welcome();

    char answer[10];
    fgets(answer, 10, stdin);

    int (*Fill)(int *) = enterMode(answer);

    if (Fill == NULL)
        return 0;

    int size = Fill(array_choice);
    if (size == -1)
        return 0;

    copyArray(array_choice, array_merge, size);
    copyArray(array_choice, array_shell, size);

    //printArrays(array_choice, size, "Source");
    //printf("\n");

    sortAndPrintStatistics(array_merge, size, mergeSort, "Merge sort");
    sortAndPrintStatistics(array_shell, size, shellSort, "Shell sort");
    sortAndPrintStatistics(array_choice, size, choiceSort, "Choice sort");

    free(array_choice);
    free(array_merge);
    free(array_shell);

    return 0;
}