#include<iostream>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual void applyDiscount(double discountPercentage) {
        price -= price * (discountPercentage / 100);
    }

    virtual double calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Available: " << stockQuantity << " units" << endl;
    }

    double getPrice() const { return price; }
    
    friend double operator+(const Product &p1, const Product &p2) {
        return p1.price + p2.price;
    }

    friend ostream &operator<<(ostream &os, const Product &p) {
        p.displayProductInfo();
        return os;
    }
};

class Electronics : public Product {
protected:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int wp, string br) 
        : Product(id, name, p, stock), warrantyPeriod(wp), brand(br) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Warranty: " << warrantyPeriod << " years" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
protected:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fm) 
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fm) {}

    void applyDiscount(double discountPercentage) override {
        price -= price * (discountPercentage / 100);
        cout << "Limited Time Offer: Discount Applied!" << endl;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
protected:
    string expirationDate;
    double calories;

public:
    FoodItem(int id, string name, double p, int stock, string expDate, double cal) 
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Best Before: " << expirationDate << endl;
        cout << "Calories Per Serving: " << calories << " kcal" << endl;
    }

    double calculateTotalPrice(int quantity) override {
        return (quantity > 10) ? price * quantity * 0.9 : price * quantity;
    }
};

int main() {
    Electronics e1(1, "Laptop", 120000, 5, 3, "Dell");
    Clothing c1(2, "T-Shirt", 1500, 30, "L", "Black", "Cotton");
    FoodItem f1(3, "Cereal", 500, 80, "2026-06-15", 180);

    c1.applyDiscount(10);
    cout << "Total cost for 8 cereal packs: $" << f1.calculateTotalPrice(8) << "\n";

    cout << "\nProduct Catalogue:\n";
    cout << e1 << "\n";
    cout << c1 << "\n";
    cout << f1 << "\n";
    
    return 0;
}

