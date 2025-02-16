#include <iostream>
using namespace std;

class fitnessTracker {
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double weight;
    double caloriesBurned;
    double progress;



    public:
    fitnessTracker() {
        userName = "Unknown";
        dailyStepGoal = 0.0;
        stepsTaken = 0.0;
        weight = 0.0;
        caloriesBurned = 0.0;
    }

    void setuserName(string n) {
        userName = n;
    }

    void setlogSteps(int steps) {
        stepsTaken = steps;
    }

    void setStepGoal(int goal) {
        dailyStepGoal = goal;
        progress = (((double)stepsTaken / goal) * 100);
    }

    void calculateCalories(double weight) {
        caloriesBurned = stepsTaken * 0.04 * weight;
    }

    void displayProgress() {
        cout << "You have burned " << caloriesBurned << " calories ;))" << endl;
        cout << "You took " << progress << " percent of steps of your daily goal (" << dailyStepGoal << ")" << endl;
    }
};

int main () {
    fitnessTracker t1;
    t1.setuserName("laiba");
    t1.setlogSteps(900);
    t1.setStepGoal(1000);
    t1.calculateCalories(70);
    t1.displayProgress();
}