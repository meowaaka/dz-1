const unsigned int N = 30;

void printBook(const Book& bk) {
    cout << "-----------------------------\n";
    cout << "ID: " << bk.Id << endl;
    cout << "Title: " << bk.title << endl;
    cout << "Pages: " << bk.pages << endl;
    cout << "Price: " << bk.price << endl;
    cout << "-----------------------------\n";
}

Book createBook() {
    static unsigned int id = 1000;
    Book book;
    book.Id = id++;

    char t[N];
    cout << "Enter title - ";
    cin.ignore();
    cin.getline(t, N);
    book.title = new char[strlen(t) + 1];
    strcpy_s(book.title, strlen(t) + 1, t);

    cout << "Enter pages - ";
    cin >> book.pages;

    cout << "Enter price - ";
    cin >> book.price;

    return book;
}

void printBooks(Book* books, unsigned int size) {
    cout << "\nEveryone books:\n";
    for (unsigned int i = 0; i < size; i++) {
        printBook(books[i]);
    }
}

Book* findBookByTitle(Book* books, unsigned int size, const char* title) {
    for (unsigned int i = 0; i < size; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return nullptr;
}

void searchBook(Book* books, unsigned int size)
{
    char searchTitle[N];
    cout << "\nEnter title to find: ";
    cin.ignore();
    cin.getline(searchTitle, N);

    Book* found = findBookByTitle(books, size, searchTitle);
    if (found)
    {
        cout << "\nFind book:\n";
        printBook(*found);
    }
    else
    {
        cout << "\nBook \"" << searchTitle << "\" not found.\n";
    }
}