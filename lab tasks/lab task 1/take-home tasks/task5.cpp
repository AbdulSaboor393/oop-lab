#include <iostream>
#include <string>
using namespace std;

const int DAYS = 28;
const int CITIES = 4;
const int WEEKS = 4;

void calculateWeeklyAverages(int aqi[DAYS][CITIES], float weeklyAvg[WEEKS][CITIES]) {
    for (int city = 0; city < CITIES; city++) {
        for (int week = 0; week < WEEKS; week++) {
            int sum = 0;
            for (int day = week * 7; day < (week + 1) * 7; day++) {
                sum += aqi[day][city];
            }
            weeklyAvg[week][city] = sum / 7.0;
        }
    }
}

void calculateMonthlyAverages(float weeklyAvg[WEEKS][CITIES], float monthlyAvg[CITIES]) {
    for (int city = 0; city < CITIES; city++) {
        float sum = 0;
        for (int week = 0; week < WEEKS; week++) {
            sum += weeklyAvg[week][city];
        }
        monthlyAvg[city] = sum / 4.0;
    }
}

void findExtremeAQI(int aqi[DAYS][CITIES], int highestAQI[CITIES], int lowestAQI[CITIES], int highDay[CITIES], int lowDay[CITIES]) {
    for (int city = 0; city < CITIES; city++) {
        highestAQI[city] = aqi[0][city];
        lowestAQI[city] = aqi[0][city];
        highDay[city] = 1;
        lowDay[city] = 1;

        for (int day = 1; day < DAYS; day++) {
            if (aqi[day][city] > highestAQI[city]) {
                highestAQI[city] = aqi[day][city];
                highDay[city] = day + 1;
            }
            if (aqi[day][city] < lowestAQI[city]) {
                lowestAQI[city] = aqi[day][city];
                lowDay[city] = day + 1;
            }
        }
    }
}

void findMostImprovedCity(float weeklyAvg[WEEKS][CITIES]) {
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};
    int mostImprovedCity = 0;
    float maxDrop = weeklyAvg[0][0] - weeklyAvg[3][0];

    for (int city = 1; city < CITIES; city++) {
        float drop = weeklyAvg[0][city] - weeklyAvg[3][city];
        if (drop > maxDrop) {
            maxDrop = drop;
            mostImprovedCity = city;
        }
    }

    cout << "\nThe city with the most improved air quality is: " << cities[mostImprovedCity]
         << " with an AQI drop of " << maxDrop << " between the first and last weeks.\n";
}

void displayCriticalDays(int aqi[DAYS][CITIES]) {
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};
    cout << "\nCritical Pollution Days (AQI > 150):\n";

    for (int city = 0; city < CITIES; city++) {
        cout << cities[city] << ": ";
        bool found = false;
        for (int day = 0; day < DAYS; day++) {
            if (aqi[day][city] > 150) {
                cout << "Day " << (day + 1) << " (" << aqi[day][city] << "), ";
                found = true;
            }
        }
        if (!found) cout << "None";
        cout << endl;
    }
}

void generateReport(int aqi[DAYS][CITIES]) {
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};

    float weeklyAvg[WEEKS][CITIES];
    float monthlyAvg[CITIES];
    int highestAQI[CITIES], lowestAQI[CITIES], highDay[CITIES], lowDay[CITIES];

    calculateWeeklyAverages(aqi, weeklyAvg);
    calculateMonthlyAverages(weeklyAvg, monthlyAvg);
    findExtremeAQI(aqi, highestAQI, lowestAQI, highDay, lowDay);

    cout << "\n===== AIR QUALITY REPORT =====\n";
    cout << "\nWeekly and Monthly AQI Averages:\n";
    cout << "------------------------------------------------------\n";
    cout << "City      | Week 1 | Week 2 | Week 3 | Week 4 | Monthly Avg\n";
    cout << "------------------------------------------------------\n";
    for (int city = 0; city < CITIES; city++) {
        cout << cities[city] << "  | ";
        for (int week = 0; week < WEEKS; week++) {
            cout << weeklyAvg[week][city] << "  | ";
        }
        cout << monthlyAvg[city] << endl;
    }

    findMostImprovedCity(weeklyAvg);
    displayCriticalDays(aqi);

    cout << "\nHighest and Lowest AQI Values:\n";
    cout << "-----------------------------------------\n";
    cout << "City      | Highest AQI | Day | Lowest AQI | Day\n";
    cout << "-----------------------------------------\n";
    for (int city = 0; city < CITIES; city++) {
        cout << cities[city] << "  | " << highestAQI[city] << "  | Day " << highDay[city] 
             << "  | " << lowestAQI[city] << "  | Day " << lowDay[city] << endl;
    }
    cout << "\n===== END OF REPORT =====\n";
}

int main() {
    int aqi[DAYS][CITIES] = {
        {267, 168, 371, 454}, {351, 264, 101, 296}, {249, 56, 393, 129}, {463, 321, 488, 160},
        {88, 74, 367, 285}, {163, 129, 465, 187}, {348, 64, 389, 401}, {212, 178, 345, 399},
        {390, 280, 89, 270}, {240, 90, 400, 150}, {455, 329, 470, 162}, {92, 80, 300, 276},
        {178, 140, 410, 190}, {360, 70, 390, 410}, {287, 170, 375, 432}, {350, 255, 150, 290},
        {250, 85, 420, 145}, {460, 320, 475, 158}, {85, 72, 360, 280}, {160, 127, 460, 180},
        {340, 60, 380, 395}, {205, 165, 335, 390}, {375, 265, 92, 268}, {245, 95, 395, 148},
        {445, 325, 465, 161}, {90, 78, 305, 273}, {175, 135, 405, 188}, {355, 68, 395, 408}
    };
    generateReport(aqi);
    return 0;
}
