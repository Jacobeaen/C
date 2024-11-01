#include <stdio.h>

int main(void){

    printf("Integers:\n");
    printf("char: %d\nshort: %d\nint: %d\nlong: %d\nlong long: %d\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
    printf("char < short <= int <= long <= long long\n\n");
    printf("Floats:\n");
    printf("float: %d\ndouble: %d\nlong double: %d\n", sizeof(float), sizeof(double), sizeof(long double));
    printf("float <= double <= long double");

    return 0;
}