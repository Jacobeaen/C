#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int numInArray(int *[], int*, int);
int append(int array[]);
int main(void)
{
    int array[1000];

    int* num_array[1000];
    int count_array[1000];

    FILE *file = fopen("numbers.txt", "r");

    int size = 0;
    while (!feof(file)){
        fscanf(file, "%d", &array[size++]);
    }


    int j = 0;
    for (int i = 0; i < size; ++i){
        int el = array[i];

        int index = numInArray(num_array, &el, j);

        // Если числа нет в массиве - добавляем указатель на массив и ставим значение в 1
        // Если есть - прибавляем +1.
        if (index  == -1){
            int *number = malloc(sizeof(int) * 1);
            *number = el;

            num_array[j] = number;
            count_array[j] = 1;

            j++;
        }
        else {
            count_array[index]++;
        }

    }

    for (int i = 0; i < j; ++i){
        int num = *num_array[i];
        int amount = count_array[i];
        printf("number: %d, amount: %d\n", num, amount);
    }
    


    return 0;
}

int numInArray(int *array[], int *number, int size){
    for (int i = 0; i < size; i++){
        int el = *array[i];
        if (el == *number)
            return i;
    }

    return -1;
}