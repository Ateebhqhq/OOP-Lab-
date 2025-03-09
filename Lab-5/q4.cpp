#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;
public:
    AlarmSystem(string level) : securityLevel(level) {}
    void display() const {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
private:
    string homeName;
    AlarmSystem alarm;
public:
    SmartHome(string name, string securityLevel) : homeName(name), alarm(securityLevel) {}
    
    void display() const {
        cout << "Smart Home: " << homeName << endl;
        alarm.display();
    }
};

int main() {
    SmartHome home("My Smart Home", "High");
    home.display();
    return 0;
}
