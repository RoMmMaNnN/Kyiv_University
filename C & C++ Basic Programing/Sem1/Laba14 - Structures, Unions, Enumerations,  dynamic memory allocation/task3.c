#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_LEN 100

typedef struct {
    char author[MAX_LEN];
    char title[MAX_LEN];
    int year;
    int pages;
    float price;
} Book;

void addBook(Book *book);
void showLibrary(Book *books, int count);
void colWidth(Book *books, int count, int *wideWidth, int *narrowWidth);
void printTopSeparators(int wideWidth, int narrowWidth);
void printCellSeparators(int wideWidth, int narrowWidth);
void printBottomSeparators(int wideWidth, int narrowWidth);
void continueProgram(char* choice);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    char choice;

    do {
        addBook(&books[count]);
        count++;
        showLibrary(books, count);
        continueProgram(&choice);
    } while (choice == '+' && count < MAX_BOOKS);

    return 0;
}

void addBook(Book *book) {
    printf("Enter book's author: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter book's title: ");
    fgets(book->title, sizeof(book->title), stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Enter year of publication this book: ");
    while (scanf("%d", &book->year) != 1) {
        printf("Invalid input. Please enter a positive integer for the year: ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    printf("Enter number of pages in your book: ");
    while (scanf("%d", &book->pages) != 1 || book->pages <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of pages: ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    printf("Enter book price: ");
    while (scanf("%f", &book->price) != 1 || book->price < 0) {
        printf("Invalid input. Please enter a non-negative number for the price: ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n');
}

void showLibrary(Book *books, int count) {
    int wideWidth, narrowWidth;

    colWidth(books, count, &wideWidth, &narrowWidth);

    printTopSeparators(wideWidth, narrowWidth);

    printf("│  %-*s  │  %-*s  │  %-*s  │  %-*s  │  %-*s  │", wideWidth, "Author", wideWidth, "Title", narrowWidth, "Year", narrowWidth, "Pages", narrowWidth, "Price");

    printCellSeparators(wideWidth, narrowWidth);

    for (int i = 0; i < count; i++) {
        printf("│  %-*s  │  %-*s  │  %-*d  │  %-*d  │  %-*.2f  │\n", wideWidth, books[i].author, wideWidth, books[i].title, narrowWidth, books[i].year, narrowWidth, books[i].pages, narrowWidth, books[i].price);
    }

    printBottomSeparators(wideWidth, narrowWidth);
}

void colWidth(Book *books, int count, int *wideWidth, int *narrowWidth) {
    int maxLenWideWidth, maxLenNarrowWidth;
    *wideWidth = 15;
    *narrowWidth = 7;

    for (int i = 0; i < count; i++) {
        maxLenWideWidth = strlen(books[i].author);
        maxLenNarrowWidth = strlen(books[i].title);

        if (maxLenWideWidth > *wideWidth) {
            *wideWidth = maxLenWideWidth;
        }

        if (maxLenNarrowWidth > *narrowWidth) {
            *narrowWidth = maxLenNarrowWidth;
        }
    }
}

void printTopSeparators(int wideWidth, int narrowWidth) {
    printf("\n┌");
    for (int i = 0; i < 5; i++) {
        if(i < 2) {
            for (int j = 1; j <= wideWidth + 4; j++) printf("─");
        } else {
            for (int j = 1; j <= narrowWidth + 4; j++) printf("─");
        }
        if (i != 4) printf("┬");
    }
    printf("┐\n");
}

void printCellSeparators(int wideWidth, int narrowWidth) {
    printf("\n├");
    for (int i = 0; i < 5; i++) {
        if(i < 2) {
            for (int j = 1; j <= wideWidth + 4; j++) printf("─");
        } else {
            for (int j = 1; j <= narrowWidth + 4; j++) printf("─");
        }
        if (i != 4) printf("┼");
    }
    printf("┤\n");
}

void printBottomSeparators(int wideWidth, int narrowWidth) {
    printf("└");
    for (int i = 0; i < 5; i++) {
        if(i < 2) {
            for (int j = 1; j <= wideWidth + 4; j++) printf("─");
        } else {
            for (int j = 1; j <= narrowWidth + 4; j++) printf("─");
        }
        if (i != 4) printf("┴");
    }
    printf("┘\n");
}

void continueProgram(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-': ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}
