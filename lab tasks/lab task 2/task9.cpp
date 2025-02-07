#include <iostream>
#include <string>

using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    float price;
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product* inventory = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for product " << i + 1 << ":" << endl;
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        cin.ignore();
        cout << "Name: ";
        getline(cin, inventory[i].name);
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        cout << "Price: ";
        cin >> inventory[i].price;
    }

    float totalValue = 0;
    cout << "\nProduct Inventory:\n";
    for (int i = 0; i < n; i++) {
        float value = inventory[i].quantity * inventory[i].price;
        totalValue += value;
        cout << "ID: " << inventory[i].productID
             << ", Name: " << inventory[i].name
             << ", Quantity: " << inventory[i].quantity
             << ", Price: $" << inventory[i].price
             << ", Value: $" << value << endl;
    }

    cout << "\nTotal Inventory Value: $" << totalValue << endl;

    delete[] inventory;
    return 0;
}
