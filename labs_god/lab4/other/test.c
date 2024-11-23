#include <stdio.h>
#include <stdbool.h>

int size1 = 7;
int size2 = 6;

int min(int x, int y){
    return (x < y) ? x : y;
}

void merge(int array[], int array1[], int array2[]){
}
int main(void){
    int arr1[] = {1, 3, 6, 8, 12, 15, 17};
    int arr2[] = {-19, -4, 0, 4, 77, 999};


    int arr[100];

    merge(arr, arr1, arr2);

    for (int i = 0; i < size1 + size2; i++){
        printf("%d ", arr[i]);
    }

    return 0;

    
}