#include <iostream>
#include <string>
using namespace std;

class Product {
    int id;
    string name;
    int quantity;

public:
    Product(int pid, string pname, int quan) : id(pid), name(pname), quantity(quan) {}

    int getID() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void displayProduct() const {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product Quantity: " << quantity << endl;
    }
};

class Warehouse {
    Product** products;
    int productCount;
    int limit;

public:
    Warehouse(int lim) : limit(lim), productCount(0) {
        products = new Product*[limit];
    }

    void addProduct(int pid, string pname, int quan) {
        if (productCount < limit) {
            products[productCount] = new Product(pid, pname, quan);
            productCount++;
        } else {
            cout << "Warehouse is full. Cannot add more products." << endl;
        }
    }

    void searchByID(int id) const {
        bool found = false;
        for (int i = 0; i < productCount; i++) {
            if (products[i]->getID() == id) {
                products[i]->displayProduct();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Product with ID " << id << " not found." << endl;
        }
    }

    void displayAllProducts() const {
        for (int i = 0; i < productCount; i++) {
            products[i]->displayProduct();
            cout << endl;
        }
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (products[j]->getName() > products[j + 1]->getName()) {
                    Product* temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
        displayAllProducts();
    }

    ~Warehouse() {
        for (int i = 0; i < productCount; i++) {
            delete products[i];
        }
        delete[] products;
    }
};

int main() {
    Warehouse warehouse(5);

    warehouse.addProduct(001, "Washing Machine", 10);
    warehouse.addProduct(002, "Refrigerator", 20);
    warehouse.addProduct(003, "Microwave", 15);
    warehouse.addProduct(004, "Dishwasher", 8);
    warehouse.addProduct(005, "Blender", 25);

    warehouse.sortProducts();

    warehouse.searchByID(001);
    warehouse.searchByID(005);

    return 0;
}

