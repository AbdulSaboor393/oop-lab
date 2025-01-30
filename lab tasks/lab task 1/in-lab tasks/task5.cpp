#include <iostream>
#include <string>
using namespace std;
void registered(string event_1[], string event_2[], int n)
{
    string s;
    cout << "Enter the name you want to check" << endl;
    getline(cin, s);

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (s == event_1[i] || s == event_2[i])
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Student is registered" << endl;
    }
    else
    {
        cout << "not registered" << endl;
    }
}
int donations(int n)
{
    int donation_per_student = 10;
    int total_students = n * 2;
    int total_donations = total_students * donation_per_student;
    cout << "Total donation is: " << endl
         << total_donations << " $ " << endl;
    return total_donations;
}
void Reverse(string event_1[], string event_2[], int n)
{
    cout << "names in reverse order in the first event are: " << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << event_1[i] << endl;
    }
    cout << "names in reverse order in the second event are: " << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << event_2[i] << endl;
    }
}
void displaybarchat(int counter1, int counter2)
{
    cout << "Event popularity bar chart" << endl;
    cout << "Event1";
    for (int i = 0; i < counter1; i++)
    {
        cout << "*";
    }
    cout << "(" << counter2 << "participants)" << endl;
    cout << "Event2";
    for (int i = 0; i < counter2; i++)
    {
        cout << "*";
    }
    cout << "(" << counter2 << "participants)" << endl;
}
int main()
{
    const int n_max = 5;
    int n;

    cout << "Enter the number of students to register (up to " << n_max << "): ";
    cin >> n;

    if (n > n_max || n <= 0)
    {
        cout << "Invalid number of students. Please enter a value between 1 and " << n_max << endl;
        return 1;
    }

    cin.ignore();

    string event_1[n_max] = {};
    string event_2[n_max] = {};

    cout << "Enter " << n << " names to register in the first event: " << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, event_1[i]);
    }

    cout << "Enter " << n << " names to register in the second event: " << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, event_2[i]);
    }
    
    registered(event_1, event_2, n);
    donations(n);
    Reverse(event_1, event_2, n);
    displaybarchat(n, n);

    return 0;
}
