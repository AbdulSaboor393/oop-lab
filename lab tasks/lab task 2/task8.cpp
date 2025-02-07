#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int** arr = new int*[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = new int;  // Allocate memory for each integer
        cin >> *arr[i];    // Store user input
    }

    cout << "Array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete arr[i];  // Free memory for each integer
    }
    delete[] arr;  // Free memory for the array of pointers

    return 0;
}
