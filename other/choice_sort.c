#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    int num;
    for (int i = 0; i < 10; ++i){
        num = (rand() % 200) - 100;
        arr[i] = num;
    }

    int min, min_index;
    int tmp;
    for (int i = 0; i < size - 1; ++i){
        min = arr[i];
        min_index = i;

        for (int j = i + 1; j < size; ++j){
            if (arr[j] < min){
                min_index = j;
                min = arr[min_index];
            }

        }
        tmp = min;
        arr[min_index] = arr[i];
        arr[i] = min;

    }

    for (int k = 0; k < size; ++k){
        printf("%d ", arr[k]);
    }

    return 0;
}