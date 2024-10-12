#include <stdio.h>

int main(void){

    char string[101];
    char new_string[101];
    fgets(string, 100, stdin);

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