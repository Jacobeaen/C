#include <stdio.h>

int main(void){

    printf("char: %d\nshort: %d\nint: %d\nlong: %d\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long));
    printf("long long: %d\nfloat: %d\ndouble: %d\nlong double: %d\n", sizeof(long long), sizeof(float), sizeof(double), sizeof(long double));
    printf("short <= int <= long <= long long\nfloat <= double <= long double");

    return 0;
}