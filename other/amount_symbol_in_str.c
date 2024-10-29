#include <stdio.h>

int main(void){
    char string[] = "Why not Python?";
    printf("size = %d\n", sizeof(string));

    char char_array[100];
    int amount_char[100];

    int i = 0;

    int count = 0;
    while (string[i] != '\0'){
        int flag = 1;
        for (int j = 0; j < count; j++){
            if (char_array[j] == string[i]){
                amount_char[j]++;
                flag = 0;
                break;
            }
        }

        if (flag){
            char_array[count] = string[i];
            amount_char[count] = 1;
            count++;
        }

        i++;
    }

    for (int i = 0; i < count; i++){
        printf("\"%c\" = %d\n", char_array[i], amount_char[i]);
    }

    return 0;
}