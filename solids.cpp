//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
#include <cstdlib>
using namespace std;

// <Return type> <function name>([arguments])
double platonicvol(int faces, int side) {
    double volume = 0;
    double side3 = side * side * side;
    // Switch statement is exactly like Javascript,
    // except you can only switch on an integer
    switch (faces) {
        case 4:     volume = side3 * sqrt(2) / 12;
                    break;
        case 6:     volume = side3;
                    break;
        case 8:     volume = side3 * sqrt(2) / 3;
                    break;
        case 12:    volume = side3 * (15 + 7*sqrt(5)) / 4;
                    break;
        case 20:    volume = side3 * (3 + sqrt(5)) * 5 / 12;
                    break;      
    }
    return volume;
}

double platonicvolif(int faces, int side) {
    double volume = 0;
    double side3 = side * side * side;
    // If-then-else is exactly like Javascript
    if (faces == 4) {
        volume = side3 * sqrt(2) / 12;
    }
    else if (faces == 6) {
        volume = side3;
    }
    else if (faces == 8) {
        volume = side3 * sqrt(2) / 3;
    }
    else if (faces == 12) {
        volume = side3 * (15 + 7*sqrt(5)) / 4;
    }
    else if (faces == 20) {
        volume = side3 * (3 + sqrt(5)) * 5 / 12;
    }
    return volume;
}

int main() {
    // for-loop is much like Javascript.  
    // Note the use of a double as the loop variable, which Python would not like.
    for (double length = 1; length < 4; length++) {
        cout << "Faces = 4, volume = " << platonicvol(4, length) << endl;
        cout << "Faces = 6, volume = " << platonicvol(6, length) << endl;
        cout << "Faces = 8, volume = " << platonicvol(8, length) << endl;
        cout << "Faces = 12, volume = " << platonicvol(12, length) << endl;
        cout << "Faces = 20, volume = " << platonicvol(20, length) << endl;
    }
}