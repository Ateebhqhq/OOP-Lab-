#include <iostream>
using namespace std;

class Library {
private:
    string bookList[10];        
    string borrowedBooks[10];   
    int count;                  

public:
    Library() {
        count = 0;  
        for (int i = 0; i < 10; i++) {
            bookList[i] = "";
            borrowedBooks[i] = "";
        }
    }

    void addBooks(string book) {
        for (int i = 0; i < 10; i++) {
            if (bookList[i] == "") {  
                bookList[i] = book;
                cout << "Book \"" << bookList[i] << "\" has been added.\n";
                return;  
            }
        }
        cout << "Library is full! Cannot add more books.\n";
    }

    void lendBook(string book) {
        for (int i = 0; i < 10; i++) {
            if (bookList[i] == book) {  
                borrowedBooks[i] = book;
                bookList[i] = "";  
                cout << "Book \"" << borrowedBooks[i] << "\" has been issued.\n";
                return;
            }
        }
        cout << "Book not available!\n";
    }

    void returnBook(string book) {
        for (int i = 0; i < 10; i++) {
            if (borrowedBooks[i] == book) {  
                bookList[i] = book;  
                borrowedBooks[i] = "";
                cout << "Book \"" << book << "\" has been returned.\n";
                return;
            }
        }
        cout << "This book was not borrowed!\n";
    }

    void displayBooks() {
        cout << "\nAvailable Books:\n";
        for (int i = 0; i < 10; i++) {
            if (bookList[i] != "") {  
                cout << "- " << bookList[i] << endl;
            }
        }
    }
};

int main() {
    Library l1;

    l1.addBooks("Harry Potter");
    l1.addBooks("Kitaabcha");
    l1.addBooks("Mein Kampf");
    l1.addBooks("How to Win Stupid Arguments");
    l1.addBooks("How to Stop a School Shooting");

    l1.lendBook("Mein Kampf");
    l1.lendBook("Kitaabcha");

    l1.returnBook("Mein Kampf");
    
    l1.displayBooks();

    return 0;
}
