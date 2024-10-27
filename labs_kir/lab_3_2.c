#include <stdio.h>
#include <string.h>

/*
Условие: на вход подается натуральное число n
Далее на вход подается n строк, в каждой строке два слова через пробел
Нужно склеить 2 слово в одно, вырезав их общую часть
3
шлакоблок окунь -> шлакоблокунь
папа мама -> папа мама
папа папаха -> папаха
*/


void clear(char *str, int len) {
    for (int i = 0; i < len; ++i) {
        str[i] = '\0';
    }
}

// Аналогично срезам в питоне, только индекс включительно
void slice(char *str, char *new_str, int start, int end)
{
    int j = 0;
    while (start <= end){
        new_str[j++] = str[start++]; 
    }
    new_str[j] = '\0';
    
}

// Индекс символа второго слова, с которого будет производится склейка
int get_begin_index(char *str1, char *str2, int len1, int len2)
{
    int end1 = len1 - 1;
    int start2 = 0;
    int step = 0;

    int start_index = 0;
    for (int i = end1; i >= 0; i--){
        char x[50] = {'\0'}, y[50] = {'\0'};
        slice(str1, x, end1 - step, end1);
        slice(str2, y, start2, start2 + step);

        if (strcmp(x, y) == 0)
            start_index = step + 1;

        step++;
    }

    return start_index;

}

void write_in_result(char *str1, char* str2, char result[], int start_index, int end_index){
    strcat(result, str1);
    slice(str2, str2, start_index, end_index);
    strcat(result, str2);
    strcat(result, "\n");
}

int main(void)
{
    char string1[50];
    char string2[50];
    char result[10000];

    int len1;
    int len2;

    int n;
    scanf("%d", &n);
    
    for (int k = 0; k < n; ++k) {
        scanf("%s %s", string1, string2);
        len1 = strlen(string1);
        len2 = strlen(string2);

        int index = get_begin_index(string1, string2, len1, len2);
        write_in_result(string1, string2, result, index, len2 - 1);
        
        clear(string2, len2);
        clear(string1, len1);
    }

    
    int i = 0;
    while (result[i]) {
        printf("%c", result[i++]);
    }

    return 0;
}