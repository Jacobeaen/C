#include <stdio.h>

void insertionSort(int array[], int size, int gap){
    for (int i = gap; i < size; ++i)
    {
        int tmp = array[i];
        int j = i - gap;

        while (tmp < array[j] && j >= 0){
            array[j + gap] = array[j];
            j -= gap;
        }

        array[j + gap] = tmp;
    }
}

int main(void)
{
    int array[] = {56, 43, 12, 78, 42, 93, 16, 55};
    int size = sizeof(array) / sizeof(array[0]);

    for (int gap = size / 2; gap > 0; gap /= 2){
        

    }


    return 0;
}