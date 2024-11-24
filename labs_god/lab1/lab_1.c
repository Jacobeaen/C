#include <stdio.h>
#include <stdbool.h>

int main(void){
    int bit;
    long long arr[10];
    int i = 0;

    char a = 0;
    while (true){
        a = (a * 2) + 1; 

        a += 1;
        if (a < 0){
            bit++;
            arr[i] = a;
            break;
        }
        else if (a == 0){
            arr[i] = a;
            break;
        }
        a--;
        
        bit++;
    }
    i++;

    unsigned char b = 0;
    while (true){
        b = (b * 2) + 1; 

        b += 1;
        if (b < 0){
            arr[i] = b;
            break;
        }
        else if (b == 0){
            arr[i] = b;
            break;
        }
        b--;
    }
    i++;

    short c = 0; bit = 1;
    while (true){
        c = (c * 2) + 1; 

        c += 1;
        if (c < 0){
            arr[i] = c;
            break;
        }
        else if (c == 0){
            arr[i] = c;
            break;
        }
        c--;
    }
    i++;

    unsigned short d = 0;
    while (true){
        d = (d * 2) + 1; 

        d += 1;
        if (d < 0){
            arr[i] = d;
            break;
        }
        else if (d == 0){
            arr[i] = d;
            break;
        }
        d--;
    }
    i++;

    int e = 0;
    while (true){
        e = (e * 2) + 1; 

        e += 1;
        if (e < 0){
            arr[i] = e;
            break;
        }
        else if (e == 0){
            arr[i] = e;
            break;
        }
        e--;
    }
    i++;

    unsigned int f = 0;
    while (true){
        f = (f * 2) + 1; 
        f += 1;
        if (f < 0){
            arr[i] = f;
            break;
        }
        else if (f == 0){
            arr[i] = f;
            break;
        }
        f--;
    }
    i++;

    long g = 0;
    while (true){
        g = (g * 2) + 1; 

        g += 1;
        if (g < 0){
            arr[i] = g;
            break;
        }
        else if (g == 0){
            arr[i] = g;
            break;
        }
        g--;
    }
    i++;

    unsigned long o = 0;
    while (true){
        o = (o * 2) + 1; 

        o += 1;
        if (o < 0){
            arr[i] = o;
            break;
        }
        else if (o == 0){
            arr[i] = o;
            break;
        }
        o--;
    }
    i++;


    long long j = 0;
    while (true){
        j = (j * 2) + 1; 

        j += 1;
        if (j < 0){
            arr[i] = j;
            break;
        }
        else if (j == 0){
            arr[i] = j;
            break;
        }
        j--;
        
        bit++;
    }
    i++;

    unsigned long long k = 0;
    while (true){
        k = (k * 2) + 1; 

        k += 1;
        if (k < 0){
            arr[i] = k;
            break;
        }
        else if (k == 0){
            arr[i] = k;
            break;
        }
        k--;
    }    
    
    
    printf("char: %hhd, %hhd\n", arr[0], arr[0] - 1);
    printf("unsigned char: %hhu, %hhu\n\n", arr[1], arr[1] - 1);

    printf("short: %hd, %hd\n", arr[2], arr[2] - 1);
    printf("unsigned short: %hu, %hu\n\n", arr[3], arr[3] - 1);

    printf("int bytes: %d, %d\n", arr[4], arr[4] - 1);
    printf("unsigned int: %u, %u\n\n", arr[5], arr[5] - 1);

    printf("long: %ld, %ld\n", arr[6], arr[6] - 1);
    printf("unsigned long: %lu, %lu\n\n", arr[7], arr[7] - 1);
    
    printf("long long: %lld, %lld\n", arr[8], arr[8] - 1);
    printf("unsigned long long: %llu, %llu", arr[9], arr[9] - 1);

    
    return 0;
}