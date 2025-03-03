// MeasurementConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int converter() {

    string measure_sys;
    
    // array declaration
    string time_systems[3] = { "AS | Aeon Soterias", "EK | Etous tou Kyriou", "E | Extranor"};
    int arr_length = sizeof(time_systems) / sizeof(time_systems[0]);

    cout << "Enter the system of time measurement you're using." << endl;
    cin >> measure_sys;

    /* 
whatever value measure_sys is should correspond to an element in time_systems[]. this means 
     */

    cout << measure_sys;

    return 0;
}

int main()
{
    converter();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
