void rentCar(int days) {
    if (isAvailable == false) {
        cout << "Car is not available for rent.\n";
        return;
    }

    double revenue = rentalPricePerDay * days;
    this->totalRevenue = this->totalRevenue + revenue;
    this->isAvailable = false;

    cout << "Car rented for " << days << " days. Revenue: " << revenue;
}

void displayRevenue() {
    cout << "Total revenue:" << this->totalRevenue << "\n";
}
