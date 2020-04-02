//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

/**
 * File to demonstrate standalone functions
 * Peter Brown <peter.brown@converse.edu>, 2020-04-01
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * Function to calculate the volume of a regular Platonic solid
 * 
 * Arguments: 
 *     faces: number of faces in the solid
 *     side: length of one side of the solid
 * Returns a double representing the volume of the solid, in units
 *     based on the units of the argument SIDE.  (If side is in inches,
 *     the return value is in cubic inches; if side is in cm, the return
 *     value is in cm^3; and so on.)
 * 
 * This function does its calculation using a switch statement.
 */
/**
 * Syntax for a function declaration:
 * <return type> <functionname>([arguments]) {}
 * where each argument is composed of a type and a name.
 */
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

/**
 * Function to calculate the volume of a regular Platonic solid
 * 
 * Arguments: 
 *     faces: number of faces in the solid
 *     side: length of one side of the solid
 * Returns a double representing the volume of the solid, in units
 *     based on the units of the argument SIDE.  (If side is in inches,
 *     the return value is in cubic inches; if side is in cm, the return
 *     value is in cm^3; and so on.)
 * 
 * This function does its calculation using an if-else structure.
 */
double platonicvolif(int faces, int side) {
    double volume = 0;
    double side3 = side * side * side;
    // If-else syntax is exactly like Javascript
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

/**
 * Main program.  Prints the volume of each kind of regular Platonic solid
 * for side lengths 1, 2, and 3.
 */
int main() {
    // for-loop is much like Javascript.  
    // Note the use of a double as the loop variable, which Python would not like.
    //   (Javascript wouldn't care, but Javascript cares little for data types anyway.)
    for (double length = 1; length < 4; length++) {
        cout << "Faces = 4, volume = " << platonicvol(4, length) << endl;
        cout << "Faces = 6, volume = " << platonicvol(6, length) << endl;
        cout << "Faces = 8, volume = " << platonicvol(8, length) << endl;
        cout << "Faces = 12, volume = " << platonicvol(12, length) << endl;
        cout << "Faces = 20, volume = " << platonicvol(20, length) << endl;
    }
}