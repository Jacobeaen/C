#include <stdio.h>

int fact(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    
    return n * fact(n - 1);

}

int main(void)
{
    int n = 5;
    printf("%d", fact(n));

    return 0;
}