#include <stdio.h>
#include <string.h>

int main(void){

    int num10 = 183;
    int num8 = 0267;
    int num2 = 0b10110111;
    int num16 = 0xB7;

    long long x = 34;
    long long *ptr = &x;
    long long y = (long long)&x;

   char a[100] = "ghjklljhgj";

   int len = strlen(a); 
   printf("%d", len);

    return 0;
}