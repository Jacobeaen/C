#include <stdio.h>

int min2(int x, int y)
{
    return (x < y) ? x : y;
}

int min3(int x, int y, int z)
{
    return min2(min2(x, y), z);
}


int bottom(int arr[][13], int last, int size_i, int i, int j)
{

    int current = arr[i][j];
    if (i < size_i - 1){
    
        if (current >= last)
            return 1 + bottom(arr, arr[i][j], size_i, i + 1, j);
        return 0;
    }
    else if (i == size_i - 1)
        return current >= last;
    return 0;
}

int left(int arr[][13], int last, int i, int j)
{
    int current = arr[i][j];
    if (i > 0 && j > 0){
        if (current >= last)
            return 1 + left(arr, arr[i][j], i - 1, j - 1);
        return 0;
    }
    if (i == 0 || j == 0)
        return current >= last;
    return 0;

}

int right(int arr[][13], int last, int size_j, int i, int j)
{
    int current = arr[i][j];

    if (i > 0 && j < size_j - 1){
        if (current >= last)
            return 1 + right(arr, arr[i][j], size_j, i - 1, j + 1);
        return 0;
    }
    else if (i == 0 || j == size_j - 1)
        return current >= last;
    
    return 0;

}


int main(void)
{
    int arr[11][13];
    int size_i = 11, size_j = 13;

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 13; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");
    int count = 1;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 12; j++){
            int left_y = left(arr, arr[i][j], i - 1, j - 1);
            int bottom_y = bottom(arr, arr[i][j], size_i, i + 1, j);
            int right_y = right(arr, arr[i][j], size_j, i - 1, j + 1);
            
            int y = min3(left_y, bottom_y, right_y);
            printf("i: %d, j: %d, lef: %d, bot: %d, rig: %d, y: %d\n", i, j, left_y, bottom_y, right_y, y);

            count = (y >= count) ? (y + 1) : count;
        }
        printf("\n");
    }

    printf("%d", count);
    return 0;
}