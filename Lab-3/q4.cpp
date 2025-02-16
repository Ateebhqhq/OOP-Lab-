#include <iostream>
using namespace std;

class Car {
    private:
        string brand;
        string model;
        double fuelCapacity;
        double currentFuelLevel;

    public:
        Car() {
            brand = "";
            model = "";
            fuelCapacity = 0.0;
            currentFuelLevel = 0.0;
        }

        void reduceFuelLevel(double fuel) {
            if(fuelCapacity >= fuel && fuel > 0) {
            fuelCapacity -= fuel;
            }
        }

        void refuel(double fuel) {
            fuelCapacity += fuel;
        }

        void fuelStatus() {
            cout << "You have " << fuelCapacity << " fuel left in your car" << endl;
        }

        void warn() {
            if(fuelCapacity < 100) {
                cout << "ALERT! Fuel is below 100!" << endl;
            }
        }


};

int main() {

    Car c1;
    Car();
    c1.refuel(1000);
    c1.reduceFuelLevel(950);
    c1.fuelStatus();
    c1.warn();

}