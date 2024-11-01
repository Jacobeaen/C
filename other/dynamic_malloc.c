#include <stdio.h>
#include <stdlib.h>

int* append(int arr[], int element, int *capacity, int size)
{
    if (size >= *capacity){
        int *new_arr = malloc(sizeof(int) * (*capacity) * 2);

        if (new_arr == NULL)
            return arr;

        (*capacity) *= 2;
        for (int i = 0; i < size; ++i){
            new_arr[i] = arr[i];
        }
        new_arr[size] = element;

        free(arr);
        arr = new_arr;

        return arr;
    }

    arr[size] = element;
    
    return arr;
}

int main(void)
{
    int capacity;
    printf("Enter capacity of array: ");
    scanf("%d", &capacity);

    int *arr = malloc(sizeof(int) * capacity);

    if (arr == NULL){
        printf("Sorry, we can't dedicate memory(");
        return 0;
    }
    
    printf("Enter elements of the array.\n");
    printf("For stop enter -1\n");

    int i = 0;
    int x;
    while (scanf("%d", &x) == 1 && x != -1){
        arr = append(arr, x, &capacity, i);
        printf("size: %d, capacity: %d, element: %d\n", i + 1, capacity, x);

        i++;
    }
    for (int j = 0; j < i; ++j){
        printf("%d ", arr[j]);
    }

    free(arr);
    return 0;
}