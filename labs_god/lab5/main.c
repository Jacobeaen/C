#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void delSpace(char *);
void copyWords(char *src, char *dst);
void appendWordsInArray(FILE *file, char *array[], size_t size);
void printArray(char *array[], size_t size);
int getWordsAmount(FILE *file);
void changeAndWrite(FILE *file_in, FILE *file_out, char *words1[], char *words2[], size_t size);
void Clear(char word[], size_t size);
int getIndex(char *word, char *array[], size_t size);
void setFree(char *array[], size_t size);
void printError(FILE *file);

enum lenght {
    max_file_len = 100,
    max_word_len = 50,
};

enum error {
    not_found = -1
};

int main(int argc, char** argv)
{
    if (argc != 5){
        puts("Invalid amount of paremetrs");
        return 0;
    }

    // words1 - слова, которые надо заменить, size одинаковый
    // words2 - слова, на которые мы заменяем слова из words1
    FILE *file_in = fopen(argv[1], "r");
    FILE *words1 = fopen(argv[2], "r");
    FILE *words2 = fopen(argv[3], "r");
    FILE *file_out = fopen(argv[4], "w");

    printError(file_in);
    printError(words1);
    printError(words2);
    printError(file_out);

    size_t size = getWordsAmount(words1);
    rewind(words1);
    //fseek(words1, 0, SEEK_SET);

    char *words1[size];
    appendWordsInArray(words1, words1, size);

    char *words2[size];
    appendWordsInArray(words2, words2, size);

    changeAndWrite(file_in, file_out, words1, words2, size);
    
    setFree(words1, size);
    setFree(words2, size);

    fclose(file_in);
    fclose(words1);
    fclose(words2);
    fclose(file_out);

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

// Заполняем массив слова из words1/words2
void appendWordsInArray(FILE *file, char *array[], size_t size){
    char string[max_word_len];

    int len;
    
    int i = 0;
    while (!feof(file)){
        fgets(string, max_word_len, file);
        
        delSpace(string);
        len = strlen(string);

        char *word = malloc(len * sizeof(char) + 1);
        copyWords(string, word);

        array[i++] = word;
    }
}

// Обнуляем массив (все элементы '\0')
void Clear(char word[], size_t size){
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
void changeAndWrite(FILE *file_in, FILE *file_out, char *words1[], char *words2[], size_t size){
    char word[max_word_len];

    char symbol;
    int i = 0;

    while (true){
        symbol = getc(file_in);

        if (isalnum(symbol)){
            word[i++] = symbol;
        }        


        else if (ispunct(symbol) || isspace(symbol) || symbol == EOF){
            word[i] = '\0';

            int index = getIndex(word, words1, size);
            
            // Если слово найдено - заменяем
            if (index != -1)
                //printf("%s", words2[index]);
                fprintf(file_out, "%s", words2[index]);
            else
                //printf("%s", word);
                fprintf(file_out, "%s", word);

            if (symbol == EOF)
                return;

            //printf("%c", symbol);
            fprintf(file_out, "%c", symbol);

            Clear(word, strlen(word));
            i = 0;
        }
    }

    word[i] = '\0';
    if (strlen(word) > 0)
    {
        int index = getIndex(word, words1, size);

        if (index != -1)
            fprintf(file_out, "%s", words2[index]);
        else
            fprintf(file_out, "%s", word);
    }
}

// Очищаем содержимое array
void setFree(char *array[], size_t size){
    for (int i = 0; i < size; i++){
        free(array[i]);
    }
}

// Проверка на ошибки открытия файла
void printError(FILE *file){
    if (file == NULL){
        puts("Sorry, this file doesn't exist or access is restricted.");
        puts("End of the programm...");
        exit(0);
    }
}

// Выводим массивы на экран
void printArray(char *array[], size_t size){
    for (int i = 0; i < size; ++i){
        printf("%s\n", array[i]);
    }
}