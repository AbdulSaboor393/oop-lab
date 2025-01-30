#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int n_max = 5;  
    int n;

    cout << "Enter the number of students to register (up to " << n_max << "): ";
    cin >> n;

    
    if (n > n_max || n <= 0) {
        cout << "Invalid number of students. Please enter a value between 1 and " << n_max << "." << endl;
        return 1; 
    }

    cin.ignore(); 
   
    string event_1[n_max] = {};
    string event_2[n_max] = {};

    
    cout << "Enter " << n << " names to register in the first event: " << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, event_1[i]);
    }

    
    cout << "Enter " << n << " names to register in the second event: " << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, event_2[i]);
    }
    return 0;
}