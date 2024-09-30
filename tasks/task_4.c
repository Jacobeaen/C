#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void min_max(int arr[], int *maximum, int *max_i, int *minimum, int *min_i, size_t size)
{
    *maximum = arr[0];
    *minimum = arr[0];

    *max_i = 0;
    *min_i = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] > *maximum){
            *maximum = arr[i];
            *max_i = i;
        }
        if (arr[i] < *minimum){
            *minimum = arr[i];
            *min_i = i;
        }
    }
}

void fill_arr(int arr[], size_t size)
{

    for (int j = 0; j < 10; j++){
        arr[j] = rand();
    }
}

int main(void)
{
    int arr[10];
    int max = 0, min = 0, index_max = 0, index_min = 0;
    size_t size = sizeof(arr) / sizeof(*arr);

    srand(time(NULL));
    fill_arr(arr, size);
    min_max(arr, &max, &index_max, &min, &index_min, size);

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\nMax: %d, index: %d\nMin: %d, index: %d", max, index_max, min, index_min);

    return 0;
}