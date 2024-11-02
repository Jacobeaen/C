#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Book {
    char* name;
    char* author;
    int year;
    double price;
};

struct Book* expandArray(struct Book *array, int *capacity, bool *success)
{
    int new_capacity = *capacity * 2;
    struct Book *new_array = realloc(array, sizeof(struct Book) * new_capacity);

    *success = true;
    if (new_array == NULL){
        *success = false;
        return array;
    }
    *capacity = new_capacity;

    return new_array;
}


void setBookName(char *name)
{
    fgets(name, 29, stdin);
}

void setBook(char *name,
            char *author,
            int *year,
            double *price)
{
    printf("Name: ");
    fgets(name, 29, stdin);

    printf("Author: ");
    fgets(author, 29, stdin);

    printf("Year: ");
    scanf("%d", year);

    printf("Price: ");
    scanf("%lf", price);
}

void showMenu(char *menu[], int size)
{
    for (int i = 0; i < size; ++i){
        printf("%s\n", menu[i]);
    }
}

void freeBook(struct Book *book) {
    free(book->name);
    free(book->author);
}

void addBook(struct Book array[],
            int index,
            char *name,
            char *author,
            int year,
            double price,
            bool *in_library)
{
    for (int i = 0; i < index; ++i){
        struct Book book = array[i];

        // printf("name: %s, book_name: %s", name, book.name);
        if (strcmp(book.name, name) == 0){
            printf("Sorry, this book is already in your library!\n");
            *in_library = true;
            return ;
        }
    }

    struct Book book;

    book.name = malloc(strlen(name) + 1);
    book.author = malloc(strlen(author) + 1);

    strcpy(book.name, name);
    strcpy(book.author, author);
    book.year = year;
    book.price = price;

    array[index] = book;
}

void showBooks(struct Book *array, int size)
{
    if (!size){
        printf("Your library is empty\n");
        return ;
    }

    printf("Your library:\n");
    for (int i = 0; i < size; ++i){
        struct Book book = array[i];

        printf("%d: %s", i + 1, book.name);
    }
}

int findBook(struct Book *array, int size, char *book_name, bool get_index)
{
    
    if (!get_index)
        printf("Result:\n");

    for (int i = 0; i < size; ++i){
        struct Book book = array[i];

        if (strcmp(book.name, book_name) == 0){
            if (get_index)
                return i;

            printf("Book name: %s", book_name);
            printf("Book author: %s", book.author);
            printf("Book year: %d\n", book.year);
            printf("Book price: %.2lf\n", book.price);

            return 0;
        }
    }

    return -1;

}

struct Book* deleteBook(struct Book *array, char *name, int size, int del_index)
{
    struct Book *new_array = malloc(sizeof(struct Book) * (size - 1));

    if (new_array == NULL){
        printf("Sorry, can't delete book, try again");
        return array;
    }

    for (int i = 0; i < size; ++i){
        if (i == del_index){
            continue;        
        }

        new_array[i] = array[i];
    }

    free(array);
    array = new_array;

    return array;
}

int main()
{
    char *menu[] = {
        "Menu:",
        "1. Add book",
        "2. Show your books",
        "3. Find book by name",
        "4. Remove book by name",
        "5. Exit"
    };

    int capacity = 1;
    struct Book *array = malloc(sizeof(struct Book) * capacity);
    
    char choice = '_';

    char name[30];
    char author[30];
    int year;
    double price;

    int size = 0;
    char tmp = '1';

    bool success;
    bool is_deleted;

    showMenu(menu, 6);
    printf(">> ");

    while (scanf("%c", &choice) == 1 && choice != '5'){
        scanf("%c", &tmp);
        bool in_library = false;

        switch (choice){
            case '1':
                setBook(name, author, &year, &price);
                scanf("%c", &tmp);

                if (size >= capacity){
                    array = expandArray(array, &capacity, &success);
                    if (!success){
                        printf("Sorry, we can't dedicate more space for your books\n");
                        printf("Try again\n");
                        break;
                    }
                }

                addBook(array, size, name, author, year, price, &in_library);
                if (!in_library)
                    size++;

                break;

            case '2':

                printf("\n");
                showBooks(array, size);
                break;

            case '3':

                char book_name[30];
                if (size == 0){
                    printf("\n");
                    printf("Your library is empty\n");
                    break;
                }

                setBookName(book_name);
                printf("\n");
                int answer = findBook(array, size, book_name, false);
                
                if (answer == -1)
                    printf("Book isn't in your library\n");

                break;

            case '4':

                setBookName(book_name);

                int del_index = findBook(array, size, book_name, true);
                if (del_index == -1){
                    printf("This book isn't in your library\n");
                    break;
                }
                
                char sure[3];
                printf("Are you sure (y/n)?\n>> ");
                fgets(sure, sizeof(sure), stdin);

                if (strncmp(sure, "n", 1) == 0){
                    printf("Exit...\n");
                    break;
                }

                array = deleteBook(array, book_name, size, del_index);
                printf("Book deleted from your library\n");
                size--;

                break;

            default:
                printf("Sorry, incorrect choice!\nWrite number again.\n");
        }

        printf("\n");
        showMenu(menu, 6);
        printf(">> ");
    }

    printf("\nEnd of the programm...");

    return 0;
}