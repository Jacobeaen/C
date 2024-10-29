#include <stdio.h>

#define     N       10
#define     M       8

int main(void)
{
    int matrix[N][M] = {0};

    int counter = 0;
    int spiral = 0;
    while (counter < N*M)
    {
        for (int j = spiral; j < M - spiral; j++){
            matrix[spiral][j] = counter++;
        }

        for (int i= spiral + 1; i < N - spiral; i++){
            matrix[i][M - 1 - spiral] = counter++;
        }

        for (int j = M - 2 - spiral; j >= spiral; j--){
            matrix[N - 1 - spiral][j] = counter++;
        }

        for (int i=N-2 - spiral; i >= 1 + spiral; i--){
            matrix[i][spiral] = counter++;
        }

        spiral++;
    }


    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}