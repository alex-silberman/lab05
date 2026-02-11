#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

int main ( int argc, char *argv[] ) {

    if (argc != 3) {
        cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
        exit(1);
    }

    string option = argv[1];
    string value = argv[2];

    if (option == "d2b") {

        //Convert decimal string to binary string
        string out = dec2bh(value, 'b');
        cout << "The value in binary is: " << out << endl;

    } 
    else if (option == "d2h") {

        //Convert decimal string to hexadecimal string
        string out = dec2bh(value, 'h');
        cout << "The value in hexadecimal is: " << out << endl;

    } 
    else if (option == "b2d") {

        // Convert binary string to decimal int; if invalid, print error
        int out = bin2d(value);
        if (out == -1) {
            cout << "Binary value contains non-binary digits." << endl;
            exit(1);
        }
        cout << "The value in decimal is: " << out << endl;

    } 
    else {

        cout << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
        exit(1);
    }

    return 0;
}

// Pre-Condition: sdec is a decimal integer value as a string, bh is 'b' or 'h'.
// Post-Condition: Returns the binary or hex equivalent as a string.
string dec2bh(string sdec, char bh) {
    int dec = 0;
    bool neg = false;
    int i = 0;

    if (sdec.size() > 0 && sdec[0] == '-') {
        neg = true;
        i = 1;
    }

    for (; i < (int)sdec.size(); i++) {
    dec = dec * 10 + (sdec[i] - '0');
    }
    if (dec == 0)
       return "0"; 

    if (bh == 'b') {
        string result = "";
        while (dec > 0) {
            int r = dec % 2;
            char digit = (char)('0' + r);
            result = digit + result;
            dec /= 2;
        }
        if (neg) result = "-" + result;
        return result;
    }

    string result = "";
    while (dec > 0) {
        int r = dec % 16;
        char digit;
        if (r < 10) digit = (char)('0' + r);
        else digit = (char)('A' + (r - 10));
        result = digit + result;
        dec /= 16;
    }
    if (neg) result = "-" + result;
    return result;
}

// Pre-Condition: binstring contains a string of 0s and 1s.
// Post-Condition: Returns the decimal int value; returns -1 if any character is not '0' or '1'.
int bin2d(string binstring) {
    int n = (int)binstring.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        char c = binstring[i];
        if (c != '0' && c != '1') return -1;
    }

    int power = 0;
    for (int i = n - 1; i >= 0; i--) {
        int bit = binstring[i] - '0';
        sum += (int)(bit * pow(2, power));
        power++;
    }
    return sum;
}