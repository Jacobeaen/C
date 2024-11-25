#ifndef CHOICE_FUNCS_H
#define CHOICE_FUNCS_H

// Прототипы. Реализации лежат в сhoice_funcs.c
int findMin(int array[], int size, int start, long long *compares);
void Swap(int array[], int i, int j);
int* choiceSort(int array[], int size, long long *compares, long long *swaps);

#endif