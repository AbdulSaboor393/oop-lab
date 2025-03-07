#include <iostream>
#include <string>
using namespace std;

class Apartment {
    int ID;
    string address;
    string* ownerName;

public:
    Apartment(int id, const string& add, const string& owner) : ID(id), address(add) {
        ownerName = new string(owner);
    }

    Apartment(const Apartment& other) : ID(other.ID), address(other.address), ownerName(new string(*other.ownerName)) {}

    void display() const {
        cout << "Apartment ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << *ownerName << endl;
        cout << "\n" << endl;
    }

    ~Apartment() {
        delete ownerName;
    }
};

int main() {
    string name = "Bonu";
    
    Apartment apartment1(0001, "Landhi", name);
    Apartment apartment2(0002, "D16", name);

    Apartment copiedApartment1 = apartment1;
    Apartment copiedApartment2 = apartment2;

    apartment1.display();
    apartment2.display();
    copiedApartment1.display();
    copiedApartment2.display();

    return 0;
}

