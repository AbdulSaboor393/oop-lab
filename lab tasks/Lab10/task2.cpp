#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream file("Booking.txt");

    if (!file.is_open()) {
        cout << "Error opening Booking.txt!" << endl;
        return 1;
    }

    string line;
    stringstream ss;
    string bookingType, bookingID, customerName, bookingYear, additionalInfo;

    while (getline(file, line)) {
        ss.clear();
        ss.str(line);

        getline(ss, bookingType, ',');
        getline(ss, bookingID, ',');
        getline(ss, customerName, ',');
        getline(ss, bookingYear, ',');
        getline(ss, additionalInfo);

        cout << "Booking Type: " << bookingType << endl;
        cout << "Booking ID: " << bookingID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Year: " << bookingYear << endl;
        cout << "Additional Info: " << additionalInfo << endl;
        cout << "-------------------------------" << endl;
    }

    file.close();
    return 0;
}
