#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

class Car{
	private:
		string Brand;
		string Model;
		float RentalPrice;
		bool Availability;
	public:
	Car(){
		Brand= "unknown";
		Model= "Generic";
		RentalPrice=0.0;
		Availability= true;
	}
	void UpdateCarDetails(string BrandName,string ModelName,float RentPrice){
		Brand = BrandName;
        Model = ModelName;
		RentalPrice=RentPrice;
	}
	void RentCar(){
		if(Availability){
			Availability= false;
			cout<<"You have rented the car\n"<<endl;
		}
		else{
			cout<<"The car is already Rented\n"<<endl;
		}
	}
	 void displayCarInfo() {
        cout << "Car Brand: " << Brand <<endl;
        cout << "Car Model: " << Model <<endl;
        cout << "Rental Price: $" << RentalPrice <<endl;
        cout << "Availability: " << (Availability ? "Car is Available" : "Sorry,The Car is Rented") <<endl;
    }
};


int main(){
	Car Product1;
	cout<< "Car Details"<<endl;
	Product1.displayCarInfo();
	Product1.RentCar();
	Product1.UpdateCarDetails("Honda","City",100.0);
	Product1.displayCarInfo();
	cout << "\nAfter Renting the Car:\n";
	Product1.RentCar();
	Product1.displayCarInfo();
	
}
