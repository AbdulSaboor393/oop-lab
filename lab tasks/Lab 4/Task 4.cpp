#include <iostream>
#include <stdbool.h>
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
		
	public:
	Car() {
		Brand = "unknown";
		Model = "Generic";
		RentalPrice = 0.0;
		Availability = true;
		rentedDays = 0; 
        totalRevenue = 0.0; 
	}

	Car(string BrandName, string ModelName, float RentPrice, bool Avail) {
        Brand = BrandName;
        Model = ModelName;
        RentalPrice = RentPrice;
        Availability = Avail;
        rentedDays = 0; 
        totalRevenue = 0.0; 
    }

    Car(const Car &c) {
        Brand = c.Brand;
        Model = c.Model;
        RentalPrice = c.RentalPrice;
        Availability = c.Availability;
        rentedDays = c.rentedDays; 
        totalRevenue = c.totalRevenue; 
    }

    ~Car() {
        cout << "Destroying Vehicle: " << Brand << " " << Model << endl;
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
            totalRevenue += this->RentalPrice * days; 
            cout << "Vehicle rented for " << days << " days.\n" << endl;
        } else {
            cout << "This vehicle is already rented.\n" << endl;
        }
    }

	 void displayCarInfo() {
        cout << "\nVehicle Make: " << Brand << endl;
        cout << "Vehicle Model: " << Model << endl;
        cout << "Daily Rental Cost: $" << RentalPrice << endl;
        cout << "Status: " << (Availability ? "Available for Rent" : "Currently Rented") << endl;
        cout << "Total Earnings: $" << totalRevenue << endl;
    }
};

int main() {
    Car firstCar("Ford", "Mustang", 75.0, true);
    cout << "Initial Vehicle Information:" << endl;
    firstCar.displayCarInfo();
    
    firstCar.RentCar(5);
    Car secondCar = firstCar;

    firstCar.UpdateCarDetails("Nissan", "Altima", 90.0);
    cout << "\nUpdated Vehicle Information:" << endl;
    firstCar.displayCarInfo();

    cout << "\nDuplicated Vehicle Information:" << endl;
    secondCar.displayCarInfo();

    return 0;
}

