#include <stdio.h>
#include <stdlib.h>

int* append(int arr[], int element, int *capacity, int size)
{
    if (size >= *capacity){
        int new_capacity = *capacity * 2;
        int *new_arr = realloc(arr, sizeof(int) * new_capacity);

        if (new_arr == NULL)
            return arr;

        arr = new_arr;

        *capacity = new_capacity;
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

    int capacity = 4;
    
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