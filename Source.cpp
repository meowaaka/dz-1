#include <iostream>
using namespace std;

#include "book.h"
#include "Header.h"

int main() {
    uint SIZE;
    cout << "Enter number of books: ";
    cin >> SIZE;

    Book* books = new Book[SIZE];

    for (uint i = 0; i < SIZE; i++)
    {
        cout << "\n--- Create book " << i + 1 << " ---\n";
        books[i] = createBook();
    }

    printBooks(books, SIZE);
    searchBook(books, SIZE);

    for (uint i = 0; i < SIZE; i++)
        delete[] books[i].title;
    delete[] books;

    return 0;
}
