//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
using namespace std;

void printIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

void printCharArray(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "'" << arr[i] << "'" << '\t';
    }
    cout << endl;    
}

#define ARRAY_SIZE 10

int main() {
    /* Make an array */
    int arraySize = ARRAY_SIZE;
    int a[ARRAY_SIZE]; // Bare array
    
    // Initialize the array
    for (int i = 0; i < arraySize; i++) {
        a[i] = i + 65;
    }
    
    // Print the array
    cout << "Print the array" << endl;
    printIntArray(a, arraySize);
    
    // Does it stop at the end of the array?
    cout << "No, it doesn't stop at the end." << endl;
    printIntArray(a, 2 * arraySize);
    // Answer: no.  The loop runs right on past the end
    // of the array, printing whatever bits it finds there 
    // (interpreted as integers).  Note that I could just
    // as easily assign to those locations as print them.
    
    // Next: break the type system.
    int* b = a;  // b is now a pointer to integer,
                 // holding the address of a.
    
    // Note that a char is *not* the same size as an int.
    char* c = reinterpret_cast<char*>(b);
    // c now points to the address of a.
    
    cout << "We don't need no stinkin' type system..." << endl;
    printCharArray(c, 10 * arraySize);
    cout << "Done" << endl;
    
}