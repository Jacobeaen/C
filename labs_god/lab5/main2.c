#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 1000

enum error {
    not_found = -1
};

// Проверка на ошибки открытия файла
void printError(FILE *file)
{
    if (file == NULL){
        puts("Sorry, this file doesn't exist or access is restricted.");
        puts("End of the programm...");
        exit(0);
    }
}

// Обнуляем массив (все элементы '\0')
void Clear(char word[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        word[i] = '\0';
    }
}

// Удаление \n в конце строки после fgets
void delSpace(char *string)
{
    int i = 0;
    while (string[i] != '\n' && string[i] != '\0')
    {
        i++;
    }
    string[i] = '\0';
}

// Подсчет количества слов в файле
int getWordsAmount(FILE *file)
{
    char word[MAX_WORD_LEN];
    int count = 0;

    while (fscanf(file, "%s", word) != EOF)
    {
        count++;
    }

    return count;
}

// Заполняем массив слова из words1/words2
void appendWordsInArray(FILE *file, char array[][MAX_WORD_LEN], size_t size)
{
    char string[MAX_WORD_LEN];
    int i = 0;

    while (fgets(string, MAX_WORD_LEN, file) && i < size)
    {
        delSpace(string);
        strncpy(array[i], string, MAX_WORD_LEN - 1);
        array[i][MAX_WORD_LEN - 1] = '\0';
        i++;
    }
}

// Индекс слова, если его надо заменить, -1 в противном случае
int getIndex(char *word, char array[][MAX_WORD_LEN], size_t size)
{
    for (int i = 0; i < size; i++){
        if (strcmp(word, array[i]) == 0){
            return i;
        }
    }

    return not_found;
}

// Записываем слова в файл file_out.txt
void changeAndWrite(FILE *file_in, FILE *file_out, char words1[][MAX_WORD_LEN], char words2[][MAX_WORD_LEN], size_t size)
{
    char word[MAX_WORD_LEN];
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

            if (index != -1)
                fprintf(file_out, "%s", words2[index]);
            else
                fprintf(file_out, "%s", word);

            if (symbol == EOF)
                return;

            
            fprintf(file_out, "%c", symbol);
            Clear(word, strlen(word));
            
            i = 0;
        }
    }

    word[i] = '\0';
    if (strlen(word) > 0){
        int index = getIndex(word, words1, size);

        if (index != -1)
            fprintf(file_out, "%s", words2[index]);
        else
            fprintf(file_out, "%s", word);
    }
}

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        puts("Invalid amount of parameters");
        return 0;
    }

    FILE *file_in = fopen(argv[1], "r");
    FILE *words1 = fopen(argv[2], "r");
    FILE *words2 = fopen(argv[3], "r");
    FILE *file_out = fopen(argv[4], "w");

    printError(file_in);
    printError(words1);
    printError(words2);
    printError(file_out);

    size_t words_count = getWordsAmount(words1);
    rewind(words1);
    rewind(words2);

    char words1_arr[MAX_WORDS][MAX_WORD_LEN];
    char words2_arr[MAX_WORDS][MAX_WORD_LEN];

    appendWordsInArray(words1, words1_arr, words_count);
    appendWordsInArray(words2, words2_arr, words_count);

    changeAndWrite(file_in, file_out, words1_arr, words2_arr, words_count);

    fclose(file_in);
    fclose(words1);
    fclose(words2);
    fclose(file_out);

    return 0;
}
