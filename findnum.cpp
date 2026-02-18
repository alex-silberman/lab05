#include <iostream>
#include <fstream>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
int FindNum(ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // find the 2nd largest int and print it
    cout << FindNum(ifs) << endl;
    
    ifs.close();
    return 0;
}

// DEFINE FUNCTION HERE. 
// Include Pre-Condition and Post-Condition comments.
// Pre-condition: ifs is open and contains at least two integers.
// Post-condition: returns the second largest integer in the file.
int FindNum(ifstream &ifs) {
    int x;
    int largest, secondLargest;

    ifs >> largest;
    ifs >> secondLargest;

    if (secondLargest > largest) {
        int temp = largest;
        largest = secondLargest;
        secondLargest = temp;
    }

    while (ifs >> x) {
        if (x > largest) {
            secondLargest = largest;
            largest = x;
        }
        else if (x > secondLargest && x != largest) {
            secondLargest = x;
        }
    }

    return secondLargest;
}