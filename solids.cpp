//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

/**
 * File to demonstrate standalone functions
 * Peter Brown <peter.brown@converse.edu>, 2020-04-01
 */

#include <iostream>
#include <cmath>
using namespace std;

// /**
//  * Syntax for a function declaration:
//  * <return type> <functionname>([arguments]) {}
//  * where each argument is composed of a type and a name.
//  */

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
double platonicvol(int faces, int side) {
    double volume = 0;
    double side3 = side * side * side;
    // Switch statement is exactly like Javascript,
    // except you can only switch on an integer
    switch (faces) {
    case 4:
	volume = side3 * sqrt(2) / 12;
	break;
    case 6:
	volume = side3;
	break;
    case 8:
	volume = side3 * sqrt(2) / 3;
	break;
    case 12:
	volume = side3 * (15 + 7*sqrt(5)) / 4;
	break;
    case 20:
	volume = side3 * (3 + sqrt(5)) * 5 / 12;
	break;
    default:
	throw "Non-Platonic solid"; // Effectively an exception
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
    // Possible numbers of faces for Platonic solids
    int numFaces[] = {4, 6, 8, 12, 20};

    // We'll want the next two twice.  They're up here so I don't have to think of different names.
    int faces; // We'll want these a little later
    double length = 1;
    // for-loop is much like Javascript.  
    // Note the use of a double as the loop variable, which Python would not like.
    //   (Javascript wouldn't care, but Javascript cares little for data types anyway.)
    // Note also that there is no initiation statement, since it was already done above.
    for (; length < 4; length++) {
        for (int i = 0; i < 5; i++) {
            faces = numFaces[i];
            // The following line is spread over two lines in the file.  C++ is fine with that.
            cout << "Faces = " << faces << ", side = " << length << ", volume = " 
                << platonicvol(faces, length) << endl;
        }
        cout << endl;  // Blank line
    }

    // Read a number of faces and a side length from the keyboard
    cout << "Please enter a number of faces: ";
    cin >> faces;
    cout << "Please enter a side length: ";
    cin >> length;
    cout << "Faces = " << faces << ", side = " << length << ", volume = " 
        << platonicvol(faces, length) << endl;

}
