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

    //cout << "\nTotal Hours Played: " 
    //     << accumulate(hrsGaming.begin(), hrsGaming.end(), 0) << endl;
    cout << "Minimum hours played: "
         << *min_element(hrsGaming.begin(), hrsGaming.end()) << endl;


    
    fin.close();
    return 0;
}