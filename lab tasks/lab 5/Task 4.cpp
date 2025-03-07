#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
    string seclevel;

public:
    AlarmSystem(string slevel) : seclevel(slevel) {
        cout << "Alarm System set to: " << seclevel << endl;
    }

    string getSecLevel() const {
        return seclevel;
    }

    ~AlarmSystem() {}
};

class SmartHome {
    AlarmSystem alarmsystem;

public:
    SmartHome(string slevel) : alarmsystem(slevel) {}

    void display() const {
        cout << "SmartHome Details: " << endl;
        cout << "Alarm Level: " << alarmsystem.getSecLevel() << endl;
    }

    ~SmartHome() {}
};

int main() {
    SmartHome home1("Low");
    home1.display();
}

