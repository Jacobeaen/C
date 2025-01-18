#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

void removeComments(FILE *input, FILE *output)
{
    int in_string = 0;
    int in_char = 0;
    int in_comment = 0;
    int single_line = 0;
    int previous_symbol = 0;
    int current_symbol;
    int flag = 0;

    while ((current_symbol = fgetc(input)) != EOF)
    {
        if (in_comment)
        {
            // Если однострочный
            if (single_line){
                if (current_symbol == '\n'){
                    if (previous_symbol != '\\'){
                        in_comment = 0;
                        single_line = 0;
                    }
                    
                    fputc(current_symbol, output);
                }
            }

            // Если многострочный
            else{
                flag++; 
                // Ищем */ 
                if (previous_symbol == '*' && current_symbol == '/')
                {
                    if (flag > 1){
                        in_comment = 0;
                        previous_symbol = '~';
                        continue;
                    }
                    // fseek(input, -1, SEEK_CUR);
                    // fputc('Q', input);
                }
            }
        }

        // Если в "" или ''
        else if (in_string || in_char){
            fputc(current_symbol, output);

            if (current_symbol == '\\'){ // \'
                // Например \' -  пропустим кавычку и cur_s = ?, prev_s \ 
                fputc(fgetc(input), output);
            }

            else if ((current_symbol == '"' && in_string) || (current_symbol == '\'' && in_char)){
                if (in_string)
                    in_string = 0;
                if (in_char)
                    in_char = 0;
            }
        }

        else
        {
            if (previous_symbol == '/' && current_symbol == '/'){
                in_comment = 1;
                single_line = 1;
                fseek(output, -1, SEEK_CUR);
                putc(' ', output);
            }
            else if (previous_symbol == '/' && current_symbol == '*'){
                flag = 0;
                in_comment = 1;
                single_line = 0;
                fseek(output, -1, SEEK_CUR);
                putc(' ', output);
            }
            else{
                if (current_symbol == '"')
                    in_string = 1;
                else if (current_symbol == '\'')
                    in_char = 1;
                fputc(current_symbol, output);
            }
        }
        previous_symbol = current_symbol;
    }
    // while
}

void delete_space(char array[])
{
    int i = 0;
    while (array[i] != '\n')
        i++;

    array[i] = '\0';
}

int main(void)
{

    FILE *project = fopen("project.txt", "r");
    
    // Получаем число файлов и убираем \n
    int files_amount;
    char number[LEN];
    fgets(number, LEN, project);
    files_amount = atoi(number);

    //printf("%d\n", files_amount);

    for (int i = 0; i < files_amount; ++i){
        char filename_c[LEN] = {0};
        char filename_wc[LEN] = {0};

        fgets(filename_c, LEN, project);
        if (i != files_amount - 1)
            delete_space(filename_c);

        
        int length = strlen(filename_c);
        strcat(filename_wc, filename_c);
        filename_wc[length - 1] = 'w';
        filename_wc[length] = 'c';
        filename_wc[length + 1] = '\0';

        FILE *c_file = fopen(filename_c, "r");
        FILE *wc_file = fopen(filename_wc, "w");

        removeComments(c_file, wc_file);

        fclose(c_file);
        fclose(wc_file);
    }

    return 0;
}