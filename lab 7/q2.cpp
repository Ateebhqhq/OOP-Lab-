#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock) : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual double calculateTotalPrice(int quantity) const {
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << endl
             << "Name: " << productName << endl
             << "Price: " << price << endl
             << "Stock: " << stockQuantity << endl;
    }

    friend ostream& operator<<(ostream& os, const Product& p) {
        os << "Product ID: " << p.productID << endl
           << "Name: " << p.productName << endl
           << "Price: " << p.price << endl
           << "Stock: " << p.stockQuantity;
        return os;
    }
};

class Book : public Product {
private:
    string author;
    string genre;

public:
    Book(int id, string name, double p, int stock, string auth, string gen)
        : Product(id, name, p, stock), author(auth), genre(gen) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl
             << "Genre: " << genre << endl;
    }

    friend ostream& operator<<(ostream& os, const Book& b) {
        os << static_cast<const Product&>(b) << endl
           << "Author: " << b.author << endl
           << "Genre: " << b.genre;
        return os;
    }
};

class Order {
public:
    double operator+(const Product& p) {
        return p.calculateTotalPrice(10);
    }
};

int main() {
    Book myBook(1, "C++ Programming", 29.99, 50, "hqhqh", "Programminging");

    myBook.displayProductInfo();

    Order myOrder;
    double totalCost = myOrder + myBook;
    cout << "Total Cost for 10 Books: " << totalCost << endl;

    cout << myBook << endl;

    return 0;
}
