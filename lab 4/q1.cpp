#include <iostream>
using namespace std;

class Car {
    public:
        string brand;
        string model;
        double price;
        bool isAvailable;

        Car() {
            brand = "Unknown";
            model = "Generic";
            price = 0.0;
            isAvailable = true;
        }

        void update(string b, string m, double p) {
            brand = b;
            model = m;
            price = p;

            isAvailable = true;
        
        }

        void process() {
            if(isAvailable == true) {
                cout << "The car is rented" << endl;
            }
        }

};

int main () {
    Car c1;
    c1.update("suzuki", "cultus", 10000);
    c1.process();
}