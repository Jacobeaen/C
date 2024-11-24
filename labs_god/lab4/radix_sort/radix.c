#include <stdio.h>

int findMax(int array[], int size);
int digitCount(int number);

    int main(void)
{
    int array[] = {2, 5, -3, 0, 33, -55, 88, 2};
    int size = sizeof(array) / sizeof(array[0]);

    int amount = digitCount(findMax(array, size));

    printf("%d", amount);
    
    return 0;
}


// Наибольший элемент в массиве
int findMax(int array[], int size){
    int max = array[0];

    for (int i = 1; i < size; i++){
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

// Число разрядов в числе
int digitCount(int number){
    int count = 0;

    while (number > 0){
        number /= 10;
        count++;
    }

    return count;
}

