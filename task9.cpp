#include <iostream>
#include <string>

using namespace std;

struct Product {
    int ID;
    string name;
    int quantity;
    float price;
};

int main() {
    int x;
    cout << "Enter the number of products: ";
    cin >> x;
    cin.ignore(); //flushes the buffer; got to know from gpt

    Product * products = new Product[x];

    for (int i = 0; i < x; ++i) {
        cout << "Enter details for product " << i + 1 << endl;
        
        cout << "ID: ";
        cin >> products[i].ID;

        cin.ignore();
        
        cout << "Name: ";
        getline(cin, products[i].name);
        
        cout << "quantity: ";
        cin >> products[i].quantity;
        
        cout << "Price: ";
        cin >> products[i].price;

        float sumQuantity = sumQuantity + products[i].quantity;
        float sumPrice = sumPrice + products[i].price;

        

        cin.ignore(); 
    }
    
        float sumQuantity, sumPrice;

        float total = sumQuantity * sumPrice;

        cout << "Total: " << total << endl;

    delete[] products;

    return 0;
}