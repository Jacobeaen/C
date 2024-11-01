#include <stdio.h>

int delete_duplicate(int arr[], int size)
{
    int arr2[1000];
    int size_arr2 = 0;
    for (int i = 0; i < size; i++){
        int flag = 1;

        for (int j = 0; j < size_arr2; j++){
            if (arr[i] == arr2[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            arr2[size_arr2] = arr[i];
            size_arr2++;
        }
    }

    for (int i = 0; i < size_arr2; i++){
        arr[i] = arr2[i];
    }

    return size_arr2; 
}

int main(void)
{
    int x[100] = {1, 3, 4, 4, 4, 5, 67, 9, 9, 3};

    int size = delete_duplicate(x, 10);

    for (int i = 0; i < size; i++){
        printf("%d ", x[i]);
    }

    return 0;
}