#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int array[], int size, int start){
    int min = array[start];
    int index = start;

    for (int i = start + 1; i < size; ++i){
        if (array[i] < min){
            min = array[i];
            index = i;
        }
    }

    return index;
}
void Swap(int array[], int i, int j){
    int tmp = array[i];

    array[i] = array[j];
    array[j] = tmp;
}
void choiceSort(int array[], int size){
    for (int i = 0; i < size - 1; ++i){
        int min_index = findMin(array, size, i);

        if (min_index != i){
            Swap(array, i, min_index);
        }
    }
}

int main(void)
{
    srand(time(NULL));

    int array[10];
    int size = sizeof(array) / sizeof(array[0]);

    int num;
    for (int i = 0; i < size; ++i){
        num = (rand() % 200) - 100;
        array[i] = num;
    }

    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }

    choiceSort(array, size);
    puts("");

    for (int k = 0; k < size; ++k){
        printf("%d ", array[k]);
    }

    return 0;
}