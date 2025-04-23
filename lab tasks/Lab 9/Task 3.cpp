#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(const string& code, int cr) : courseCode(code), credits(cr) {}
    virtual ~Course() {} // Virtual destructor for proper cleanup
    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

class LectureCourse : public Course {
public:
    LectureCourse(const string& code, int cr) : Course(code, cr) {}

    double calculateGrade() override {
        return 75.0;
    }

    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(const string& code, int cr) : Course(code, cr) {}

    double calculateGrade() override {
        return 80.0;
    }

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    Course* c1 = new LectureCourse("CS1002", 3);
    Course* c2 = new LabCourse("CSL1002", 1);

    c1->displayInfo();
    cout << "Final Grade: " << c1->calculateGrade() << "\n\n";

    c2->displayInfo();
    cout << "Final Grade: " << c2->calculateGrade() << "\n";

    delete c1;
    delete c2;

    return 0;
}
