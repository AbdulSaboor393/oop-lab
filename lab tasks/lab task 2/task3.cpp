#include <iostream>
using namespace std;
struct Employee{
    string name;
    float hours_worked;
    float hourly_rate;
};
void calculateSalary(Employee* p, float &total_salary){
    total_salary = p->hourly_rate*p->hours_worked*4;
    return;

}
int main(){
    int n;
    float total_salary;
    cout<<"Enter the number of employees"<<endl;
    cin>>n;
    Employee* p = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the details of  employee "<<i+1<<endl;
        cout<<"Name: ";
        cin>>p[i].name;
        cout<<"hours worked: ";
        cin>>p[i].hours_worked;
        cout<<"hourly rate: ";
        cin>>p[i].hourly_rate;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"details of employee "<<i+1<<" are: "<<endl;
        cout<<"Name: "<<p[i].name<<endl;
        cout<<"hours worked: "<<p[i].hours_worked<<endl;;
        cout<<"hourly rate: "<<p[i].hourly_rate<<endl;
        calculateSalary(&p[i], total_salary);
        cout<<"Total salary: "<<total_salary<<endl;
    }

    delete[] p;
    
   return 0; 
}