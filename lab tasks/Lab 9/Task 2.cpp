#include <iostream>
#include <string>

using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(const string& n, double p) : dishName(n), price(p) {}
    virtual ~MenuItem() {} // Virtual destructor for proper cleanup
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(const string& n, double p) : MenuItem(n, p) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " - $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer: " << dishName << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(const string& n, double p) : MenuItem(n, p) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " - $" << price << endl;
    }

    void prepare() override {
        cout << "Cooking main course: " << dishName << endl;
    }
};

class Dessert : public MenuItem {
public:
    Dessert(const string& n, double p) : MenuItem(n, p) {}

    void showDetails() override {
        cout << "Dessert: " << dishName << " - $" << price << endl;
    }

    void prepare() override {
        cout << "Plating dessert: " << dishName << endl;
    }
};

int main() {
    MenuItem* m1 = new Appetizer("Garlic Bread", 6.99);
    MenuItem* m2 = new MainCourse("Mutton Ribs", 22.50);
    MenuItem* m3 = new Dessert("Chocolate Lava Cake", 6.75);

    m1->showDetails();
    m1->prepare();
    cout << endl;

    m2->showDetails();
    m2->prepare();
    cout << endl;

    m3->showDetails();
    m3->prepare();

    delete m1;
    delete m2;
    delete m3;

    return 0;
}
