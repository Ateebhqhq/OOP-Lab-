#include <iostream>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

Book* allocateMemory(int x) {
    return new Book[x];
}

void inputDetails(Book* books, int x) {
    cin.ignore();  // Acts like flush buffer
    for (int i = 0; i < x; i++) {
        cout << "Enter title of book " << i + 1;
        getline(cin, books[i].title);

        cout << "Enter author of book " << i + 1;
        getline(cin, books[i].author);

        cout << "Enter publication year of book " << i + 1;
        cin >> books[i].year;

        cin.ignore();  
    }
}

void display(Book* books, int x, int year) {
    cout << "Books published after " << year << endl;
    for (int i = 0; i < x; i++) {
        if (books[i].year > year) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }
}

int main() {
    int x;
    cout << "Enter the number of books: ";
    cin >> x;

    Book* books = allocateMemory(x);
    inputDetails(books, x);

    int thatYear;
    cout << "Enter a year to filter books published after that year: ";
    cin >> thatYear;

    display(books, x, thatYear);

    delete[] books;  

    return 0;
}
