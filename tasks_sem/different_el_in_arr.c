#include <stdio.h>

int el_in_arr(int el, int arr[], int size){

    for (int i = 0; i < size; i++){
        if (arr[i] == el)
            return 0;
    }
    return 1;
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

    int count = 0;
    for (int i = 0; i < quantity; i++){
        if (el_in_arr(arr[i], used, quantity)){
            count++;
            used[i] = arr[i];
        }
        
    }

    printf("Different elements in arr: %d", count);

    return 0;
}