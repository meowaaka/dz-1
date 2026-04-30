#include <iostream>
using namespace std;

#include "book.h"
#include "Header.h"

int main() {
    const unsigned int SIZE = 3;

    Book books[SIZE];

    for (unsigned int i = 0; i < SIZE; i++)
    {
        cout << "\n--- Create book " << i + 1 << " ---\n";
        books[i] = createBook();
    }

    printBooks(books, 3);

    searchBook(books, SIZE);

    for (int i = 0; i < 3; i++)
        delete[] books[i].title;

    return 0;
}
