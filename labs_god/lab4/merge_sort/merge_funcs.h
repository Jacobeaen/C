#ifndef MERGE_FUNCS_H
#define MERGE_FUNCS_H

// Прототипы. Реализации находятся в merge_funcs.c
void copyNumbers(int[], int[], int, int);
int *mergeArrays(int array1[], int size1, int array2[], int size2, int *compares, int *swaps);
int *mergeSort(int[], int, int *compares, int *swaps);

#endif