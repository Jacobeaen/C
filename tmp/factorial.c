#include <stdio.h>

long long fact(int num)
{
    long long count = 1;
    while (num > 0){
        count *= num--;
    }
    
    return count;
}

int main(void)
{
    int number;
    scanf("%d", &number);
    
    printf("Factorial of %d: %d", number, fact(number));
    

    return 0;
}