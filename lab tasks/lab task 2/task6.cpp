#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Enter marks in 3 subjects: ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].marks[j];
        }
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].marks[j];
        }
        float average = sum / 3;
        cout << "\nName: " << students[i].name;
        cout << "\nRoll Number: " << students[i].rollNumber;
        cout << "\nAverage Marks: " << average << endl;
    }

    delete[] students;
    return 0;
}
