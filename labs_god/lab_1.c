#include <stdio.h>
#include <stdbool.h>

int main(void){
    int byte;
    int arr[10];
    int i = 0;

    printf("\033[2J]");
    printf("SHORT\n");
    char a = 0; byte = 1;
    while (true){
        a = (a * 2) + 1; 
        printf("number: %hhd  byte: %d\n", a, byte);

        a += 1;
        if (a < 0){
            byte++;
            printf("number: %hhd  byte: %d\n\n", a, byte);
            arr[i] = byte;
            break;
        }
        else if (a == 0){
            arr[i] = byte;
            break;
        }
        a--;
        
        byte++;
    }
    i++;

    printf("UNSIGNED SHORT\n");
    unsigned char b = 0; byte = 1;
    while (true){
        b = (b * 2) + 1; 
        printf("number: %hhu  byte: %d\n", b, byte);

        b += 1;
        if (b < 0){
            byte++;
            arr[i] = byte;
            break;
        }
        else if (b == 0){
            arr[i] = byte;
            break;
        }
        b--;
        
        byte++;
    }
    printf("\n");
    i++;

    printf("SHORT\n");
    short c = 0; byte = 1;
    while (true){
        c = (c * 2) + 1; 
        printf("number: %hd  byte: %d\n", c, byte);

        c += 1;
        if (c < 0){
            byte++;
            printf("number: %hd  byte: %d\n\n", c, byte);
            arr[i] = byte;
            break;
        }
        else if (c == 0){
            arr[i] = byte;
            break;
        }
        c--;
        
        byte++;
    }
    i++;

    printf("UNSIGNED SHORT\n");
    unsigned short d = 0; byte = 1;
    while (true){
        d = (d * 2) + 1; 
        printf("number: %hu  byte: %d\n", d, byte);

        d += 1;
        if (d < 0){
            byte++;
            arr[i] = byte;
            break;
        }
        else if (d == 0){
            arr[i] = byte;
            break;
        }
        d--;
        
        byte++;
    }
    printf("\n");
    i++;

    printf("INT\n");
    int e = 0; byte = 1;
    while (true){
        e = (e * 2) + 1; 
        printf("number: %d  byte: %d\n", e, byte);

        e += 1;
        if (e < 0){
            byte++;
            printf("number: %d  byte: %d\n\n", e, byte);
            arr[i] = byte;
            break;
        }
        else if (e == 0){
            arr[i] = byte;
            break;
        }
        e--;
        
        byte++;
    }
    i++;

    printf("UNSIGNED INT\n");
    unsigned int f = 0; byte = 1;
    while (true){
        f = (f * 2) + 1; 
        printf("number: %u  byte: %d\n", f, byte);

        f += 1;
        if (f < 0){
            byte++;
            arr[i] = byte;
            break;
        }
        else if (f == 0){
            arr[i] = byte;
            break;
        }
        f--;
        
        byte++;
    }
    printf("\n");
    i++;

    printf("LONG\n");
    long g = 0; byte = 1;
    while (true){
        g = (g * 2) + 1; 
        printf("number: %ld  byte: %d\n", g, byte);

        g += 1;
        if (g < 0){
            byte++;
            printf("number: %ld  byte: %d\n", g, byte);
            arr[i] = byte;
            break;
        }
        else if (g == 0){
            arr[i] = byte;
            break;
        }
        g--;
        
        byte++;
    }
    i++;
    printf("\n");

    printf("UNSIGNED LONG\n");
    unsigned long o = 0; byte = 1;
    while (true){
        o = (o * 2) + 1; 
        printf("number: %lu  byte: %d\n", o, byte);

        o += 1;
        if (o < 0){
            arr[i] = byte;
            byte++;
            break;
        }
        else if (o == 0){
            arr[i] = byte;
            break;
        }
        o--;
        
        byte++;
    }
    printf("\n");
    i++;


    printf("LONG LONG\n");
    long long j = 0; byte = 1;
    while (true){
        j = (j * 2) + 1; 
        printf("number: %lld  byte: %d\n", j, byte);

        j += 1;
        if (j < 0){
            byte++;
            printf("number: %lld  byte: %d\n\n", j, byte);
            arr[i] = byte;
            break;
        }
        else if (j == 0){
            arr[i] = byte;
            break;
        }
        j--;
        
        byte++;
    }
    i++;

    printf("UNSIGNED LONG LONG\n");
    unsigned long long k = 0; byte = 1;
    while (true){
        k = (k * 2) + 1; 
        printf("number: %llu  byte: %d\n", k, byte);

        k += 1;
        if (k < 0){
            arr[i] = byte;
            byte++;
            break;
        }
        else if (k == 0){
            arr[i] = byte;
            break;
        }
        k--;
        
        byte++;
    }
    printf("\n");
    
    
    
    printf("short bytes: %d\n", arr[0]);
    printf("unsigned short bytes: %d\n\n", arr[1]);

    printf("char bytes: %d\n", arr[2]);
    printf("unsigned char bytes: %d\n\n", arr[3]);

    printf("int bytes: %d\n", arr[4]);
    printf("unsigned int bytes: %d\n\n", arr[5]);

    printf("long bytes: %d\n", arr[6]);
    printf("unsigned long bytes: %d\n\n", arr[7]);
    
    printf("long long bytes: %d\n", arr[8]);
    printf("unsigned long long bytes: %d", arr[9]);
    return 0;
}
    
    
