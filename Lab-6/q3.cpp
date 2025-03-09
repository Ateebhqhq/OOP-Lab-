#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string rArea) : Person(n, a), researchArea(rArea) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string rArea, int pubs) : Person(n, a), Teacher(n, a, sub), Researcher(n, a, rArea), publications(pubs) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter professor's name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter subject expertise: ";
    getline(cin, subject);
    cout << "Enter research area: ";
    getline(cin, researchArea);
    cout << "Enter number of publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);
    cout << "Professor Details: " << endl;
    prof.displayDetails();

    return 0;
}
