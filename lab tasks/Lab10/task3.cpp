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
    string type, id, name, yearStr, extra;
    int year;

    while (getline(file, line)) {
        ss.clear();
        ss.str(line);

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearStr, ',');
        getline(ss, extra);

        try {
            year = stoi(yearStr);
        } catch (invalid_argument&) {
            cout << "Error: Invalid year format in booking entry!" << endl;
            continue;
        }

        cout << "Vehcile Type: " << type << endl;
        cout << "Vehcile ID: " << id << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Booking Year: " << year << endl;
        cout << "Additional Info: " << extra << endl;
        cout << "-------------------------------" << endl;
    }

    file.close();
    return 0;
}
