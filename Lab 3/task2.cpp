#include <iostream>
using namespace std;

class fitnesstracker {

    string username;
    int dailystepgoal;
    int stepstaken;
    double caloriesburned;

public:
    fitnesstracker(string name, int stepgoal) {
        username = name;
        dailystepgoal = stepgoal;
        stepstaken = 0;
        caloriesburned = 0.0;
    }

    
    void logsteps(int steps) {
        stepstaken += steps;
        caloriesburned += steps * 0.04;
        cout << "Steps logged successfully!" << endl;
}

    bool goalachieved() {
        return stepstaken >= dailystepgoal;
    }
    
    void displayprogress() {
        cout << "User: " << username << endl;
        cout << "daily step goal : " << dailystepgoal << endl;
        cout << "Steps Taken: " << stepstaken <<  endl;
        cout << "Calories Burned: " << caloriesburned << " kcal" << endl;
        if (goalachieved()) {
            cout << "Congratulations! You met your daily step goal!" << endl;
        } else {
            cout << "Keep going! You can do it!" << endl;
        }
    }
};

int main() {
    
    fitnesstracker tracker("Laiba", 10000);

    tracker.logsteps(3000);
    tracker.logsteps(5000);
    tracker.logsteps(2500);
    
    tracker.displayprogress();
    
    return 0;
}

