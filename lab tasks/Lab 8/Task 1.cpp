#include <iostream>
#include <string>

using namespace std;

class Device{
    public:
    int deviceId;
    string deviceName;
    bool status;
    string location;
    
    Device(int id, string name, bool status): deviceId(id), deviceName(name), status(status), location(""){}
    
    virtual void turnOn(){
        status=true;
    }

    virtual void turnOff(){
        status=false;
    }

    virtual bool getStatus(){
        return status;
    }

    virtual void display(){
        cout<<"Device ID: "<<deviceId<<"\tDevice Name: "<<deviceName<<"\tStatus: "<< (status ? "On" : "Off");
        if(location!="") cout<<"\tLocation: "<<location<<endl;
        else cout<<endl;
    }

    virtual ~Device(){}
};

class Light: public Device{
public:
    double brightnessLevel;
    string colorMode;

    Light(int id, string name, bool status, double level, string mode): Device(id, name, status), brightnessLevel(level), colorMode(mode){}

    void display(){
        Device::display();
        cout<<"Brightness Level: "<<brightnessLevel<<"\tColor Mode: "<<colorMode<<endl;
    }

};

class Thermostate: public Device{
    public:
    double temp;
    bool tempStatus; 

    Thermostate(int id, string name, bool status, double temp, bool tempStatus): Device(id, name, status), temp(temp), tempStatus(tempStatus){}

    bool getStatus(){ return tempStatus;}
};

class SecurityCamera: public Device{
public:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

    SecurityCamera(int id, string name, bool status, string resolution, bool Status, bool vision): Device(id, name, status), recordingStatus(Status), resolution(resolution), nightVisionEnabled(vision){}


    void turnOn(){
        status=true;
        recordingStatus=true;
    }
};

class SmartPlug: public Device{
public:
    double powerConsumption;
    int timerSetting;

    SmartPlug(int id, string name, bool status, double consumption, int setting): Device(id, name, status), powerConsumption(consumption), timerSetting(setting){}

    void turnOff(){
        powerConsumption=0;
    }
};

int main(){
    Light light(1, "Living Room Light", true, 75, "Warm White");
    Thermostate thermostate(2, "Hall Thermostate", false, 22.5, true);
    SecurityCamera camera(3, "Front Door Camera", true, "1080p", true, true);
    SmartPlug plug(4, "Smart Plug", true, 150, 30);

    light.turnOn();
    light.display();
    cout << endl;

    thermostate.getStatus();
    cout << endl;

    camera.turnOn();
    camera.getStatus();
    cout << endl;

    plug.turnOff();
}
