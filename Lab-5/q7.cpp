#include <iostream>
#include <cstring>
using namespace std;

class Product {
public:
    int id;
    char name[50];
    int quantity;

    Product() {}
    Product(int pid, const char* pname, int qty) {
        id = pid;
        strcpy(name, pname);
        quantity = qty;
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    Product products[100];
    int count;

public:
    Warehouse() { count = 0; }
    void addProduct(int id, const char* name, int qty) {
        products[count++] = Product(id, name, qty);
    }
    void sortProducts() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(products[i].name, products[j].name) > 0) {
                    Product temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
    }
    void searchProduct(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i].id == id) {
                products[i].display();
                return;
            }
        }
        cout << "Not found." << endl;
    }
    void displayAll() {
        for (int i = 0; i < count; i++) {
            products[i].display();
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(1, "Laptop", 10);
    warehouse.addProduct(2, "Chair", 20);
    warehouse.addProduct(3, "Table", 15);
    warehouse.sortProducts();
    warehouse.displayAll();
    warehouse.searchProduct(102);
    return 0;
}
