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
int donations(int n){
    int donation_per_student = 10;
    int total_students = n * 2;
    int total_donations= total_students * donation_per_student;
    cout<<"Total donation is: "<<endl<<total_donations<< " $ " <<endl;
    return total_donations;

}
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
    registered(event_1, event_2, n);
    donations(n);

    return 0;
}
