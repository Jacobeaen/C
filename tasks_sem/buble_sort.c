#include <stdio.h>

void print_array(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
}

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void buble_sort(int arr[], size_t size){
    for (int i=0; i < size - 1; i++){
        for (int j=1; j < size - i; j++){
            if (arr[j - 1] > arr[j])
                swap(arr, j-1, j);
        }
    }
}

int main(void)
{
    int array[] = {1, 4, 5, 6, 0, 0, -5, -123};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Source array: ");
    print_array(array, size);

    buble_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}