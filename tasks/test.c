#include <stdio.h>

int main(void){

    int num10 = 183;
    int num8 = 0267;
    int num2 = 0b10110111;
    int num16 = 0xB7;

    int arr[] = {1, 2, 3, 4};

    int *ptr = arr;

    int size = sizeof(ptr);
    printf("%d", size);

    return 0;
}