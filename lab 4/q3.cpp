#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string model;
    double price;
    bool isAvailable;

    Car(string b, string m, double p, bool s) : brand(b), model(m), price(p), isAvailable(s) {}

    Car(const Car &obj) {
        brand = obj.brand; 
        model = obj.model; 
        price = obj.price; 
        isAvailable = obj.isAvailable;
        cout << "Car copied" << endl;
    }

    ~Car() {
        cout << brand << model << " car is removed " << endl;
    }

    void displayCar() {
        cout << "Brand: " << brand << "\nModel: " << model; 
        cout << "\nPrice: " << price << "\nStatus: ";
        if(isAvailable == true) {
            
            cout << "Available" << "\n";
         }
         else { 
            cout << "Rented" << "\n";
         }
    }
};

int main() {
    Car car1("Toyota", "Corolla", 25000, true);
    cout << "Original Car:" << endl;
    car1.displayCar();

    Car car2 = car1;  
    cout << "Copied Car:" << endl;
    car2.displayCar();

    car1.brand = "Honda";
    car1.model = "Civic";
    car1.price = 27000;

    cout << "After modifying original Car:" << endl;
    car1.displayCar();
    cout << "Copied Car:" << endl;
    car2.displayCar();

    return 0;
}
