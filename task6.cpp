#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
    float average;
};

int main() {
    int x;
    cout << "Enter the number of students: ";
    cin >> x;
    cin.ignore(); //flushes the buffer; got to know from gpt

    Student* students = new Student[x];

    for (int i = 0; i < x; ++i) {
        cout << "Enter details for student " << i + 1 << endl;
        
        cout << "Name: ";
        getline(cin, students[i].name);
        
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        
        cout << "Marks in 3 subjects: ";
        cin >> students[i].marks[0] >> students[i].marks[1] >> students[i].marks[2];
        
        students[i].average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3;
        
        cin.ignore(); 
    }

    
    for (int i = 0; i < x; ++i) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Marks: " << students[i].marks[0] << students[i].marks[1] << students[i].marks[2] << endl;
        cout << "Average: " << students[i].average << endl;
    }

    delete[] students;

    return 0;
}