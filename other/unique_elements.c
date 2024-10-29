#include <stdio.h>

int main(void){

    int length;
    scanf("%d", &length);
    
    int num[length];
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &num[i]);
    }

    int count = 0;
    int unique_elements[length];
    int flag;
    for(int i = 0; i < length; i++){
        flag = 1;
        for(int j = 0; j < count; j++){
            if (unique_elements[j] == num[i]){
                flag = 0;
                break;
            }
        }

        if (flag){
            unique_elements[count] = num[i];
            count += 1;
        }
    }
    printf("%d\n", count);


    return 0;
}
