#include <stdio.h>
#include <string.h>

void cat_strings(char str1[],  char str2[], char str3[], int len1, int len2)
{
    int index = 0;
    for (int i = 0; i < len1 - 1; i++){
        str3[index++] = str1[i];
    }
    for (int i = 0; i < len2 - 1; i++){
        if (str2[i] == '\n')
            break;
        str3[index++] = str2[i];
    }
}


int main(void)
{
    char str1[101];
    char str2[101];
    fgets(str1, 101, stdin);
    fgets(str2, 101, stdin);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char str3[len1 + len2];

    cat_strings(str1, str2, str3, len1, len2);
    printf("string1 + string2 = %s", str3);

    return 0;
}