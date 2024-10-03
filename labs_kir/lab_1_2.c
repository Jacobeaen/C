#include <stdio.h>
#include <string.h>

#define SIZE    100

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// All -> base (long long)
void all(long long num, int base, char arr[])
{
    int negative = (num < 0) ? 1 : 0;
    num = (negative) ? -num : num;

    int i = 1;
    while (num > 0){
        arr[SIZE - i] = alphabet[num % base];
        num /= base;
        i++;
    }

    if (negative)
        arr[SIZE - i] = '-';
    else
        i--;

    int j;
    for (j = 0; i > 0; j++, i--)
        arr[j] = arr[SIZE - i];
    
    arr[j] = '\0';
}

int main(void){
    const short a = -021561;
    const int b = 011306225024;
    const unsigned int c = 035671111240;
    const long d = -016462603530;
    const unsigned long e = 024117737606;

    char x_8[SIZE];
    char x[SIZE];

    all(a, 8, x_8);
    all(a, 4, x);
    printf("short %s=%s 4\n", x_8, x);
    
    all(b, 8, x_8);
    all(b, 20, x);
    printf("int %s=%s 20\n", x_8, x);
    
    all(c, 8, x_8);
    all(c, 17, x);
    printf("unsigned int %s=%s 17\n", x_8, x);
    
    all(d, 8, x_8);
    all(d, 27, x);
    printf("long %s=%s 27\n", x_8, x);
    
    all(e, 8, x_8);
    all(e, 9, x);
    printf("unsigned long %s=%s 9", x_8, x);

    return 0;
}