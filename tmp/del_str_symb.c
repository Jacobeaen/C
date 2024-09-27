#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void strip_str(char *str, char *del)
{
    bool delete;
    int i = 0;
    while (str[i] != '\0'){
        //printf("\n\nstr[%d] = %c\n", i, str[i]);
        delete = false;
        
        int j = 0;
        while (del[j] != '\0'){
            //printf("del[%d] = %c\n", j, del[j]);
            if (str[i] == del[j]){
                delete = true;
                break;
            }
            j++;
        }
        
        if (delete){
            if (str[i + 1] == '\0')
                str[i] = '\0';
            else
                str[i] = str[i + 1];
        }
    i++;
    }
}


int main(void)
{
    char str[100] = "Hello, World!";
    char str2[20] = ".,-!?";
    
    strip_str(str, str2);
    
    printf("%s", str);

    return 0;
}