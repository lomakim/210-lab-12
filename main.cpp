// COMSC-210 | Lab 12 | Loma Kim
/* This program has an hrsGaming array which holds hours spent 
   playing video games per day for the last 30 days */
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    // DECLARATIONS
    const int SIZE = 30;
    double target = 0.0;    // Used to search for values
    int count;              // Used to count in range loop
    

    array <double, SIZE> hrsGaming;

    ifstream fin;
    fin.open("file.txt");

    // Banner
    cout << "**** HOURS GAMING CALCULATOR (PAST 30 DAYS) ****" << endl << endl;

    // Read hours in file into array and print
    for(int i = 0; i < SIZE; i++){
        fin >> hrsGaming[i];
        cout << "Day " << i + 1 << ": " << hrsGaming[i] << "\t";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }

    // Declare iterator to find elements
    array<double, SIZE>::iterator loc;
    
    // Find total hours played
    cout << "\nYou played a total of "
         << accumulate(hrsGaming.begin(), hrsGaming.end(), 0)
         << " hours in the past 30 days." << endl;
    
    // Find lowest number of hours and location
    target = *min_element(hrsGaming.begin(), hrsGaming.end());
    loc = find(hrsGaming.begin(), hrsGaming.end(), target);
    cout << "Lowest number of hours played was on day "
         << loc - hrsGaming.begin() << " with " << target
         << " hours played." << endl;

    // Find highest number of hours and location
    target = *max_element(hrsGaming.begin(), hrsGaming.end());
    loc = find(hrsGaming.begin(), hrsGaming.end(), target);
    cout << "Highest number of hours played was on day "
         << loc - hrsGaming.begin() << " with " << target
         << " hours played." << endl;

    // Create duplicate array for sorting and copy in values
    array <double, SIZE> sortArr;
    for(int i = 0; i < SIZE; i++) {
        sortArr[i] = hrsGaming[i];
    }

    // Sort the sorting arr from low to high then print
    sort(sortArr.begin(), sortArr.end());
    cout << "\nHours sorted from low to high:" << endl;
    for(double val : sortArr) {
        count = 0;
        cout << val << "\t";
        if((count + 1) % 3 == 0)
            cout << endl;
        count++;
    }
    cout << endl << endl;

    // Reverse sort from high to low then print
    sort(sortArr.rbegin(), sortArr.rend());
    cout << "Hours sorted from high to low:" << endl;
    for(double val : sortArr) {
        count = 0;
        cout << val << "\t";
        if((count + 1) % 3 == 0)
            cout << endl;
        count++;
    }
    cout << endl << endl;

    // Search for value decided by user input
    target = 0;
    while (target != -1){
        cout << "\nEnter a value you would like to search for (or -1 to end): ";
        cin >> target;
        loc = find(hrsGaming.begin(), hrsGaming.end(), target);
        if (loc != hrsGaming.end()) {
            cout << target << " hours were played on day " 
                 << loc - hrsGaming.begin() << "." << endl;
        }
        else {
            cout << "There were no days in the past 30 days where "
                 << target << " hours were played." << endl;
        }
    }


    fin.close();    // close file
    return 0;
}