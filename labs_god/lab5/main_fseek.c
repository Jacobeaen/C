#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void delSpace(char *);
bool check_word(FILE *file1, FILE *file3);
void change(FILE *file1, FILE *file2, FILE *file3, FILE *file4);
void get_next_word(FILE *file);
void get_next_f1_word(FILE *file_in, FILE *file_out);
void print_unchanged_word(FILE *file_in, FILE *file_out);
void print_changed_word(FILE *words2, FILE *file_out);
void print_char(FILE *file);

int begin_pos;
int pos_in, pos1;
int word_num;

bool end_of_file2 = false;
bool end_of_file1 = false;
bool match; 

int main(int argc, char **argv){

    if (argc != 5){
        puts("Invalid amount of paremetrs");
        return 0;
    }

    FILE *file_in = fopen(argv[1], "r");
    FILE *words1 = fopen(argv[2], "r");
    FILE *words2 = fopen(argv[3], "r");
    FILE *file_out = fopen(argv[4], "w");

    // FILE *file_in = fopen("file_in.txt", "r");
    // FILE *words1 = fopen("words1.txt", "r");
    // FILE *words2 = fopen("words2.txt", "r");
    // FILE *file_out = fopen("e.txt", "w");

    while (true){
        char symbol = fgetc(file_in);
        begin_pos++;

        if (isalpha(symbol))
            break;

        putc(symbol, file_out);
    }
    
    begin_pos--;
    fseek(file_in, -1, SEEK_CUR);

    change(file_in, words1, words2, file_out);

    return 0;
}

// Собственно основная функция замены
void change(FILE *file1, FILE *file2, FILE *file3, FILE *file4){
    while (!end_of_file1){
        /* На этом моменте при вызове fgets для file_in будет либо самый первый символ file_in,
        либо первый символ какого-то слова в file_in */

        match = false;

        // Индекс слова в words1/words2
        word_num = -1;        

        // Ищем совпадение между словом и словами из words1
        while (!match && !end_of_file2){
            match = check_word(file1, file2);

            // 0 - номер первого слова в words2 и т.д.
            word_num++;
            if (match)
                break;

            // Если не совпало, возвращаем каретку к исходному слову
            fseek(file1, begin_pos, SEEK_SET);
            pos1 = begin_pos;
        }
        /* После завершения pos1 указывает на:
        Пробельный символ после слова, если слово найдено
        ВСЕГДА, так как делается проверка после конца words1
        begin_pos - на начало слова */

        // Приводим words2 в начальное состояние
        rewind(file2);
        end_of_file2 = false;

        // Если нашли совпадение - печатаем слово из words2
        if (match){
            // Если совпало, то pos1 - это следующий пробельный символ после слова,
            // те при вызове getc мы теряем пробел, поэтому pos - 1
            fseek(file1, -1, SEEK_CUR);
            begin_pos = pos1 - 1;

            print_changed_word(file3, file4);
            rewind(file3);
            get_next_f1_word(file1, file4);
        }

        // Если не нашли - просто переходим к новому слову
        else{
            print_unchanged_word(file1, file4);
            get_next_f1_word(file1, file4);

            // Если не совпало, то pos1 - gthds
            pos1 = begin_pos;
        }
    }
}

// Получаем новое слово (для файлов words)
void get_next_word(FILE *file){
    char symbol;
    while (true){
        symbol = fgetc(file);

        if (symbol == '\n')
            break;
            
        if (symbol == EOF){
            end_of_file2 = true;
            break;
        }
    }
        
}

// Принтуем слово, если оно не заменяется.
void print_unchanged_word(FILE *file_in, FILE *file_out){
    char symbol;
    while (true){
        symbol = fgetc(file_in);
        begin_pos++;

        if (symbol == EOF)
            exit(0);

        if (isspace(symbol))
            break;

        putc(symbol, file_out);

    }

    begin_pos--;
    fseek(file_in, -1, SEEK_CUR);
}

// Принтуем слово, если оно заменяется
void print_changed_word(FILE *words2, FILE *file_out){
    
    char symbol;
    int count = 0;

    if (word_num == 0){
        while ((symbol = fgetc(words2)) != '\n')
            putc(symbol, file_out);
    }

    else{
        while (count < word_num){
            symbol = fgetc(words2);

            if (symbol == '\n')
                count++;
        }

        while (true){
            symbol = fgetc(words2);

            if (symbol == EOF || symbol == '\n')
                return;

            putc(symbol, file_out);
        }
    }
    begin_pos++;
}

// Переходим к следующему слову в file_in (между словами много пробельных символов)
void get_next_f1_word(FILE *file_in, FILE *file_out){
    char symbol;

    while (true){
        symbol = fgetc(file_in);
        begin_pos++;

        if (symbol == EOF)
            exit(0);

        if (symbol == '\n'){
            begin_pos++;
        }

        if (isalpha(symbol))
            break;

        putc(symbol, file_out);

    }

    /* Откатываемся назад, чтобы при вызове fgetc для file_in
    мы получали первый символ следующего слова*/

    begin_pos--;
    fseek(file_in, -1, SEEK_CUR);
}

// Проверяем совпадение слова
bool check_word(FILE *file1, FILE *file2){
    
    char symbol1 = fgetc(file1);
    pos1++;
    char symbol2 = fgetc(file2);
    

    // Условия выхода из цикла прописаны в конце тела цикла
    while (true){
        if (symbol1 != symbol2){

            // Если был достигнут конец words2, то соответствующая переменная стоит
            get_next_word(file2);

            // Проверяем на конец file_in
            if (end_of_file2){
                char check_for_end_f1;
                while (true){
                    check_for_end_f1 = fgetc(file1);
                    pos1++;

                    // Если дошли до конца слова, возвращаем каретку, чтобы при fgetc был пробел после слова
                    if (isspace(check_for_end_f1)){
                        pos1--;
                        fseek(file1, -1, SEEK_CUR);
                        return false;
                    }

                    if (check_for_end_f1 == EOF){
                        end_of_file1 = true;
                        return false;
                    }
                }
            }
            
            return false;
        }

        symbol1 = fgetc(file1);
        pos1++;
        symbol2 = fgetc(file2);


        if (!isalpha(symbol1)){
            if (symbol2 == EOF || symbol2 == '\n'){
                end_of_file2 = true;
                return true;
            }
            return false;
        }

        // Если конец file_in
        if (symbol1 == EOF){
            end_of_file1 = true;
            if (symbol2 == '\n' || symbol2 == EOF)
                return true;
            return false;
        }

        // Если конец файла words2
        if (symbol2 == EOF){
            end_of_file2 = true;
            
            if (isspace(symbol1) || symbol1 == EOF)
                return true;
            return false;
        }

        // Если конец слова из file_in, но не конец слова из words2
        if (isspace(symbol1) && symbol2 != '\n'){
            while (true){
                symbol2 = fgetc(file2);
                if (symbol2 == '\n')
                    return false;
                if (symbol2 == EOF){
                    end_of_file2 = true;
                    return false;
                }
            }
        }

        // Если конец слова в words2
        if (symbol2 == '\n'){
            if (!isalpha(symbol1))
                return true;
            return false;
        }
    }
}

// Удаляем \n после fgets
void delSpace(char *string){
    int i = 0;
    while (string[i] != '\n'){
        if (string[i] == EOF)
            return;
        i++;
    }
    string[i] = '\0';
}
