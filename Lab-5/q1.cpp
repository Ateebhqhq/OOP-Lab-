#include <iostream>
#include <cstring>

using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* ownerName;

public:
    Apartment(int aptID, string aptAddress, const char* owner) {
        id = aptID;
        address = aptAddress;
        ownerName = new char[strlen(owner) + 1];
        strcpy(ownerName, owner);
    }

    Apartment(const Apartment& other) {
        id = other.id;
        address = other.address;
        ownerName = other.ownerName;
    }

    void display() const {
        cout << "Apartment ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << ownerName << endl;
      
    }

    ~Apartment() {
        delete[] ownerName;
    }
};

int main() {
    Apartment apt1(1, "hqhqh street", "John Cena");
    Apartment apt2 = apt1;

    cout << "Original Apartment:" << endl;
    apt1.display();

    cout << "Copied Apartment:" << endl;
    apt2.display();

    return 0;
}
