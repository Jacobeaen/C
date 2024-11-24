#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

// Начальное сообщение с просьбой выбора режима работы программы
void Welcome()
{
    puts("Choose Fill of programm:");
    puts("1. Numbers from file");
    puts("2. Numbers from cli");
    puts("3. Numbers from PC (random)");
    printf(">> ");
}

// Удаление \n в конце строки после fgets
void delSpace(char *string)
{
    int i = 0;
    while (string[i] != '\n')
    {
        i++;
    }

    string[i] = '\0';
}

// Заполение массива из файла
int fromFile(int *array)
{
    char filename[50];

    printf("Enter filename: ");
    fgets(filename, 50, stdin);
    delSpace(filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Invalid name of file!");
        return -1;
    }

    int size = 0;
    while (!feof(file)){
        fscanf(file, "%d", &array[size++]);
    }

    fclose(file);

    return size;
}

// Заполение массива вручную через командную оболочку
int fromUser(int *array)
{
    int size;

    printf("Enter amount of numbers: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Number must be positive");
        return -1;
    }

    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }

    return size;
}

// Заполение массива случайными числами
int fromPC(int *array)
{
    int size;

    printf("Enter amount of numbers: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Number must be positive");
        return -1;
    }

    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % RAND_MAX - 16383;
    }

    return size;
}

// Установка режима работы в зависимости от пользовательского ввода
int (*enterMode(char *answer))(int *)
{
    if (answer[0] == '1' && strlen(answer) == 2)
        return fromFile;
    else if (answer[0] == '2' && strlen(answer) == 2)
        return fromUser;
    else if (answer[0] == '3' && strlen(answer) == 2)
        return fromPC;
    else
    {
        printf("Invalid input!");
        return NULL;
    }
}

// Копирование массива
void copyArray(int src[], int dst[], int size){
    for (int i = 0; i < size; ++i){
        dst[i] = src[i];
    }
}

// Вывод массива на экран
void printArrays(int *array, int size, char *type)
{
    printf("%s array: ", type);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

// Сортируем массив и возвращаем время сортировки
void sortAndPrintStatistics(int *array, int size, int* (*sort)(int*, int, int*, int*), char *sort_name){
    clock_t start = clock();

    int compares = 0;
    int swaps = 0;

    array = sort(array, size, &compares, &swaps);
    clock_t end = clock();

    double time = (double)((end - start) / CLOCKS_PER_SEC) * 1000;

    printf("%s:\n", sort_name);
    printArrays(array, size, "Sorted");
    printf("\nTime: %lf\n", time);
    printf("Compares: %d\n", compares);
    printf("Swaps: %d\n\n", swaps);
}