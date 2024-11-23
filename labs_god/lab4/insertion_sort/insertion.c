#include <stdio.h>
#include <stdlib.h>

void Swap(int array[], int i, int right){
    int tmp = array[i];

    array[i] = array[right];
    array[right] = tmp;
}
int* insertionSort(int array[], int size){
    for (int i = 1; i < size; ++i){
        int tmp = array[i];
        int j = i - 1;

        while (tmp < array[j] && j >= 0){
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = tmp;
    }

    return array;
}

int main(void)
{
    int array[] = {100, 7, 3, -6, 0, 33, -5, 3, -99};
    int size = sizeof(array) / sizeof(array[0]);

    int *array2;
    array2 = insertionSort(array, size);

    for (int i = 0; i < size; i++){
        printf("%d ", array2[i]);
    }

    return 0;
}