#ifndef GENERAL_FUNCS_H
#define GENERAL_FUNCS_H

// Прототипы. Реализации лежат в general_funcs.c
void Welcome();
void delSpace(char *string);
int fromFile(int *array);
int fromUser(int *array);
int fromPC(int *array);
int (*enterMode(char *answer))(int *);
void copyArray(int src[], int dst[], int size);
void printArrays(int *array, int size, char *type);
void sortAndPrintStatistics(int *array, int size, int* (*sort)(int*, int, int*, int*), char *sort_name);

#endif