#include <stdio.h>

long long pow(n, power)
{
    if (power == 0)
        return 1;
    else if (power == 1)
        return n;
    
    for (int i = 0; i < power; ++i){
        n *= n;
    }

    return n;
}

long long factorial(n)
{
    long long count = 1;
}

long double func(n)
{
    long double res;

}

long double sum_series(n)
{
    unsigned int count = 0;

}


int main(void)
{
    unsigned int n;
    scanf("%u", &n);



    return 0;
}