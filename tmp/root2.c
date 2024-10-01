#include <stdio.h>
#include <stdlib.h>

#define TOL 0.01  // точность

double sqrt2(double x)
{
    double y = 1.0;
    while (fabs(x / y - y) > TOL )
        y = (y + x / y) / 2.0;
        
    return y;
}

int main(void){

    int x;
    scanf("%d", &x);

    printf("%lf", sqrt2(x));
}