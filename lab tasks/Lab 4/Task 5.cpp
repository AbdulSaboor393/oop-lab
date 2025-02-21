#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string Brand;
    string Model;
    float RentalPrice;
    bool Availability;
    int rentedDays;
    float totalRevenue;
    string carID;

public:
    Car() : carID("0000"), Brand("Unknown"), Model("Generic"), RentalPrice(0.0), Availability(true), rentedDays(0), totalRevenue(0.0) {}

    Car(string ID, string BrandName, string ModelName, float RentPrice, bool Avail)
        : carID(ID), Brand(BrandName), Model(ModelName), RentalPrice(RentPrice), Availability(Avail), rentedDays(0), totalRevenue(0.0) {}

    Car(const Car &c) : carID(c.carID), Brand(c.Brand), Model(c.Model), RentalPrice(c.RentalPrice), Availability(c.Availability), rentedDays(c.rentedDays), totalRevenue(c.totalRevenue) {}

    ~Car() {
        cout << "Destroying Vehicle: " << Brand << " " << Model << " | ID: " << carID << endl;
    }

    void UpdateCarDetails(string BrandName, string ModelName, float RentPrice) {
        Brand = BrandName;
        Model = ModelName;
        RentalPrice = RentPrice;
    }

    void RentCar(int days) {
        if (Availability) {
            Availability = false;
            rentedDays += days;
            totalRevenue += RentalPrice * days;
            cout << "Vehicle rented for " << days << " days.\n" << endl;
        } else {
            cout << "This vehicle is currently unavailable.\n" << endl;
        }
    }

    void displayCarInfo() {
        cout << "\nVehicle ID: " << carID << endl;
        cout << "Make: " << Brand << endl;
        cout << "Model: " << Model << endl;
        cout << "Daily Rental Rate: $" << RentalPrice << endl;
        cout << "Status: " << (Availability ? "Available for Rent" : "Currently Rented") << endl;
    }

    void displayFullCarInfo() {
        displayCarInfo();
        cout << "Total Days Rented: " << rentedDays << endl;
        cout << "Total Earnings: $" << totalRevenue << endl;
    }
};

int main() {
    Car firstCar("X789", "Ford", "Mustang", 75.0, true);
    cout << "Initial Vehicle Information:" << endl;
    firstCar.displayFullCarInfo();

    firstCar.RentCar(5);

    Car secondCar = firstCar;

    firstCar.UpdateCarDetails("Nissan", "Altima", 90.0);
    cout << "\nUpdated Vehicle Information:" << endl;
    firstCar.displayFullCarInfo();

    cout << "\nDuplicated Vehicle Information:" << endl;
    secondCar.displayFullCarInfo();

    return 0;
}

