#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings you want to store: ";
    cin >> n;

    string* arr = new string[n];

    cout << "Enter the strings:" << endl;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
