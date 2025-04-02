#include <iostream>
using namespace std;

class Device{
    protected:
    int ID;
    string Name;
    bool status;
    string location;
    public:
    Device(int i, string n, string loc = " " ) :ID(i),Name(n),location(loc){}
    
    virtual void turnon(){
         status = true;
         cout << Name << " is now switched ON." << endl;
    }
    
    virtual void turnoff(){
         status = false;
         cout << Name << " is now switched OFF." << endl;
    }
    
    virtual void displayInfo(){
        cout << "Device ID: " << ID << endl;
        cout << "Device Name: " << Name << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
        cout << "Location: " << location << endl;
    }
};

class Light : public Device{
    protected:
    int brightness;
    string colormode;
    public:
    Light (int i, string n, string loc, int b, string c) : Device(i,n,loc),brightness(b),colormode(c){}
    
    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightness << "%" << endl;
        cout << "Color Mode: " << colormode << endl;
    }
};

class Thermostat : public Device{
    protected:
    int temp;
    public:
    Thermostat(int i, string n, string loc, int t):Device(i,n,loc),temp(t){}
    
    void displayInfo() override{
        Device::displayInfo();
        cout << "Current Temperature: " << temp << "°C" << endl;
    }
};

class SecurityCamera:public Device{
    protected:
    string resolution;
    bool recordingstatus;
    bool nightvision;
    public:
    SecurityCamera(int i, string n, string loc, string res, bool nv):Device(i,n,loc),resolution(res),nightvision(nv),recordingstatus(false){}
    void turnon(){
        status = true;
        recordingstatus = true;
        cout << Name << " is now ACTIVE and recording." << endl;
    }
    void turnoff(){
        status = false;
        recordingstatus = false;
        cout << Name << " is now INACTIVE and not recording." << endl;
    }
    
    void displayInfo() override{
        Device::displayInfo();
        cout << "Resolution: " << resolution << endl;
        cout << "Night Vision: " << (nightvision ? "ENABLED" : "DISABLED") << endl;
        cout << "Recording Status: " << (recordingstatus ? "ACTIVE" : "INACTIVE") << endl;
    }
};

class SmartPlug:public Device{
    private:
    int powerconsump;
    int timersetting;
    public:
    SmartPlug(int i, string n, string loc, int power, int timer) : Device(i,n,loc),powerconsump(power),timersetting(timer){}
    void turnoff() override {
        status = false;
        cout << Name << " is now DISABLED." << endl; 
        cout << "Total Power Used: " << powerconsump << " Watts" << endl;
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerconsump << " Watts" << endl;
        cout << "Timer Setting: " << timersetting << " minutes" << endl;
    }
};

int main(){
    Light L1(1, "Ceiling Light", "Bedroom", 75, "White");
    Thermostat T1(2, "Room Heater", "Living Room", 22);
    SecurityCamera C1(3, "Outdoor Camera", "Garage", "4K", true);
    SmartPlug P1(4, "Energy Saver Plug", "Office", 15, 10);
    
    L1.displayInfo();
    T1.displayInfo();
    C1.displayInfo();
    P1.turnoff();
    C1.turnon();
}

