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
    
    //cout << "\nTotal Hours Played: " 
    //     << accumulate(hrsGaming.begin(), hrsGaming.end(), 0) << endl;
    //cout << "Sum: " << accumulate(hrsGaming.begin(), hrsGaming.end(), 0) << endl;
    
    // Find lowest number of hours and location
    target = *min_element(hrsGaming.begin(), hrsGaming.end());
    loc = find(hrsGaming.begin(), hrsGaming.end(), target);
    cout << "Lowest number of hours played was on day " << loc - hrsGaming.begin()
         << " with " << target << " hrs played." << endl;


    cout << "Highest number of hours played: "
         << *max_element(hrsGaming.begin(), hrsGaming.end()) << endl;

    // Create duplicate array for sorting and copy in values
    array <double, SIZE> sortArr;
    for(int i = 0; i < SIZE; i++) {
        sortArr[i] = hrsGaming[i];
    }

    // Sort the sorting arr from low to high then print
    sort(sortArr.begin(), sortArr.end());
    cout << "Hours sorted from low to high:" << endl;
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


    fin.close();
    return 0;
}