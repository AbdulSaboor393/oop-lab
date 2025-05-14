#include <iostream>
#include <exception>

using namespace std;

class BelowAbsoluteZero : public exception {};

template <typename T>
T convertToF(T celsius) {
    if (celsius < static_cast<T>(-273.15)) {
        throw BelowAbsoluteZero();
    }
    return (celsius * static_cast<T>(1.8)) + static_cast<T>(32);
}

int main() {
    try {
        cout << "Attempting conversion of -300°C..." << endl;
        double fahrenheit = convertToF(-300.0);
        cout << "Result: " << fahrenheit << "°F" << endl;
    } catch (BelowAbsoluteZero& ex) {
        cout << "Error: Temperature is below absolute zero!" << endl;
        cout << "Exception: " << ex.what() << endl;
    }

    return 0;
}
