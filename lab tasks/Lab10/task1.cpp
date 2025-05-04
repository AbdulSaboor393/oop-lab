#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("Vehicle.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Vehicle.txt could not be opened." << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }
        cout << "Vehcle Entry: " << line << endl;
    }

    inputFile.close();
    return 0;
}
