#include <stdio.h>

/*
Условие: на вход подается строка
Нужно заменить цепочку подряд идущих символов на один символ
aassbbbttteeeeod22222f44f
*/


int main(void){

    char string[10001];
    char new_string[10001];
    fgets(string, 10000, stdin);

    if (string[0] == '\n'){
        printf("[\n]");
        return 0;
    }

    int i = 0, j = 0;
    while (string[i] != '\0' && string[i] != '\n'){
        if (i == 0)
            new_string[j++] = string[i];
        else if (string[i] != string[i - 1] && string[i] != '\0' && string[i] != '\n')
            new_string[j++] = string[i];    

        i++;
    }

    new_string[j] = '\0';

    
    printf("%s", new_string);


    return 0;
}