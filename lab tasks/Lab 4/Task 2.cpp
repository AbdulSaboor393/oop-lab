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
	public:
	Car(){
		Brand = "unknown";
		Model = "Generic";
		RentalPrice = 0.0;
		Availability = true;
	}
	Car(string BrandName, string ModelName, float RentPrice, bool Avail) {
        Brand = BrandName;
        Model = ModelName;
        RentalPrice = RentPrice;
        Availability = Avail;
    }
    
	void UpdateCarDetails(string BrandName, string ModelName, float RentPrice) {
		Brand = BrandName;
        Model = ModelName;
		RentalPrice = RentPrice;
	}
	void RentCar() {
		if (Availability) {
			Availability = false;
			cout << "Car rental confirmed! Enjoy your ride.\n" << endl;
		} else {
			cout << "Sorry, this car is already booked.\n" << endl;
		}
	}
	void displayCarInfo() {
        cout << "Vehicle Brand: " << Brand << endl;
        cout << "Vehicle Model: " << Model << endl;
        cout << "Daily Rental Fee: $" << RentalPrice << endl;
        cout << "Current Status: " << (Availability ? "Available for Booking" : "Currently Unavailable") << endl;
    }
};

int main() {
	Car RentalCar;
	cout << "Vehicle Details:" << endl;
	RentalCar.displayCarInfo();
	RentalCar.RentCar();
	RentalCar.UpdateCarDetails("BMW", "5", 120.0);
	RentalCar.displayCarInfo();
	cout << "\nAfter Booking the Vehicle:\n";
	RentalCar.RentCar();
	RentalCar.displayCarInfo();
}

