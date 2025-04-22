#include <iostream>
using namespace std;

class WhetherSensor {
public:
    virtual void ReadData() = 0;
    virtual void printReport() = 0;
    virtual ~WhetherSensor() {}
};

class Thermometer : public WhetherSensor {
public:
    void ReadData() override {
        cout << "Scanning" << endl;
    }

    void printReport() override {
        cout << "Complete" << endl;
    }
};

class Barometer : public WhetherSensor {
public:
    void ReadData() override {
        cout << "Reading atmospheric conditions" << endl;
    }

    void printReport() override {
        cout << "It's chilled" << endl;
    }
};

int main() {
    WhetherSensor* thermometerSensor = new Thermometer();
    WhetherSensor* barometerSensor = new Barometer();

    WhetherSensor* sensors[] = {thermometerSensor, barometerSensor};

    for (int i = 0; i < 2; ++i) {
        sensors[i]->ReadData();
        sensors[i]->printReport();
    }

    delete thermometerSensor;
    delete barometerSensor;

    return 0;
}
