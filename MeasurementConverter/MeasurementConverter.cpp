/*

PREFACE:
This is messy and overly complicated. If you are reading this, tear it apart and tell me what to make better. You don't have to read the project background.

-----------------------------------------------------

BRIEF Project background:

This is for a game concept I've been working on for some time. I've been writing so much I may as well scrap the "game" idea and just turn it into a book.

This beaut' Olir-based chronological measurement converter.

Within Olir are two species: Hemitheons and their weaker counterparts, Humans. Both species naturally have their own cultures and traditions. Within these cultures are different methods of measuring history.

- Hemitheons utilize the "AS" ("Aeon Soterias", trans. "Age of Salvation") counting system, which starts counting the years following the preservation of their fallen god, Nea.

- Humans utilize the "EK" ("Etous tou Kyriou", trans. "Year of our Lord") counting system, which starts counting the years following the arrival of Khemithras, the falsely-proclaimed, Hemitheonic god of mankind.

- Both species passively make use of "E" ("Extranor", trans. "Existence") as a way of determining how long existence has...existed.

Olir is the world I've created, upon which this all takes place.

-----------------------------------------------------

I will definitely be updating the conversion constants and the offset between each chronological system.

For the sake of "immersion", the current narrative date is 8031 AS, 7020 EK, or 20909 E.


Thanks for reading. If you have any critiques I would be elated to hear them.


By Amari Coleman
*/



#include <iostream>
#include <string>
using namespace std;

int converter() {

    // int variables used throughout the code in respective order of where they're used
    int src_index;
    int src_index_fix = 0;
    int target_index;
    int target_index_fix = 0;
    int years;
    int result = 0;

    // for printing out the str elements of the chosen systems
    string first_sys;
    string sec_sys;

    // constants for matrix values
    const int AS_TO_EK_SUB = 1011;
    const int EK_TO_AS_ADD = 1011;
    const int E_TO_AS_SUB = 12878;
    const int E_TO_EK_SUB = 13889;
    const int AS_TO_E_ADD = 12878;
    const int EK_TO_E_ADD = 13889;

    // constant for array length. just in case i need to change it later. easier to have it here
    const int ARR_LENGTH = 3;

    // array declaration
    string time_systems_expanded[ARR_LENGTH] = { "Aeon Soterias", "Etous tou Kyriou", "Extranor" };
    string time_systems[ARR_LENGTH] = { "AS", "EK", "E" };

    struct ConversionMatrix {
        int data[ARR_LENGTH][ARR_LENGTH]; // declares a 2D array member of the struct ConversionMatrix with a 3x3 matrix
    };

    const ConversionMatrix conversion_data = { // declares a conversion_data instance inside struct
    {
        {0, -AS_TO_EK_SUB, AS_TO_E_ADD}, // value initialization within the matrix
        {EK_TO_AS_ADD, 0, EK_TO_E_ADD},
        {-E_TO_AS_SUB, -E_TO_EK_SUB, 0}
    }
    };

    // this displays the expanded names of the chronological systems using a range based for loop
    int expanded_counter = 1;
    cout << "Chronological Systems: \n";
    for (const string& expand_element : time_systems_expanded) {
        cout << expanded_counter << ". " << expand_element << " " << endl;
        expanded_counter++;

    }



    while (true) {

        cout << "Enter a non-negative amount of years you're converting: " << endl;

        // input type checker for years. just makes sure it's not anyting other an a positive int
        if (!(cin >> years) || years < 0) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        // error catch
        if (years > 0) {
            cout << "You selected: " << years << endl;
        }

        while (true) {
            cout << "Enter the time system you'd like to convert " << years << " years from (1-3): " << endl;
            int i = 1;
            for (const string& element : time_systems) { // iterates through the element with a range based for loop and prints each element. i is just a counter prefix
                cout << i << ": " << element << endl;
                i++;
            }

            // input type checker. just prompts for re-input if user enters anything other than a positive int that's beyond the length of the array
            if (!(cin >> src_index) || src_index < 0 || src_index > ARR_LENGTH) {
                cout << "Invalid input." << endl;
                cin.clear(); // cool input fail state functions
                cin.ignore(10000, '\n');
                continue;
            }

            // checks if sys_index is within the range of time_systems[] then "fixes" the inputted index by adjusting it to the actual length of the array
            if (src_index >= 1 && src_index <= ARR_LENGTH) {
                src_index_fix = src_index - 1;
                first_sys = time_systems[src_index_fix];
                cout << "You selected: " << first_sys << endl;
            }
            else {
                cout << "Invalid input." << endl;
            }

            while (true) {

                cout << "Enter the time system you'd like to convert " << years << " " << first_sys << " to (1-3): " << endl;

                int i = 1;
                for (const string& element : time_systems) { // iterates through the element with a range based for loop and prints each element. i is just a counter prefix
                    cout << i << ": " << element << endl;
                    i++;
                }

                // more fail state error catching and general enforcement
                if (!(cin >> target_index) || target_index < 0 || target_index > ARR_LENGTH) {
                    cout << "Invalid input." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                // 
                if (target_index >= 1 && target_index <= ARR_LENGTH) {
                    target_index_fix = target_index - 1; // additional index "fixing". this applies similar fundamentals as the first system input
                    sec_sys = time_systems[target_index_fix]; // this just assigns whatever str element is in the "fixed" index
                    cout << "You selected: " << sec_sys << endl;

                    result = years + conversion_data.data[src_index_fix][target_index_fix]; // prep for final conversion. assigns result to the value of years + the offset. pulling data from the struct member conversion_data with the array data[]. parameters are the first "fixed" index and the second (target) "fixed" index

                    if (result > 0) { // this is just doesn't print this if it's below 0
                        cout << "\nConverted " << years << " " << first_sys << " to " << result << " " << sec_sys << endl;
                        return 0;
                    }
                }
                if (result < 0) { // shows the user how many years are left until their chosen chronological system exists
                    cout << "Your chosen system of " << sec_sys << " will exist in " << result * -1 << " years." << endl;
                    return 0;
                }
            }
        }





    } while (true);

    // ok now i somehow have to make comparisons between first_sys and the second system of chronological measurement. i'm thinking of doing a for loop to compare the first_sys to another sys

    return 0;
}

int main()
{
    converter();

}