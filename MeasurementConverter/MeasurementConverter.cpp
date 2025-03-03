// MeasurementConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int converter() {

    int sys_index;
    int sys_index_fix;
    int sec_sys_index; 
    int sec_sys_i_fix;
    int year;
    int result; 


    // for when i implement converted year output
#if 0
    if (result <= 0) {
        cout << sec_sys << " does not exist at the time of " << year << " " << first_sys << endl;
    }
#endif // 0



    string first_sys;
    string sec_sys;
    string first_prompt = "Enter a time system you'd like to use to convert from (1-3): ";
    string second_prompt = "\n\nEnter the time system you'd like to convert to (1-3): ";
    string third_prompt = "Enter the number of years you're converting: ";

    const int AS_TO_EK = 1011; // subtract constant
    const int EK_TO_AS = 1011; // add constant
    const int E_TO_AS = 12878; // subtract constant
    const int E_TO_EK = 13889; // subtract constant
    const int AS_TO_E = 12878; // add constant
    const int EK_TO_E = 13889; // add constant
  
    // array declaration
    string time_systems[] = { "AS | Aeon Soterias", "EK | Etous tou Kyriou", "E  | Extranor"};

    // conversion matrix
    double conversion_data[3][3] = {
        {0, -AS_TO_EK, AS_TO_E},
        {EK_TO_AS, 0, EK_TO_E},
        {-E_TO_AS, -E_TO_EK, 0}
    };
    
    // range-based for loop to print out the elements of the time_systems[] array
    
    int i = 1;
    for (string& element : time_systems) {
        cout << i << ": " << element << endl;
        i++;
    }

    do
    {
        cout << first_prompt << endl;

        // input type checker. just prompts for re-input if user enters anything other than an int
        if (!(cin >> sys_index)){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // checks if sys_index is within the range of time_systems[] 
        if (sys_index >= 1 && sys_index <= size(time_systems)) {
            sys_index_fix = sys_index - 1;
            first_sys = time_systems[sys_index_fix];
            cout << "You selected: " << first_sys << endl;
        }
        else if (sys_index > size(time_systems)) {
            cout << "Invalid input." << endl;
            continue;
        }


        cout << second_prompt << endl;

        if (!(cin >> sec_sys_index)){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (sec_sys_index >= 1 && sec_sys_index <= size(time_systems) && sec_sys_index != sys_index) {
            sec_sys_i_fix = sec_sys_index - 1;
            sec_sys = time_systems[sec_sys_i_fix];
            cout << "You selected: " << sec_sys << endl;
            break;

        }


    } while (true);

    // ok now i somehow have to make comparisons between first_sys and the second system of chronological measurement. i'm thinking of doing a for loop to compare the first_sys to another sys

    return 0;
}

int main()
{
    converter();

}