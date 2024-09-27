#include <stdio.h>

#define SIZE_BUFFER     10

int main(void)
{
    int buffer[SIZE_BUFFER];
    size_t count = 0;
    size_t sz_ar = sizeof(buffer) / sizeof(*buffer);

    while(count < sz_ar && scanf("%d", &buffer[count]) == 1)
        count++;
    
  
    int start = 0;
    int tmp;
    for (int i = count / 2; i > 0; start++, i--){
        tmp = buffer[start];
        buffer[start] = buffer[count - 1 - start];
        buffer[count - 1 - start] = tmp;
    }

    for (int j = 0; j < count; j++){
        printf("%d ", buffer[j]);
    }
    return 0;
}