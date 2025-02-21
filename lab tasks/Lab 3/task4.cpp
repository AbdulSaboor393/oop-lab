#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string make;
    string type;
    float tankSize;     
    float fuelLevel; 

public:
    Vehicle(string b, string m, float capacity) {
        make = b;
        type = m;
        tankSize = capacity;
        fuelLevel = capacity; 
    }

    void move(float distance) {
        float fuelUsed = distance * 0.1; 
        if (fuelUsed > fuelLevel) {
            cout << "Not enough fuel to move " << distance << " km!\n";
        } else {
            fuelLevel -= fuelUsed;
            cout << "Moved " << distance << " km. Fuel used: " << fuelUsed << " liters.\n";
            checkFuel();
        }
    }

    void fillTank(float amount) {
        if (amount <= 0) {
            cout << "Invalid fuel amount!\n";
            return;
        }

        if (fuelLevel + amount > tankSize) {
            cout << "Tank overflow! Filling up to full capacity.\n";
            fuelLevel = tankSize;
        } else {
            fuelLevel += amount;
            cout << "Added " << amount << " liters of fuel.\n";
        }
        checkFuel();
    }

    void checkFuel() {
        cout << "Current fuel level: " << fuelLevel << " liters.\n";
        if (fuelLevel < 5) {
            cout << "Warning: Low fuel! Please refill soon.\n";
        }
    }

    void showVehicle() {
        cout << "Vehicle: " << make << " " << type << "\n";
        cout << "Tank Size: " << tankSize << " liters\n";
        cout << "Current Fuel Level: " << fuelLevel << " liters\n";
    }
};

int main() {
    Vehicle zoyavehicle("Honda", "city", 55); 

    zoyavehicle.showVehicle();
    
    zoyavehicle.move(110); 
    zoyavehicle.move(190); 
    
    zoyavehicle.fillTank(20);
    zoyavehicle.fillTank(40); 
    
    zoyavehicle.showVehicle(); 
    return 0;
}

