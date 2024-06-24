#include <stdio.h>
#include <string.h>

typedef struct Book {
    char title[50];
    char author[50];
    float price;
    int pages;
} Book;

int main (int) {
    Book book = {
        .title = "Harry Potter and the Fiery Stone",
        .author = "JK Rowling",
        .price = 10000,
        .pages = 5
    };

    printf("title is: %s, author is %s\n", book.title, book.author);

    strcpy(book.title, "hi");
    strcpy(book.author, "hello world");

    printf("title is: %s, author is %s\n", book.title, book.author);
}