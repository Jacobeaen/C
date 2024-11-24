#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Слияние двух упорадоченных массивов в один отсортированный
int* mergeArrays(int array1[], int size1, int array2[], int size2, int *compares, int *swaps)
{
    int *array = malloc(sizeof(int) * (size1 + size2));

    int i = 0;
    int j = 0;
    int k = 0;

    while (true)
    {
        if (i == size1 && j == size2)
            break;

        else if (i == size1)
            array[k] = array2[j++];

        else if (j == size2)
            array[k] = array1[i++];

        else if (array1[i] < array2[j]){
            array[k] = array1[i++];
            (*compares)++;
        }
        else{
            array[k] = array2[j++];
            (*compares)++;
        }

        k++;
    }

    return array;
}

// Копирование чисел из осного массива в левую/правую часть
void copyNumbers(int src_array[], int dst_array[], int start, int stop)
{
    int j = 0;
    for (int i = start; i < stop; i++)
    {
        dst_array[j++] = src_array[i];
    }
}

// Сортировка слиянием
int* mergeSort(int array[], int size, int *compares, int *swaps)
{
    size_t left_size = size / 2;
    size_t right_size = size - left_size;

    int *array_left = malloc(sizeof(int) * left_size);
    int *array_right = malloc(sizeof(int) * (right_size));

    copyNumbers(array, array_left, 0, left_size);
    copyNumbers(array, array_right, left_size, size);

    if (left_size > 1)
        array_left = mergeSort(array_left, left_size, compares, swaps);
    if (right_size > 1)
        array_right = mergeSort(array_right, right_size, compares, swaps);

    array = mergeArrays(array_left, left_size, array_right, right_size, compares, swaps);

    free(array_left);
    free(array_right);

    return array;
}