#include <iostream>
using namespace std;
void calculateAverages(int aqi[7][4], float averages[4])
{
    for (int city = 0; city < 4; city++)
    {
        int sum = 0;
        for (int days = 0; days < 7; days++)
        {
            sum += aqi[days][city];
        }
        averages[city] = sum / 7.0;
    }
}
void displayResults(float averages[4])
{
    string cities[4] = {"City A", "City B", "City C", "City D"};
    cout << "Averages for city over the week are:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << cities[i] << ": " << averages[i] << endl;
    }
    int heighestaqi = 0;
    for (int i = 0; i < 4; i++)
    {
        if (averages[i] > averages[heighestaqi])
        {
            heighestaqi = i;
        }
    }
    cout << "the city having worst air quality index is: (" << cities[heighestaqi] << ") with the average aqi: " << averages[heighestaqi] << endl;
}
void criticalpollutionDays(int aqi[7][4])
{
    string cities[4] = {"City A", "City B", "City C", "City D"};
    cout << "Critical pollution days" << endl;
    bool hascriticaldays = false;
    for (int city = 0; city < 4; city++)
    {
        for (int days = 0; days < 7; days++)
        {
            if (aqi[days][city] > 150)
            {
                cout << "Day " << (days + 1) << " in " << cities[city] << " had AQI " << aqi[days][city] << endl;
                hascriticaldays = true;
            }
        }
    }
    if (!hascriticaldays)
    {
        cout << "No critical pollution days found." << endl;
    }
}
void dataVisualisation(int aqi[7][4]){
      string cities[4] = {"City A", "City B", "City C", "City D"};
      cout<<"AQI data visualization (Each * shows an increment of 50 in aqi)"<<endl;
    for (int city = 0; city < 4; city++)
    {   cout<<cities[city]<<":"<<endl;
        for (int days = 0; days < 7; days++)
        {
           int star = aqi[days][city] / 50;
            cout<<"Day "<<(days+1)<<":"<<endl;
            for (int i = 0; i < star; i++)
            {
                cout<<"*"; 
            }
            cout<<endl;
        }
        
    }
    
}
int main()
{
    int aqi[7][4] = {{267, 168, 371, 454},
                     {351, 264, 101, 296},
                     {249, 56, 393, 129},
                     {463, 321, 488, 160},
                     {88, 74, 367, 285},
                     {163, 129, 465, 187},
                     {348, 64, 389, 401}};
    float averages[4];
    calculateAverages(aqi, averages);
    displayResults(averages);
    criticalpollutionDays(aqi);
    dataVisualisation(aqi);
    return 0;
} 