#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;
public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "InPatient Treatment for " << name << " ID: " << id << " - Kitler juice infusion and unicorn naps" << endl;
    }
    void calculateCost() override {
        cout << "InPatient Cost: 9999 glitter coins and 3 abra kadabra" << endl;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "OutPatient Treatment for " << name << " ID: " << id << " - Bubblewrap therapy" << endl;
    }
    void calculateCost() override {
        cout << "OutPatient Cost: 555 sugar cubes and a whisper from a goblin" << endl;
    }
};

int main() {
    Patient* p1 = new InPatient("Fluffy McMeow", "IN123");
    Patient* p2 = new OutPatient("zoomie poomie", "OUT456");

    p1->displayTreatment();
    p1->calculateCost();

    p2->displayTreatment();
    p2->calculateCost();

    delete p1;
    delete p2;

    return 0;
}
