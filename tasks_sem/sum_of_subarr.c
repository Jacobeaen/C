#include <stdio.h>

int main(void){
    int f, amount, quantity;

    printf("Put number f:\n>> ");
    scanf("%d", &f);

    printf("Put amount of elements in array (N >= f):\n>> ");
    scanf("%d", &amount);    
    quantity = amount;

    if (amount < f){
        printf("There is no subarrays in array");
        return 0;
    }

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

    int count_all = 0;
    for (int i = 0; i <= quantity - f; i++){
        int count = 0;
        for (int j = i; j < f + i; j++){
            count += arr[j];
        }
        printf("Sum of array (%d): %d\n", i + 1, count);
        count_all += count;
    }   

    printf("Sum of subarrays with len %d: %d", f, count_all);


    return 0;
}