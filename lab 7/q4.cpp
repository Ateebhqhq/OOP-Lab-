#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, age, contactNumber, address;
public:
    Person(string n, string a, string c, string addr = "Unknown") : name(n), age(a), contactNumber(c), address(addr) {}
    virtual void displayInfo() {
        cout << "Name: " << name << endl << "Age: " << age << endl << "Contact: " << contactNumber << endl << "Address: " << address << endl;
    }
    virtual void updateInfo(string newContact, string newAddress) {
        contactNumber = newContact;
        address = newAddress;
    }
};

class Patient : public Person {
    string patientID, medicalHistory, doctorAssigned;
public:
    Patient(string n, string a, string c, string id, string history, string doctor) : Person(n, a, c), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    void displayInfo() override {
        cout << "Patient ID: " << patientID << endl;
        Person::displayInfo();
        cout << "Medical History: " << medicalHistory << endl << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    vector<string> patientsList; // For vectors => GPT zindabad
public:
    Doctor(string n, string a, string c, string spec, double fee) : Person(n, a, c), specialization(spec), consultationFee(fee) {}
    void addPatient(string patientName) {
        patientsList.push_back(patientName);
    }
    void displayInfo() override {
        cout << "Specialization: " << specialization << endl << "Consultation Fee: " << consultationFee << endl;
        Person::displayInfo();
        cout << "Patients List:" << endl;
        for (const auto& p : patientsList) {
            cout << p << endl;
        }
    }
};

class Nurse : public Person {
    string assignedWard, shiftTimings;
public:
    Nurse(string n, string a, string c, string ward, string shift) : Person(n, a, c), assignedWard(ward), shiftTimings(shift) {}
    void displayInfo() override {
        cout << "Assigned Ward: " << assignedWard << endl << "Shift Timings: " << shiftTimings << endl;
        Person::displayInfo();
    }
};

class Administrator : public Person {
    string department;
    double salary;
public:
    Administrator(string n, string a, string c, string dept, double sal) : Person(n, a, c), department(dept), salary(sal) {}
    void updateInfo(string newContact, string newAddress, double newSalary) {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }
    void displayInfo() override {
        cout << "Department: " << department << endl << "Salary: " << salary << endl;
        Person::displayInfo();
    }
};

int main() {
    Patient p("Kitler", "35", "12345", "P001", "Diabetes", "Dr. Meow");
    Doctor d("Meow", "45", "67890", "Cardiology", 500);
    Nurse n("Whiskers", "30", "54321", "ICU", "Night");
    Administrator a("Bork", "50", "99999", "HR", 6000);

    d.addPatient("Kitler");
    
    p.displayInfo();
    cout << endl;
    d.displayInfo();
    cout << endl;
    n.displayInfo();
    cout << endl;
    a.displayInfo();
    
    return 0;
}
