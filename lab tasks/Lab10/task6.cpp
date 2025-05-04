#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct BookingRecord {
    int bookingID;
    char customerName[20];
};

int main() {
    BookingRecord bookingOut;
    bookingOut.bookingID = 1001;
    strcpy(bookingOut.customerName, "Alice Smith");

    fstream file("Bookings.dat", ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "Error opening Bookings.dat for writing!" << endl;
        return 1;
    }

    file.write((char*)&bookingOut, sizeof(bookingOut));
    file.close();
    cout << "Booking data written to file successfully." << endl;

    BookingRecord bookingIn;
    file.open("Bookings.dat", ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "Error opening Bookings.dat for reading!" << endl;
        return 1;
    }

    file.read((char*)&bookingIn, sizeof(bookingIn));
    file.close();

    cout << "Retrieved Booking Details:" << endl;
    cout << "Booking ID: " << bookingIn.bookingID << endl;
    cout << "Customer Name: " << bookingIn.customerName << endl;

    return 0;
}

