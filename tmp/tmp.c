#include <stdio.h>

int next(int arr[], int size, int last, int i)
{
    int current = arr[i];

    if (i < size - 1){
        if (arr[i] > last)
            return 1 + next(arr, size, arr[i], i + 1);
        return 0;
    }
    return arr[i] > last;
    


}

int main(void)
{
    int arr[5] = {1, 3, 3, 0, 7};

    for (int i = 0; i < 4; i++){
        int c = next(arr, 5, arr[i], i + 1);
        printf("%d ", c);
    }

    return 0;
}