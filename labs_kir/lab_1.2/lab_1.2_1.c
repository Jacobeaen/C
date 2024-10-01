#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQ";
int quantity = 0;
int *ptr_quantity = &quantity;

// All -> 8 (long long)
char *eight(long long num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num8[10000];


    int i = 0;
    long long copy = fabs(num);
    while (copy > 0){
        last = copy % 8;

        num8[i] = alphabet[last];

        copy /= 8;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr8[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr8[j] = num8[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr8[j + 1] = arr8[j];
        }
        arr8[0] = '-';
    }
    
    char *ptr_arr_8 = arr8;
    return ptr_arr_8;

}

// a -> 4 (short)
char *four(short num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num4[10000];


    int i = 0;
    short copy = fabs(num);
    while (copy > 0){
        last = copy % 4;

        num4[i] = alphabet[last];

        copy /= 4;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr4[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr4[j] = num4[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr4[j + 1] = arr4[j];
        }
        arr4[0] = '-';
    }
    
    char *ptr_arr_4 = arr4;
    return ptr_arr_4;

}

// b -> 20 (int)
char *twenty(int num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num20[10000];


    int i = 0;
    int copy = fabs(num);
    while (copy > 0){
        last = copy % 20;

        num20[i] = alphabet[last];

        copy /= 20;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr20[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr20[j] = num20[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr20[j + 1] = arr20[j];
        }
        arr20[0] = '-';
    }
    
    char *ptr_arr_20 = arr20;
    return ptr_arr_20;

}


// c -> 17 (unsigned int)
char *seventeen(unsigned int num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num17[10000];


    int i = 0;
    unsigned copy = fabs(num);
    while (copy > 0){
        last = copy % 17;

        num17[i] = alphabet[last];

        copy /= 17;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr17[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr17[j] = num17[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr17[j + 1] = arr17[j];
        }
        arr17[0] = '-';
    }
    
    char *ptr_arr_17 = arr17;
    return ptr_arr_17;

}

// d -> 27 (long)
char *twenty7(long num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num27[10000];


    int i = 0;
    long copy = fabs(num);
    while (copy > 0){
        last = copy % 27;

        num27[i] = alphabet[last];

        copy /= 27;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr27[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr27[j] = num27[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr27[j + 1] = arr27[j];
        }
        arr27[0] = '-';
    }
    
    char *ptr_arr_27 = arr27;
    return ptr_arr_27;

}

// e -> 9 (unsigned long)
char *nine(unsigned long num){
    int last;
    bool negative = (num < 0);
    int plus = 0;
    char num9[10000];


    int i = 0;
    unsigned long copy = fabs(num);
    while (copy > 0){
        last = copy % 9;

        num9[i] = alphabet[last];

        copy /= 9;
        i++;
    }

    if (negative){
        plus = 1;
    }

    *ptr_quantity = i + plus;
    char arr9[*ptr_quantity];
    for (int j = 0; i >= 0; i--, j++){
        arr9[j] = num9[i - 1];
    }
    
    if (negative){
        for (int j = *ptr_quantity - 1; j >= 0; j--){
            arr9[j + 1] = arr9[j];
        }
        arr9[0] = '-';
    }
    
    char *ptr_arr_9 = arr9;
    return ptr_arr_9;

}

int main(void){
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

    ptr_a_8 = eight(a);
    printf("short %s=", ptr_a_8);
    ptr_a = four(a);
    printf("%s %d\n", ptr_a, 4);

    ptr_b_8 = eight(b);
    printf("int %s=", ptr_b_8);
    ptr_b = twenty(b);
    printf("%s %d\n", ptr_b, 20);

    ptr_c_8 = eight(a);
    printf("unsigned int %s=", ptr_a_8);
    ptr_c = seventeen(a);
    printf("%s %d\n", ptr_a, 17);

    ptr_d_8 = eight(d);
    printf("long %s=", ptr_d_8);
    ptr_d = twenty7(d);
    printf("%s %d\n", ptr_d, 27);
    
    ptr_e_8 = eight(e);
    printf("unsigned long %s=", ptr_e_8);
    ptr_e = nine(e);
    printf("%s %d", ptr_e, 9);
    
    return 0;
}
