// Сортировка вставками, но только элементов, отстающих друг от друга на величину gap
// Если gap = 1, то это обычная сортировка вставками.
void insertionSort(int array[], int size, int gap, long long* compares, long long *swaps)
{
    for (int i = gap; i < size; ++i){
        int tmp = array[i];
        int j = i - gap;

        while (j >= 0 && tmp < array[j]){
            array[j + gap] = array[j];
            j -= gap;

            (*compares)++;
        }

        array[j + gap] = tmp;
        (*swaps)++;
    }
}

// Сортировка Шелла
int* shellSort(int array[], int size, long long *compares, long long *swaps)
{
    for (int gap = size / 2; gap > 0; gap /= 2){
        insertionSort(array, size, gap, compares, swaps);
    }

    return array;
}