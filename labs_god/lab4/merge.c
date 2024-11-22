#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


int compares = 0;
int swaps = 0;

void Welcome();
int fromFile(int *);
int fromUser(int *);
void delSpace(char *);
void printArrays(int *, int, char*);
bool isNumber(char);
int getNumber(int [], int, bool);
int getNumbers(int [], FILE*);
void copyNumbers(int [], int [], int, int);
int* mergeSort(int [], int);

int main(void)
{    
    int *array = malloc(sizeof(int) * 1000000);

    Welcome();

    char answer[100];
    fgets(answer, 100, stdin);

    int size;
    if (answer[0] == '1' && strlen(answer) == 2)
        size = fromFile(array);
    else if (answer[0] == '2' && strlen(answer) == 2)
        size = fromUser(array);
    else {
        printf("Invalid input!");
        return 0;
    }
    if (size == -1)
        return 0;

    printArrays(array, size, "Source");
    printf("\n");

    // clock() - количество тиков процессора. Такой способ более предпочтителен,
    // тк исключает такие факторы, как производительность системы
    clock_t start = clock();
    array = mergeSort(array, size);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printArrays(array, size, "Sorted");
    printf("\nTime: %lf", seconds);
    printf("\nCompares: %d", compares);
    printf("\nSwaps: %d", swaps);

    free(array);

    return 0;
}

// Приветствие и выбор режима
void Welcome(){
    puts("Choose mode of programm:");
    puts("1. Numbers from file");
    puts("2. Numbers from cli");    
    printf(">> ");
}

// Заполняем массив из файла, -1 если ошибка, иначе возвращаем размер массива
int fromFile(int *array){
    char filename[50];

    printf("Enter filename: ");
    fgets(filename, 50, stdin);
    delSpace(filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Wrong name, try again");
        return -1;
    }

    int size = getNumbers(array, file);
    
    return size;
}

// Заполняем массив при помощи пользовательского ввода -1 если ошибка, иначе размер
int fromUser(int *array){
    int size;
   
    printf("Enter amount of numbers: ");
    scanf("%d", &size);

    if (size <= 0){
        printf("Number must be positive");
        return -1;
    }

    for (int i = 0; i < size; ++i){
        scanf("%d", &array[i]);
    }

    return size;
}

void printArrays(int *array, int size, char *type){
    printf("%s array: ", type);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    
}

// Удаляем символ \n при вводе имени файла
void delSpace(char *string){
    int i = 0;
    while (string[i] != '\n'){
        i++;
    }

    string[i] = '\0';
}

// Из двух отсортированных массивов получаем большой отсортированный
int *mergeArrays(int array1[], int size1, int array2[], int size2){
    int *array = malloc(sizeof(int) * (size1 + size2));

    int i = 0;
    int j = 0;
    int k = 0;

    while (true)
    {
        if (i == size1 && j == size2)
            break;

        else if (i == size1)
            array[k] = array2[j++];

        else if (j == size2)
            array[k] = array1[i++];

        else if (array1[i] < array2[j]){
            array[k] = array1[i++];
            compares++;
        }
        else{
            array[k] = array2[j++];
            compares++;
        }

        k++;
        swaps++;
    }

    return array;
}

// Заполняем массив чисел из файла
int getNumbers(int array[], FILE *file)
{
    int i = 0;
    int j = 0;

    int number[100];
    bool negative = false;

    char digit;
    while (true)
    {
        digit = fgetc(file);
        
        if (digit == '-'){
            negative = true;
        }

        if (isNumber(digit))
        {
            number[i] = digit - '0';
            i++;
        }
        else if (digit == ' ' || digit == EOF)
        {
            array[j++] = getNumber(number, i, negative);

            i = 0;
            negative = false;

            if (digit == EOF)
            {
                break;
            }
        }
    }

    return j;
}

// Проверка символа на число
bool isNumber(char symbol)
{
    return symbol >= 48 && symbol <= 57;
}

// Получение числа из массива, в который записываются символы
int getNumber(int array[], int size, bool negative)
{
    int i = 1;

    int number = 0;
    for (int j = size - 1; j >= 0; j--)
    {
        int digit = array[j];

        number = number + digit * i;

        i *= 10;
    }

    if (negative)
        return -number;

    return number;
}

// Копирование чисел из осного массива в левую/правую часть
void copyNumbers(int src_array[], int dst_array[], int start, int stop)
{
    int j = 0;
    for (int i = start; i < stop; i++)
    {
        dst_array[j++] = src_array[i];
    }
}

// Основная функция сортировки
int* mergeSort(int array[], int size)
{
    size_t left_size = size / 2;
    size_t right_size = size - left_size;

    int *array_left = malloc(sizeof(int) * left_size);
    int *array_right = malloc(sizeof(int) * (right_size));

    copyNumbers(array, array_left, 0, left_size);
    copyNumbers(array, array_right, left_size, size);

    if (left_size > 1)
        array_left = mergeSort(array_left, left_size);
    if (right_size > 1)
       array_right = mergeSort(array_right, right_size);

    array = mergeArrays(array_left, left_size, array_right, right_size); 

    free(array_left);
    free(array_right);

    return array;
}