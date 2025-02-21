#include <iostream>
using namespace std;

class Car {
    public:
        string brand;
        string model;
        double price;
        bool isAvailable;

        Car(string b, string m, double p, bool s) {
            brand = b;
            model = m;
            price = p;
            isAvailable = s;
        }

        void applyDiscount(int x) {
            if (x>5 && x<10) {
                cout << "You get a 5percent discount" << endl;
            }

            else if (x>10) {
                cout << "You get a 10 percent discount" << endl;

            }
        
        }

        void availibility() {
            if(isAvailable=false) {
                cout << "The car is unavailable" << endl;
            }
        }

};

int main () {

    Car c1("Nissan", "GTR", 100000, true);
    c1.applyDiscount(10);
    c1.availibility();
}