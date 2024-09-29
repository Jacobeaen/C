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
    int amount, quantity;

    printf("Put amount of elements in array:\n>> ");
    scanf("%d", &amount);    
    quantity = amount;

    printf("Put elements.\n");

    int arr[amount];
    int used[amount];
    int j = 0;
    while (scanf("%d", &arr[j++]) == 1 && --amount > 0){
    }   

    printf("Your array: [");
    for (int k = 0; k < quantity; k++){
        printf("%d", arr[k]);
        if (k != quantity - 1)
            printf(", ");
    }
    printf("]\n");

    int el;
    printf("What's element we're looking for:\n>> ");
    scanf("%d", &el);

    int index = binary_search(arr, el, quantity);
    printf("Your element: %d at index: %d", el, index);

    return 0;
}