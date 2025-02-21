class Car {
private:
    string carID;
    string model;
    double rentalPricePerDay;
    double totalRevenue;
    bool isAvailable;

public:
    Car(string id, string model, double rentalPrice) : carID(id), model(model), rentalPricePerDay(rentalPrice), totalRevenue(0), isAvailable(true) {}

    void displayCarDetails() {
        cout << "Car ID: " << carID << "\n";
        cout << "Model: " << model << "\n";
        cout << "Rental Price Per Day:" << rentalPricePerDay << "\n";
        cout << "Total Revenue: " << totalRevenue << "\n";
        cout << "Availability: " << "\n";

        if(isAvailable) {

        cout << "Available" << "\n";
        }
        else {
        cout << "Rented" << "\n";
    }
};