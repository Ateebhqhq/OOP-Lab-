#include <iostream>
using namespace std;

class Shipment {
protected:
    string TrackingNumber;
    double Weight;

public:
    Shipment(string tn, double wt) : TrackingNumber(tn), Weight(wt) {}
    virtual void estimatedeliveryTime() = 0;
    virtual void ShowDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double wt) : Shipment(tn, wt) {}

    void estimatedeliveryTime() override {
        cout << "Air estimated time" << endl;
    }

    void ShowDetails() override {
        cout << TrackingNumber << " " << Weight << endl;
    }
};

class GroundSHipment : public Shipment {
public:
    GroundSHipment(string tn, double wt) : Shipment(tn, wt) {}

    void estimatedeliveryTime() override {
        cout << "Ground estimated" << endl;
    }

    void ShowDetails() override {
        cout << TrackingNumber << " " << Weight << endl;
    }
};

int main() {
    Shipment* shipment1 = new AirFreight("abc123", 10.5);
    Shipment* shipment2 = new GroundSHipment("hqhqh454", 20.0);

    shipment1->estimatedeliveryTime();
    shipment1->ShowDetails();

    shipment2->estimatedeliveryTime();
    shipment2->ShowDetails();

    delete shipment1;
    delete shipment2;

    return 0;
}
