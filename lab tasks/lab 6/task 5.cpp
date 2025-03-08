#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    bool isActive;
public:
    Device(int id, bool status) : deviceID(id), isActive(status) {}

    virtual void showDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float displaySize;
public:
    SmartPhone(int id, bool status, float size) : Device(id, status), displaySize(size) {}

    void showDetails() override {
        Device::showDetails();
        cout << "Display Size: " << displaySize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool hasHeartRateSensor;
public:
    SmartWatch(int id, bool status, bool hrSensor) : Device(id, status), hasHeartRateSensor(hrSensor) {}

    void showDetails() override {
        Device::showDetails();
        cout << "Heart Rate Sensor: " << (hasHeartRateSensor ? "Available" : "Not Available") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int totalSteps;
public:
    SmartWearable(int id, bool status, float size, bool hrSensor, int steps)
        : Device(id, status), SmartPhone(id, status, size), SmartWatch(id, status, hrSensor), totalSteps(steps) {}

    void showDetails() override {
        Device::showDetails();
        cout << "Display Size: " << displaySize << " inches" << endl;
        cout << "Heart Rate Sensor: " << (hasHeartRateSensor ? "Available" : "Not Available") << endl;
        cout << "Step Count: " << totalSteps << " steps" << endl;
    }
};

int main() {
    int id, steps;
    bool status, heartRateSensor;
    float size;

    cout << "Enter Device ID: ";
    cin >> id;
    cout << "Enter Device Status (1 for Active, 0 for Inactive): ";
    cin >> status;
    cout << "Enter Display Size (in inches): ";
    cin >> size;
    cout << "Heart Rate Sensor Available? (1 for Yes, 0 for No): ";
    cin >> heartRateSensor;
    cout << "Enter Step Count: ";
    cin >> steps;

    SmartWearable wearableDevice(id, status, size, heartRateSensor, steps);
    
    cout << "\nSmart Wearable Device Details:\n";
    wearableDevice.showDetails();

    return 0;
}
