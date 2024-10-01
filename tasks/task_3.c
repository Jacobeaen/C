#include <stdio.h>

// Перевод строчных букв в заглавные и наоборот
// Символ А менятся на X
int main(void){
    char arr[10000];

    int k = 0;
    while (scanf("%c", &arr[k]) == 1 && arr[k] != '\n'){
        k++;
    }

    int i = 0;
    while (arr[i] != 10){
        if (arr[i] >= 65 && arr[i] <= 90){
            arr[i] += 32;
        }
        else if (arr[i] >= 97 && arr[i] <= 122){
            arr[i] -= 32;
        }

        if (arr[i] == 'A'){
            arr[i] = 'X';
        }

        i += 1;
    }

    printf("%s", arr);


    return 0;
}