#include <iostream>
#include <string>

using namespace std;

class ActivityMonitor {
private:
    string participantName;
    int targetSteps;
    int recordedSteps;
    double burnedCalories;

public:
    ActivityMonitor(string name, int stepTarget) {
        participantName = name;
        targetSteps = stepTarget;
        recordedSteps = 0;
        burnedCalories = 0.0;
    }

    void registerSteps(int steps) {
        if (steps > 0) {
            recordedSteps += steps;
            burnedCalories += steps * 0.05;
            cout << steps << " steps logged. Total steps: " << recordedSteps << endl;
        } else {
            cout << "Invalid step count!" << endl;
        }
    }

    void showProgress() {
        cout << "Progress for " << participantName << ":\n";
        cout << "Steps Taken: " << recordedSteps << endl;
        cout << "Calories Burned: " << burnedCalories << endl;
        cout << "Daily Step Goal: " << targetSteps << endl;

        if (recordedSteps >= targetSteps) {
            cout << "Congratulations! You've met your daily step goal!" << endl;
        } else {
            cout << "Keep going! You need " << (targetSteps - recordedSteps) << " more steps to reach your goal." << endl;
        }
    }

    bool isGoalAchieved() {
        return recordedSteps >= targetSteps;
    }
};

int main() {
    ActivityMonitor laibasMonitor("Laiba", 10000);

    laibasMonitor.registerSteps(3000);
    laibasMonitor.registerSteps(5000);
    laibasMonitor.registerSteps(3000);

    laibasMonitor.showProgress();

    return 0;
}
