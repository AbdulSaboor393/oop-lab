#include <iostream>
#include <exception>

using namespace std;

class BelowZeroError : public exception {};
class CapacityExceeded : public exception {};

template <typename T>
class StockItem {
    T current;
    T limit;

public:
    StockItem(T maxLimit) : current(0), limit(maxLimit) {}

    void update(T value) {
        if (value < 0) {
            throw BelowZeroError();
        }
        if (value > limit) {
            throw CapacityExceeded();
        }
        current = value;
        cout << "Current stock: " << current << endl;
    }

    T fetch() {
        return current;
    }
};

int main() {
    StockItem<int> product(100);

    try {
        cout << "Trying to assign stock -5\n";
        product.update(-5);
    } catch (BelowZeroError& ex) {
        cout << "Error: Negative stock is invalid.\n";
        cout << "Reason: " << ex.what() << endl;
    }

    try {
        cout << "Trying to assign stock 120\n";
        product.update(120);
    } catch (CapacityExceeded& ex) {
        cout << "Error: Stock exceeds capacity.\n";
        cout << "Reason: " << ex.what() << endl;
    }

    return 0;
}
