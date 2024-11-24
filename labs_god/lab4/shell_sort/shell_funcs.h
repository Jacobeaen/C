#ifndef SHELL_FUNCS_H
#define SHELL_FUNCS_H

// Прототипы. Реализация находится в shell_funcs.c
void insertionSort(int array[], int size, int gap, int *compares, int *swaps);
int *shellSort(int array[], int size, int *compares, int *swaps);

#endif