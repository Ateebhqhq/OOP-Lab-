#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc = "Unknown") : deviceID(id), deviceName(name), location(loc), status(false) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " is now ON" << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " is now OFF" << endl;
    }

    virtual void getStatus() const {
        cout << deviceName << " is " << (status ? "ON" : "OFF") << endl;
    }

    virtual void displayInfo() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Name: " << deviceName << endl;
        cout << "Location: " << location << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }

    virtual ~Device() {}
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string loc, int brightness = 50, string color = "White") : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    double temperature;
    string mode;

public:
    Thermostat(int id, string name, string loc, double temp = 22.0, string m = "Cooling") : Device(id, name, loc), temperature(temp), mode(m) {}

    void getStatus() const override {
        Device::getStatus();
        cout << "Temperature: " << temperature << "C" << endl;
        cout << "Mode: " << mode << endl;
    }
};

class SecurityCamera : public Device {
private:
    int resolution;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string loc, int res = 1080, bool nightVision = true) : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision) {}

    void turnOn() override {
        status = true;
        cout << deviceName << " is now recording" << endl;
    }
};

class SmartPlug : public Device {
private:
    double powerConsumption;

public:
    SmartPlug(int id, string name, string loc, double power = 0.0) : Device(id, name, loc), powerConsumption(power) {}

    void turnOff() override {
        Device::turnOff();
        cout << "Power usage recorded: " << powerConsumption << endl;
    }
};

int main() {
    Light livingRoomLight(1, "Living Room Light", "Living Room", 75, "Warm White");
    Thermostat homeThermostat(7, "Smart Thermostat", "Hallway", 24.5, "Heating");
    SecurityCamera frontDoorCam(4, "Front Door Camera", "Entrance", 1440, true);
    SmartPlug coffeeMaker(9, "Coffee Maker Plug", "Kitchen", 0.5);

    cout << "Device Information" << endl;
    livingRoomLight.displayInfo();
    homeThermostat.getStatus();
    frontDoorCam.turnOn();
    coffeeMaker.turnOff();

    return 0;
}
