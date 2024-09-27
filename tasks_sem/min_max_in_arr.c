#include <stdio.h>

int main(void){
    int amount, quantity;

    printf("Put amount of elements in array:\n>> ");
    scanf("%d", &amount);    
    quantity = amount;

    printf("Put elements.\n");

    int arr[amount];
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

    int min = arr[0], max = arr[0];
    for (int i = 0; i < quantity; i++){
        if (min > arr[i])
            min = arr[i];

        if (max < arr[i])
            max = arr[i];
    }

    printf("Min: %d\nMax: %d", min, max);

    return 0;
}