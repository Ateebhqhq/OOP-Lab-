#include <iostream>

using namespace std;

struct Employee {
    string name;
    float hoursWorked;
    float hourlyRate;
};

Employee* allocateMemory(int x) {
    return new Employee[x];
}

void inputDetails(Employee* employees, int x) {
    cin.ignore();
    for (int i = 0; i < x; i++) {
        cout << "Enter employee's name: ";
        getline(cin, employees[i].name);

        cout << "Enter employee's hours worked: ";
        cin >> employees[i].hoursWorked;

        cout << "Enter employee's hourly rate: ";
        cin >> employees[i].hourlyRate;
        
        cin.ignore(); 
    }
}

void calculate(Employee* employees, int x) {
    for (int i = 0; i < x; i++) {
        float salary = employees[i].hoursWorked * employees[i].hourlyRate;
cout << employees[i].name << " salary: $" << salary << endl;
    }
}

int main() {
    int x;
    cout << "Enter number of employees: ";
    cin >> x;

    Employee* employees = allocateMemory(x);

    inputDetails(employees, x);

    calculate(employees, x);

    delete[] employees;

    return 0;
}
