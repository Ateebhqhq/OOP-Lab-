#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(string empName, string empDesignation) {
        name = empName;
        designation = empDesignation;
    }

    void display() {
        cout << "Employee: " << name << " (" << designation << ")" << endl;
    }
};

class Project {
public:
    string title;
    string deadline;
    Employee* employees[5]; 
    int employeeCount;

    Project(string t, string d) {
        title = t;
        deadline = d;
        employeeCount = 0;
    }

    void addEmployee(Employee* emp) {
        if (employeeCount < 5) {
            employees[employeeCount++] = emp;
        }
    }

    void display() {
        cout << "Project: " << title << " (Deadline: " << deadline << ")\nEmployees:\n";
        for (int i = 0; i < employeeCount; i++) {
            cout << "- " << employees[i]->name << "\n";
        }
    
    }
};

int main() {
    Employee emp1("Musashi", "Mazdoor");
    Employee emp2("Gordon", "Chef");

    Project proj1("AI Project", "2025-06-30");
    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);

    proj1.display();
    emp1.display();
    emp2.display();

    return 0;
}
