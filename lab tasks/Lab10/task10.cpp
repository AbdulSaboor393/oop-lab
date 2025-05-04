#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("log_entries.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Error opening log file!" << endl;
        return 1;
    }

    file << "System boot complete\n";
    file << "User login successful\n";
    file << "Configuration loaded\n";
    file << "Diagnostics started\n";

    file.close();

    ifstream file2("log_entries.txt", ios::in);
    if (!file2.is_open())
    {
        cout << "Error opening log file for reading!" << endl;
        return 1;
    }

    file2.seekg(20, ios::beg);
    string line;
    getline(file2, line);
    cout << "Line read from byte position 20: " << line << endl;

    file2.close();
    return 0;
}
