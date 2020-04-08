//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
#include <vector>
using namespace std;

/**
 * Print an array of int.
 * 
 * Arguments: 
 *     arr: the array to print
 *     size: size of the array.  Note that C++ just trusts the value given here.
 */
void printIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        cout << arr[i] << '\t';
    }
    cout << endl;
}

/**
 * Print an array of char.
 * 
 * Arguments: 
 *     arr: the array to print
 *     size: size of the array.  Note that C++ just trusts the value given here.
 */
void printCharArray(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        cout << "'" << arr[i] << "'" << '\t';
    }
    cout << endl;    
}

/**
 * Break the type system!  Print an array of int byte by byte as char.
 * 
 * Arguments: 
 *     arr: the array to print
 *     size: size of the array
 */
void printIntArrayAsChar(int* arr, int size) {
    int* b = arr;  // b is now a pointer to integer,
                   // holding the address of arr.
    
    // Note that a char is *not* the same size as an int.
    char* c = reinterpret_cast<char*>(b);
    // c now points to the address of a.
    
    cout << "We don't need no stinkin' type system..." << endl;
    printCharArray(c, 10 * size);
    cout << "Done" << endl;
}

/**
 * Take advantage of C++ templates to print a vector of *anything* (same function).
 * I *could* have used templates above, but it would have made the type problems less obvious.
 * 
 * Arguments:
 *     vec: vector to print
 */
template <typename T>
void printVector(vector<T> &vec) {
    // Note asking the vector its size on the next line
    for (int i = 0; i < vec.size(); i++) {
        cout << i << ": ";
        // cout << vec[i] << '\t'; // Unchecked access to vector elements.  Fairly safe in *this*
                                   // context, since we asked the vector its size, but in general
                                   // you can still do buffer overruns with this
        cout << vec.at(i) << '\t'; // Access vector elements, checking for invalid values of i
    }
    cout << endl;
}

/**
 * Take advantage of C++ templates to print a vector of *anything* (same function), using an
 * iterator.  
 * 
 * An iterator is like a pointer, only a *whole* lot safer.  Iterators don't support
 * general arithmetic, just the stuff you need for iteration.  Also, you can't get the address out
 * of an iterator.
 * 
 * Arguments:
 *     vec: vector to print
 */
template <typename T>
void printVectorIter(vector<T> &vec) {
    // Start at the beginning, go on until you come to the end, and then stop.
    for (typename vector<T>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << '\t'; // *iter is the thing indicated by iter
    }
    cout << endl;
}

#define ARRAY_SIZE 10

/**
 * Do thoughtless things with arrays, which demonstrate the danger of being thoughtless in C++.
 */
void doUglyArrayThings() {
    /* Make an array */
    const int arraySize = ARRAY_SIZE;  // "const" is a promise not to change it
    int a[arraySize]; // Bare array
    
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
    printIntArrayAsChar(a, arraySize);
}

/**
 * Do similarly thoughtless things with vectors, demonstrating that C++ vectors are much safer than arrays.
 */
void doCleanerVectorThings() {
    // Make a vector
    const int vecSize = ARRAY_SIZE;
    vector<int> intVec;

    // Initialize the vector
    for (int i = 0; i < vecSize; i++) {
        intVec.push_back(i + 65);  // vector increases in length each time
    }

    // Print the vector
    cout << "Print the vector" << endl;
    printVector(intVec);

    // Vector of char
    // Note you can't reuse the memory from the int vector for the char
    //   vector, so they stay separate...
    vector<char> charVec;
    for (int i = 0; i < vecSize; i++) {
        charVec.push_back('A' + i); // Can still do math with characters
    }

    // Print the char vector.
    // Note the same function is used as for the int vector, with no loss of type safety.
    cout << "Print the vector" << endl;
    printVector(charVec);

    // Still possible to break the type system, but much harder to do it by accident
    printIntArrayAsChar(intVec.data(), intVec.size());
}

int main() {
    doUglyArrayThings();
    cout << endl;
    doCleanerVectorThings();
}
