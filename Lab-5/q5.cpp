#include <iostream>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    int experience;
public:
    Doctor(string n, string spec, int exp) : name(n), specialization(spec), experience(exp) {}
    void display() const {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization << ", Experience: " << experience << " years" << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctors[10];
    int doctorCount;
public:
    Hospital(string name) : hospitalName(name), doctorCount(0) {}
    void addDoctor(Doctor* doc) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = doc;
        } else {
            cout << "Hospital doctor capacity full" << endl;
        }
    }
    void display() const {
        cout << "Hospital: " << hospitalName << endl;
        cout << "Doctors Working Here:" << endl;
        for (int i = 0; i < doctorCount; i++) {
            doctors[i]->display();
        }
    }
};

int main() {
    Doctor d1("Dr. john chandio", "ent specialist", 15);
    Doctor d2("Dr. jason uzumaki", "general", 10);
    
    Hospital h("City Hospital");
    h.addDoctor(&d1);
    h.addDoctor(&d2);
    
    h.display();
    return 0;
}
