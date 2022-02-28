/*
Author: Sakib Khan
Course: CSCI-135
Instructor: Tong Yi
Assignment: Compare
Asks user to input two dates which
will serve as an interval
and will check which basin had
the higher elevation based on day
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main()
{
    string date;
    string first_date;
    string last_date;
    cout << "Enter starting date: ";
    cin >> first_date;
    cout << "Enter ending date: ";
    cin >> last_date;
    double eastSt, eastEl, westSt, westEl, minimum, maximum;
    int i = 0;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); //exits if file doesn't open
    }
    string junk;        
    getline(fin, junk);
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        if (date  >= first_date && date <= last_date)
        {
            if (eastEl > westEl)
                cout << date << " " << "East" << endl;
            else if (eastEl < westEl)
                cout << date << " " << "West" << endl;
            else
                cout << date << "Equal" << endl;
                //prints 'Equal' if value is the same
        }
        getline(fin,junk);
    }
    fin.close();
    return 0;
}
