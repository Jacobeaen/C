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
int (*enterMode(char *answer))(int *);
void delSpace(char *);
void printArrays(int *, int, char*);
void copyNumbers(int [], int [], int, int);
int *mergeArrays(int array1[], int size1, int array2[], int size2);
int *mergeSort(int[], int);

int main(void){
    srand(time(NULL));

    int *array = malloc(sizeof(int) * 1000000);

    Welcome();

    char answer[100];
    fgets(answer, 100, stdin);

    // Возвращается fromFile или fromUser в зависимости от ввода
    int (*Fill)(int *) = enterMode(answer);

    if (Fill == NULL)
        return 0;

    int size = Fill(array);

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
    puts("Choose Fill of programm:");
    puts("1. Numbers from file");
    puts("2. Numbers from cli");
    puts("3. Numbers from PC (random)"); 
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
        printf("Invalid name of file!");
        return -1;
    }

    int size = 0;
    while (!feof(file)){
        fscanf(file, "%d", &array[size++]);
    }

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

int fromPC(int *array){
    int size;

    printf("Enter amount of numbers: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Number must be positive");
        return -1;
    }

    for (int i = 0; i < size; ++i){
        array[i] = rand() % RAND_MAX - 16383;
    }

    return size;
}

// Возвращаем режим, с помощью которого будет заполняться массив
int (*enterMode(char *answer))(int *){
    if (answer[0] == '1' && strlen(answer) == 2)
        return fromFile;
    else if (answer[0] == '2' && strlen(answer) == 2)
        return fromUser;
    else if (answer[0] == '3' && strlen(answer) == 2)
        return fromPC;
    else{
        printf("Invalid input!");
        return NULL; 
    }
}

// Выовд массивов
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