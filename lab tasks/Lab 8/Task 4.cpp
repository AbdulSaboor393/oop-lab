#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice);
    void displayDetails(const Car& car);
};

class Car {
private:
    string model;
    double price;

public:
    Car(string model, double price) : model(model), price(price) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
}

void InventoryManager::displayDetails(const Car& car) {
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price)
        cout << car1.model << " is more expensive." << endl;
    else if (car1.price < car2.price)
        cout << car2.model << " is more expensive." << endl;
    else
        cout << "Both cars are priced equally." << endl;
}

int main() {
    Car car1("BMW", 24534);
    Car car2("Civic", 54532);

    InventoryManager manager;
    manager.displayDetails(car1);
    manager.displayDetails(car2);

    manager.updatePrice(car1, 32000);
    cout << "After updating car1's price:" << endl;
    manager.displayDetails(car1);

    comparePrice(car1, car2);

    return 0;
}


