#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void delSpace(char *);
void copyWords(char *src, char *dst);
void AppendWordsInArray(FILE *file, char *array[], size_t size);
void printArray(char *array[], size_t size);
int getWordsAmount(FILE *file);
void ChangeAndPrint(FILE *file_in, FILE *file_out, char *array_1[], char *array_2[], size_t size);
void setZeros(char word[], size_t size);
int getIndex(char *word, char *array[], size_t size);
void setFree(char *array[], size_t size);

enum lenght {
    max_file_len = 100,
    max_word_len = 50,
};

enum error {
    not_found = -1
};

int main(void)
{
    char filename_in[max_file_len];
    char filename_out[max_file_len];

    char words_to_replace[max_file_len];
    char replacement_words[max_file_len];
    
    printf("Enter name of the source file:\n");
    printf(">> ");
    fgets(filename_in, max_file_len, stdin);
    delSpace(filename_in);

    printf("Enter words_to_replace file (which we change):\n");
    printf(">> ");
    fgets(words_to_replace, max_file_len, stdin);
    delSpace(words_to_replace);

    printf("Enter words_to_replace file (on which we change):\n");
    printf(">> ");
    fgets(replacement_words, max_file_len, stdin);
    delSpace(replacement_words);

    printf("Enter filename that will be result:\n");
    printf(">> ");
    fgets(filename_out, max_file_len, stdin);
    delSpace(filename_out);

    // file_1 - слова, которые надо заменить, size одинаковый
    FILE *file_1 = fopen(words_to_replace, "r");
    size_t size = getWordsAmount(file_1);
    fseek(file_1, 0, SEEK_SET);
    char *array_1[size];
    AppendWordsInArray(file_1, array_1, size);

    // file_2 - слова, на которые мы заменяем
    FILE *file_2 = fopen(replacement_words, "r");
    char *array_2[size];
    AppendWordsInArray(file_2, array_2, size);

    FILE *file_in = fopen(filename_in, "r");
    FILE *file_out = fopen(filename_out, "w");

    ChangeAndPrint(file_in, file_out, array_1, array_2, size);
    
    setFree(array_1, size);
    setFree(array_2, size);

    return 0;
}

// Удаление \n в конце строки после fgets
void delSpace(char *string)
{
    int i = 0;
    while (string[i] != '\n'){
        if (string[i] == EOF){
            return;
        }

        i++;
    }

    string[i] = '\0';
}

// Копируем слово из одного массива в другой вместе с '\0'
void copyWords(char *src, char *dst){
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

// Подсчет количества слов в filename_in
int getWordsAmount(FILE *file){
    char word[max_word_len];

    int i = 0;
    while (!feof(file)){
        fscanf(file, "%s", word);

        i++;
    }

    return i;
}

// Заполняем массив слова из file_1/file_2
void AppendWordsInArray(FILE *file, char *array[], size_t size){
    char string[max_word_len];

    int len;
    int i = 0;

    while (!feof(file)){
        fgets(string, max_word_len, file);
        
        delSpace(string);
        len = strlen(string);

        // 1 оставляем для символа '\0'
        char *word = malloc(len * sizeof(char) + 1);
        copyWords(string, word);

        array[i++] = word;
    }
}

// Обнуляем массив (все элементы '\0')
void setZeros(char word[], size_t size){
    for (int i = 0; i < size; i++){
        word[i] = '\0';
    }
}

// Индекс слова, если его надо заменить, -1 в противном случае
int getIndex(char *word, char *array[], size_t size){
    for (int i = 0; i < size; i++){
        if (strcmp(word, array[i]) == 0)
        {
            return i;
        }
    }

    return not_found;
}

// Записываем слова в файл file_out.txt
void ChangeAndPrint(FILE *file_in, FILE *file_out, char *array_1[], char *array_2[], size_t size){
    char word[max_word_len];

    char symbol;
    int i = 0;

    while (true){
        symbol = getc(file_in);

        if (isgraph(symbol)){
            word[i++] = symbol;
        }
        

        else if (isspace(symbol) || symbol == EOF){
            word[i] = '\0';

            int index = getIndex(word, array_1, size);
            
            // Если слово найдено - заменяем
            if (index != -1)
                printf("%s", array_2[index]);
            else
                printf("%s", word);

            if (symbol == EOF)
                return;

            printf("%c", symbol);

            setZeros(word, strlen(word));
            i = 0;
        }
    }
}

// Очищаем содержимое array
void setFree(char *array[], size_t size){
    for (int i = 0; i < size; i++){
        free(array[i]);
    }
}

// Выводим массивы на экран
void printArray(char *array[], size_t size){
    for (int i = 0; i < size; ++i){
        printf("%s\n", array[i]);
    }
}