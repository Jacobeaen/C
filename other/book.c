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

    printf("\n");
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
            printf("Sorry, this book is already in your library!\n\n");
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
        printf("Your library is empty\n\n");
        return ;
    }

    printf("Your library:\n");
    for (int i = 0; i < size; ++i){
        struct Book book = array[i];

        printf("%d: %s", i + 1, book.name);
    }
}

void findBook(struct Book *array, int size, char *book_name)
{
    printf("Your library:\n");
    for (int i = 0; i < size; ++i){
        struct Book book = array[i];

        if (!strcmp(book.name, book_name)){
            printf("Book name: %s", book_name);
            printf("Book author: %s", book.author);
            printf("Book year: %d\n", book.year);
            printf("Book price: %lf\n", book.price);

            break;
        }
    }
}

void deleteBook(struct Book *array)
{

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

    struct Book *array = malloc(sizeof(struct Book) * 5);
    
    char choice = '_';
    char name[30];
    char author[30];
    int year;
    double price;

    int i = 0;
    char tmp = '1';
    

    showMenu(menu, 6);
    printf(">> ");

    while (scanf("%c", &choice) == 1 && choice != '5'){
        scanf("%c", &tmp);
        bool in_library = false;

        switch (choice){
            case '1':
                setBook(name, author, &year, &price);
                scanf("%c", &tmp);

                addBook(array, i, name, author, year, price, &in_library);
                if (!in_library)
                    i++;

                break;
            case '2':
                showBooks(array, i);
                break;
            case '3':
                char book_name[30];
                if (i == 0){
                    printf("Your library is empty\n\n");
                    break;
                }

                setBookName(book_name);
                findBook(array, i, book_name);
                break;
            case '4':
                printf("This func will be added soon!\n");
                break;
            default:
                printf("Sorry, incorrect choice!\nWrite number again.\n\n");
        }

        showMenu(menu, 6);
        printf(">> ");
    }

    printf("\nEnd of the programm...");

    return 0;
}