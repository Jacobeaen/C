#include <stdio.h>

#define SIZE    24
#define COORD_LEN

enum vs2010isbad {
    got_solutions = 1,
    attack = 1,
    clean = 0,
    not_attack = -1,
    solution = 123 
};

struct Cell {
    int x;
    int y;
};

FILE *file_in;
FILE *file_out;

int board_size;
int amount_to_place;
int amount_on_table;
int need_to_place;
int have_solutions;

// 0 - свободно
// 1 и больше - занято
int board[SIZE][SIZE];

void printBoard();
void printSolution();
int inBoard(int x, int y);
void placeKing(struct Cell coords, int action);
void get_a_try(int x, int y, int placed);

int main(void)
{
    FILE *file_in = fopen("input.txt", "r");
    fscanf(file_in, "%d %d %d", &board_size, &amount_to_place, &amount_on_table);

    need_to_place = amount_to_place + amount_on_table;

    for (int i = 0; i < amount_on_table; i++){
        struct Cell coords;

        fscanf(file_in, "%d %d", &coords.x, &coords.y);
        placeKing(coords, attack);   
    }

    //printBoard();

    file_out = fopen("output.txt", "w");
    get_a_try(0, 0, amount_on_table);

    if (!have_solutions)
        fprintf(file_out, "no solutions");
    
    fclose(file_in);
    fclose(file_out);

    return 0;
}

int inBoard(int x, int y){
    return x >= 0 && y >= 0 && x < board_size && y < board_size;
}

// Правильно!!
void placeKing(struct Cell coords, int action){
    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){

            int attacked_x = coords.x + x;
            int attacked_y = coords.y + y;

            if (inBoard(attacked_x, attacked_y))
            {
                if (attacked_x == coords.x && attacked_y == coords.y){
                    if (action == attack)
                        board[coords.x][coords.y] = solution;
                    else
                        board[coords.x][coords.y] = clean;
                }

                else
                    board[attacked_x][attacked_y] += action;
            }
        }
    }
}

void printSolution(){
    for (int rows = 0; rows < board_size; rows++){
        for (int columns = 0; columns < board_size; ++columns){
            if (board[rows][columns] == solution)
                fprintf(file_out, "(%d,%d) ", rows, columns);
        
        }
    }

    fputc('\n', file_out);
}

void printBoard(){
    for (int x = 0; x < board_size; ++x){
        for (int y = 0; y < board_size; y++){
            printf("%3d ", board[x][y]);
        }

        puts("");
    }
}

void get_a_try(int x, int y, int placed){
    if (placed == need_to_place){
        printSolution();
        have_solutions = got_solutions;

        // 1. Убирается последний король и пробуется следующий вариант
        // Если сл вар не подходит - пункт 1 и тд
        return;
    }

    for (; x < board_size; x++, y = 0){
        for (; y < board_size; y++){
            if (board[x][y] == 0){
                struct Cell coords = {x, y};

                placeKing(coords, attack);
                // printBoard();
                // puts("");
                get_a_try(x, y, placed + 1);
                placeKing(coords, not_attack);
            }
        }
    }
}
