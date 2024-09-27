#include <stdio.h>
#include <string.h>

#define SIZE    1000

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// All -> base (long long)
char* all(long long num, int base, char arr[])
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
    
    return arr;
}

int main(void){
    const short a = -021561;
    const int b = 011306225024;
    const unsigned int c = 035671111240;
    const long d = -016462603530;
    const unsigned long e = 024117737606;

    char a_8_arr[SIZE];
    char a_4_arr[SIZE];
    
    char b_8_arr[SIZE];
    char b_20_arr[SIZE];
    
    char c_8_arr[SIZE];
    char c_17_arr[SIZE];
    
    char d_8_arr[SIZE];
    char d_27_arr[SIZE];
    
    char e_8_arr[SIZE];
    char e_9_arr[SIZE];


    char *a_8 = all(a, 8, a_8_arr);
    char *a_4 = all(a, 4, a_4_arr);
    printf("short %s=%s 4\n", a_8, a_4);
    
    char *b_8 = all(b, 8, b_8_arr);
    char *b_20 = all(b, 20, b_20_arr);
    printf("int %s=%s 20\n", b_8, b_20);
    
    char *c_8 = all(c, 8, c_8_arr);
    char *c_17 = all(c, 17, c_17_arr);
    printf("unsigned int %s=%s 17\n", c_8, c_17);
    
    char *d_8 = all(d, 8, d_8_arr);
    char *d_27 = all(d, 27, d_27_arr);
    printf("long %s=%s 27\n", d_8, d_27);
    
    char *e_8 = all(e, 8, e_8_arr);
    char *e_9 = all(e, 9, e_9_arr);
    printf("unsigned long %s=%s 9", e_8, e_9);


    return 0;
}