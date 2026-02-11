#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {

    // Get full target string
    string target;
    cout << "Enter string to split:" << endl;
    getline(cin, target);

    // Get delimiter
    string delimiter;
    cout << "Enter delimiter string:" << endl;
    getline(cin, delimiter);

    // Call split function
    vector<string> parts = split(target, delimiter);

    // If no substrings were extracted
    if (parts.size() == 0) {
        cout << "No substrings." << endl;
        return 0;
    }

    // Print formatted output
    cout << "The substrings are: ";
    for (int i = 0; i < (int)parts.size(); i++) {
        cout << "\"" << parts[i] << "\"";
        if (i != (int)parts.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;

}

// MISSING FUNCTION DEFINITIONS HERE 
// Pre-Condition: delimiter is a single character.
// Post-Condition: Returns a vector of substrings of target separated by delimiter.
vector<string> split(string target, string delimiter) {

    vector<string> result;


    if (delimiter.size() == 0) {
        if (target.size() > 0)
            result.push_back(target);
        return result;
    }

    char d = delimiter[0];
    string current = "";

    // Iterate through target string character by character
    for (int i = 0; i < (int)target.size(); i++) {

        if (target[i] == d) {

            if (current.size() > 0)
                result.push_back(current);

            current = ""; // reset for next substring
        }
        else {
            current += target[i];
        }
    }

    // Add final substring if not empty
    if (current.size() > 0)
        result.push_back(current);

    return result;
}