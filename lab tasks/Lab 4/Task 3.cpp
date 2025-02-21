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
	Car() {
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

	Car(const Car &c) {
		Brand = c.Brand;
		Model = c.Model;
		RentalPrice = c.RentalPrice;
		Availability = c.Availability;
	}

	~Car() {
		cout << "Destroying Car: " << Brand << " " << Model << endl;
	}

	void UpdateCarDetails(string BrandName, string ModelName, float RentPrice) {
		Brand = BrandName;
		Model = ModelName;
		RentalPrice = RentPrice;
	}

	void displayCarInfo() {
		cout << "\nVehicle Make: " << Brand << endl;
		cout << "Vehicle Model: " << Model << endl;
		cout << "Daily Rental Rate: $" << RentalPrice << endl;
		cout << "Current Availability: " << (Availability ? "Available for Rent" : "Already Rented") << endl;
	}
};

int main() {
	Car firstCar("Ford", "Mustang", 75.0, true);
	cout << "Initial Vehicle Details:" << endl;
	firstCar.displayCarInfo();

	Car secondCar = firstCar;
	firstCar.UpdateCarDetails("Nissan", "Altima", 90.0);
	
	cout << "\nModified Vehicle Details:" << endl;
	firstCar.displayCarInfo();

	cout << "\nDuplicated Vehicle Details:" << endl;
	secondCar.displayCarInfo();

	return 0;
}

