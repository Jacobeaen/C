#include <stdio.h>

int right(int arr[][5], int i, int j, int current)
{
    if (arr[i - 1][j + 1] > current){
        return 1 + right(arr, i - 1, j + 1, arr[i - 1][j + 1]);       
    }
    return 0;
}

int left(int arr[][5], int i, int j, int current)
{
    if (arr[i - 1][j - 1] > current){
        return 1 + right(arr, i - 1, j - 1, arr[i - 1][j - 1]);       
    }
    return 0;
}

int bottom(int arr[][5], int i, int j, int current)
{
    if (arr[i + 1][j] > current){
        return 1 + right(arr, i + 1, j, arr[i + 1][j]);       
    }
    return 0;
}


int main(void)
{
    int arr[5][5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int y, count = 1;
    // Границы для i и j
    for (int i = 1; i < 4; i++){
        for (int j = 0; j < 5; j++){
            int current = arr[i][j];
            for (int k = 0; k < i; k++)    
                y = right(arr, i, j, current) + left(arr, i, j, current) + bottom(arr, i, j, current);
        
            count = (y > count) ? y : count;
        }
    } 

    printf("%d", y);



    return 0;
}