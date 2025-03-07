#include <iostream>
#include <string>
using namespace std;

class Doctor {
    string name;
    string specialization;
    int experience;

public:
    Doctor(string n, string s, int exp) : name(n), specialization(s), experience(exp) {}

    string getName() const {
        return name;
    }

    string getSpecialization() const {
        return specialization;
    }

    int getExperience() const {
        return experience;
    }
};

class Hospital {
    string hospname;
    Doctor** doctor;
    int limit;
    int dcount;

public:
    Hospital(string name) : hospname(name), dcount(0), limit(50) {
        doctor = new Doctor*[limit];
    }

    void addDoctor(Doctor* doc) {
        if (dcount == limit) {
            cout << "Doctor limit reached" << endl;
        } else {
            doctor[dcount] = doc;
            dcount++;
            cout << "Doctor added" << endl;
        }
    }

    bool removeDoctor(Doctor* doc) {
        for (int i = 0; i < dcount; i++) {
            if (doctor[i]->getName() == doc->getName()) {
                for (int j = i; j < dcount - 1; j++) {
                    doctor[j] = doctor[j + 1];
                }
                delete doctor[dcount - 1];
                dcount--;
                return true;
            }
        }
        return false;
    }

    void changeHospital(Doctor* doc, Hospital* newhosp) {
        if (removeDoctor(doc)) {
            newhosp->addDoctor(doc);
            cout << "Doctor " << doc->getName() << " moved to " << newhosp->hospname << endl;
        } else {
            cout << "Doctor not found" << endl;
        }
    }

    void display() const {
        cout << "Hospital Name: " << hospname << endl;
        cout << "Doctors working: \n" << endl;
        for (int i = 0; i < dcount; i++) {
            cout << "Doctor Name: " << doctor[i]->getName() << endl;
            cout << "Specialization: " << doctor[i]->getSpecialization() << endl;
            cout << "Experience: " << doctor[i]->getExperience() << " years\n" << endl;
        }
    }

    ~Hospital() {
        for (int i = 0; i < dcount; i++) {
            delete doctor[i];
        }
        delete[] doctor;
    }
};

int main() {
    Hospital hosp1("Aga Khan");
    Doctor doc1("Memon", "Child Specialist", 20);
    Doctor doc2("Shareef", "Surgeon", 20);
    hosp1.addDoctor(&doc1);
    hosp1.addDoctor(&doc2);
    hosp1.display();

    Hospital hosp2("Liaquat");
    Doctor doc3("Mamoon", "Specialist", 18);
    hosp2.addDoctor(&doc3);
    hosp1.changeHospital(&doc2, &hosp2);
    hosp1.removeDoctor(&doc2);

    hosp1.display();
    hosp2.display();

    return 0;
}

