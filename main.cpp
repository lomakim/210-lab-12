// COMSC-210 | Lab 12 | Loma Kim
/* This program has an hrsGaming array which holds hours spent 
   playing video games per day for the last 30 days */
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    // DECLARATIONS
    const int SIZE = 30;
    array <double, SIZE> hrsGaming;

    ifstream fin;
    fin.open("file.txt");

    for(int i = 0; i < SIZE; i++){
        fin >> hrsGaming[i];
        cout << "Day " << i + 1 << ": " << hrsGaming[i] << endl;
    }

    
    fin.close();
    return 0;
}