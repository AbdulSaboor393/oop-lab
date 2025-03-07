#include <iostream>
#include <string>
using namespace std;

class Project;

class Employee {
    string designation;
    string name;
    int projcount = 0;
    Project* project[10];

public:
    Employee(string des, string empname) : designation(des), name(empname) {}

    string getName() const {
        return name;
    }

    string getDesignation() const {
        return designation;
    }
};

class Project {
    string title;
    string deadline;
    int empcount = 0;
    Employee* employee[10];

public:
    Project(string ptitle, string dline) : title(ptitle), deadline(dline) {}

    void addEmployee(Employee* emp) {
        employee[empcount] = emp;
        empcount++;
    }

    void displayProject() const {
        cout << "Project Title: " << title << endl;
        cout << "Project Deadline: " << deadline << endl;
        cout << "\nEmployees Working on this project: \n" << endl;
        for (int i = 0; i < empcount; i++) {
            cout << "Employee Name: " << employee[i]->getName() << endl;
            cout << "Employee Designation: " << employee[i]->getDesignation() << endl;
        }
    }

    string getTitle() const {
        return title;
    }

    string getDeadline() const {
        return deadline;
    }
};

int main() {
    Employee emp1("CEO", "Saboor");
    Employee emp2("HR", "Alina");

    Project proj1("Game Development", "10th March 2005");
    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj1.displayProject();

    Project proj2("OOP Project", "10th June 2006");
    proj2.addEmployee(&emp1);
    proj2.displayProject();

    return 0;
}

