#include <stdio.h>
#include <string.h>

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQ";

// All -> base (long long)
char *all(long long num, int base, char *ptr_num_arr, char *ptr_arr){
    int negative = (num < 0) ? 1 : 0;
    
    int i = 0;
    long long copy = (num > 0) ? num : -num;
    while (copy > 0){
        ptr_num_arr[1000 - i] = alphabet[copy % base];

        copy /= base;
        i++;
    }

    if (negative)
        ptr_num_arr[1000 - i] = '-';

    int j;
    for (j = 0; i >= 0; i--, j++){
        ptr_arr[j] = ptr_num_arr[1000 - i];
    }
    
    ptr_arr[j] = '\0';
    
    return ptr_arr;

}

int main(void){
    char num_arr[1000];
    char arr[1000];

    char *ptr_num_arr = num_arr;
    char *ptr_arr = arr;

    const short a = -021561;
    const int b = 011306225024;
    const unsigned int c = 035671111240;
    const long d = -016462603530;
    const unsigned long e = 024117737606;

    char *ptr_a_8;
    char *ptr_b_8;
    char *ptr_c_8;
    char *ptr_d_8;
    char *ptr_e_8;

    char *ptr_a;
    char *ptr_b;
    char *ptr_c;
    char *ptr_d;
    char *ptr_e;


    ptr_a_8 = all(a, 8, ptr_num_arr, ptr_arr);
    ptr_a = all(a, 4, ptr_num_arr, ptr_arr);

    printf("%s", ptr_a);
    
    return 0;
}
