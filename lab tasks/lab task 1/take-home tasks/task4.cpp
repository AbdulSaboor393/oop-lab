#include <iostream>
#include <string>
using namespace std;

const int DAYS = 28; // 4 weeks (7 days per week)
const int CITIES = 4;

// Function to calculate weekly averages
void calculateWeeklyAverages(int aqi[DAYS][CITIES], float weeklyAvg[4][4])
{
    for (int city = 0; city < CITIES; city++)
    {
        for (int week = 0; week < 4; week++)
        {
            int sum = 0;
            for (int day = week * 7; day < (week + 1) * 7; day++)
            {
                sum += aqi[day][city];
            }
            weeklyAvg[week][city] = sum / 7.0;
        }
    }
}

// Function to calculate overall monthly average AQI for each city
void calculateMonthlyAverages(float weeklyAvg[4][CITIES], float monthlyAvg[CITIES])
{
    for (int city = 0; city < CITIES; city++)
    {
        float sum = 0;
        for (int week = 0; week < 4; week++)
        {
            sum += weeklyAvg[week][city];
        }
        monthlyAvg[city] = sum / 4.0;
    }
}

// Function to display the results and identify the city with worst air quality
void displayResults(float monthlyAvg[CITIES])
{
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};

    cout << "\nMonthly Average AQI for each city:\n";
    int highestAQICity = 0;
    for (int i = 0; i < CITIES; i++)
    {
        cout << cities[i] << ": " << monthlyAvg[i] << endl;
        if (monthlyAvg[i] > monthlyAvg[highestAQICity])
        {
            highestAQICity = i;
        }
    }
}

// Function to identify the city with the most improved air quality
void findMostImprovedCity(float weeklyAvg[4][CITIES])
{
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};
    int mostImprovedCity = 0;
    float maxDrop = weeklyAvg[0][0] - weeklyAvg[3][0];

    for (int city = 1; city < CITIES; city++)
    {
        float drop = weeklyAvg[0][city] - weeklyAvg[3][city];
        if (drop > maxDrop)
        {
            maxDrop = drop;
            mostImprovedCity = city;
        }
    }

    cout << "The city with the most improved air quality is: " << cities[mostImprovedCity]
         << " with an AQI drop of " << maxDrop << " between the first and last weeks.\n";
}
int main()
{
    int aqi[DAYS][CITIES] = {
        {267, 168, 371, 454}, {351, 264, 101, 296}, {249, 56, 393, 129}, {463, 321, 488, 160}, {88, 74, 367, 285}, {163, 129, 465, 187}, {348, 64, 389, 401}, {212, 178, 345, 399}, {390, 280, 89, 270}, {240, 90, 400, 150}, {455, 329, 470, 162}, {92, 80, 300, 276}, {178, 140, 410, 190}, {360, 70, 390, 410}, {287, 170, 375, 432}, {350, 255, 150, 290}, {250, 85, 420, 145}, {460, 320, 475, 158}, {85, 72, 360, 280}, {160, 127, 460, 180}, {340, 60, 380, 395}, {205, 165, 335, 390}, {375, 265, 92, 268}, {245, 95, 395, 148}, {445, 325, 465, 161}, {90, 78, 305, 273}, {175, 135, 405, 188}, {355, 68, 395, 408}};

    float weeklyAvg[4][CITIES];
    float monthlyAvg[CITIES];
    calculateWeeklyAverages(aqi, weeklyAvg);
    calculateMonthlyAverages(weeklyAvg, monthlyAvg);

    displayResults(monthlyAvg);
    findMostImprovedCity(weeklyAvg);
}
