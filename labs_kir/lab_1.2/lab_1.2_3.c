#include <stdio.h>
#include <string.h>

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQ";
int quantity = 0;
int *ptr_quantity = &quantity;

// All -> base (long long)
void all(long long num, int base){
    int last;
    int negative = (num < 0) ? 1 : 0;
    int plus = 0;
    char num_arr[999];


    int i = 0;
    long long copy = (num > 0) ? num : -num;
    while (copy > 0){
        last = copy % base;

        num_arr[i] = alphabet[last];

        copy /= base;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    const int amount = *ptr_quantity;
    char arr[amount];
    for (int j = 0; i >= 0; i--, j++){
        arr[j] = num_arr[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr[j + 1] = arr[j];
        }
        arr[0] = '-';
    }
    
    printf("%s", arr);

}

int main(void){
    const short a = -021561;
    const int b = 011306225024;
    const unsigned int c = 035671111240;
    const long d = -016462603530;
    const unsigned long e = 024117737606;


    printf("short ");
    all(a, 8);
    printf("=");
    all(a, 4);
    printf(" 4");
    
    return 0;
}
