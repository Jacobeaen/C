#include <stdio.h>

int binary_search(int arr[], int el, int size)
{
    if (size <= 1)
        return 0;
    
    int low = 0, index = size / 2, high = size - 1;
    while (arr[index] != el){
        //printf("low: %d, high: %d, index: %d, element: %d\n", low, high, index, arr[index]);
        
        if (high - index == 1)
            return high;
        if (el > arr[index]){
            low = index;
            index = (index + high) / 2;
        }
        else{
            high = index;
            index = high / 2;
        }
    }
    
    return index;
}


int main(void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int index = binary_search(arr, 10, 10);
    printf("index: %d", index);

    return 0;
}