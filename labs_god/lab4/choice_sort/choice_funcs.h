#ifndef CHOICE_FUNCS_H
#define CHOICE_FUNCS_H

// Прототипы. Реализации лежат в choice_funcs.c
int findMin(int array[], int size, int start, int *compares);
void Swap(int array[], int i, int j);
int* choiceSort(int array[], int size, int *compares, int *swaps);

#endif