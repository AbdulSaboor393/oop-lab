#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual double estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}

    double estimateDeliveryTime() override {
        return 1.5;
    }

    void showDetails() override {
        cout << "Air Freight - Tracking#: " << trackingNumber << ", Weight: " << weight << " kg\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}

    double estimateDeliveryTime() override {
        return 4.0;
    }

    void showDetails() override {
        cout << "Ground Shipment - Tracking#: " << trackingNumber << ", Weight: " << weight << " kg\n";
    }
};

int main() {
    Shipment* sh1 = new AirFreight("AIR123", 10.5);
    Shipment* sh2 = new GroundShipment("GRD456", 25.0);

    sh1->showDetails();
    cout << "Estimated Delivery: " << sh1->estimateDeliveryTime() << " days\n\n";

    sh2->showDetails();
    cout << "Estimated Delivery: " << sh2->estimateDeliveryTime() << " days\n";

    delete sh1;
    delete sh2;

    return 0;
}
