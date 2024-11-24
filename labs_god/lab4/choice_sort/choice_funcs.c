// Индекс минимального элемента в неотсортированной части массива
int findMin(int array[], int size, int start, int *compares)
{
    int min = array[start];
    int index = start;

    for (int i = start + 1; i < size; ++i){
        if (array[i] < min){
            min = array[i];
            index = i;
        }

        (*compares)++;
    }

    return index;
}

// Минимальный элемент меняется местами с текущим элементом, если последний не минимальный
void Swap(int array[], int i, int j)
{
    int tmp = array[i];

    array[i] = array[j];
    array[j] = tmp;
}

// Сортировка выбором
int* choiceSort(int array[], int size, int *compares, int *swaps)
{
    for (int i = 0; i < size - 1; ++i){
        int min_index = findMin(array, size, i, compares);

        if (min_index != i){
            Swap(array, i, min_index);
            (*swaps)++;
        }
    }

    return array;
}
