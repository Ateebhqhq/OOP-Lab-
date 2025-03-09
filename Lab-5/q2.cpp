#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int studentID, string studentName, int* examScores, int count) {
        id = studentID;
        name = studentName;
        numScores = count;
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = examScores[i];
        }
    }

    Student(const Student& other) {
        id = other.id;
        name = other.name;
        numScores = other.numScores;
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }

    void display() const {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int scores1[] = {3, 80, 79, 100};
    Student student1(3, "Kitler", scores1, 4);
    
    Student student2 = student1;
    
    cout << "Original Student:" << endl;
    student1.display();

    cout << "Copied Student:" << endl;
    student2.display();

    return 0;
}
