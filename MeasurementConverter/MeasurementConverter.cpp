// MeasurementConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int converter() {

    int src_index;
    int src_index_fix = 0;
    int target_index;
    int target_index_fix = 0;
    int checkpoint = 0;
    int checkpoint_two = 0;
    int years;
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

    const int AS_TO_EK_SUB = 1011;
    const int EK_TO_AS_ADD = 1011;
    const int E_TO_AS_SUB = 12878;
    const int E_TO_EK_SUB = 13889;
    const int AS_TO_E_ADD = 12878;
    const int EK_TO_E_ADD = 13889;

    const int ARR_LENGTH = 3;

    // array declaration
    string time_systems[ARR_LENGTH] = { "AS | Aeon Soterias", "EK | Etous tou Kyriou", "E  | Extranor" };

    // conversion matrix

    struct ConversionMatrix {
        int data[ARR_LENGTH][ARR_LENGTH];
    };

    const ConversionMatrix conversion_data = {
    {
        {0, -AS_TO_EK_SUB, AS_TO_E_ADD},
        {EK_TO_AS_ADD, 0, EK_TO_E_ADD},
        {-E_TO_AS_SUB, -E_TO_EK_SUB, 0}
    }
    };

    // range-based for loop to print out the elements of the time_systems[] array


    int i = 1;
    for (const string& element : time_systems) {
        cout << i << ": " << element << endl;
        i++;
    }

    do
    {


        cout << "Enter a non-negative amount of years you're converting: " << endl;

        // input type checker for years
        if (!(cin >> years) || years < 0) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (years > 0) {
            cout << "You selected: " << years << endl;
        }




        cout << "Enter the time system you'd like to convert from (1-3): " << endl;

        // input type checker. just prompts for re-input if user enters anything other than an int
        if (!(cin >> src_index) || src_index < 0) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // checks if sys_index is within the range of time_systems[] 
        if (src_index >= 1 && src_index <= ARR_LENGTH) {
            src_index_fix = src_index - 1;
            first_sys = time_systems[src_index_fix];
            cout << "You selected: " << first_sys << endl;
        }
        else {
            cout << "Invalid input." << endl;
        }


        cout << "Enter the time system you'd like to convert to (1-3): " << endl;

        if (!(cin >> target_index)) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (target_index >= 1 && target_index <= ARR_LENGTH && target_index != src_index) {
            target_index_fix = target_index - 1;
            sec_sys = time_systems[target_index_fix];
            cout << "You selected: " << sec_sys << endl;
            result = years + conversion_data.data[src_index_fix][target_index_fix];
            cout << "\nConverted " << years << " " << src_index_fix << " to " << result << " " << target_index_fix << endl;
            continue;

        }




    } while (true);

    // ok now i somehow have to make comparisons between first_sys and the second system of chronological measurement. i'm thinking of doing a for loop to compare the first_sys to another sys

    return 0;
}

int main()
{
    converter();

}