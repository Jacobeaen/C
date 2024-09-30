#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arr(int arr[], size_t size)
{

    for (int j = 0; j < 10; j++){
        arr[j] = rand();
    }
}

int main(void)
{

    int arr1[10];
    int *arr2[10];

    size_t size = sizeof(arr1) / sizeof(*arr1);

    srand(time(NULL));
    fill_arr(arr1, size);

    for (int i = 0; i < 10; i++){
        arr2[i] = &arr1[i];
    }

    for (int i = 0; i < 10; i++){
        printf("%d ", arr1[i]);
    }

    printf("\n");
    for (int i = 0; i < 10; i++){
        printf("%p ", arr2[i]);
    }


    return 0;
}