//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>

int main()
{
    // Print a multiplication table, with definite loops
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            std::cout << (i*j) << "\t";
        }
        std::cout << std::endl;
    }
    
    // Blank line between the tables
    std::cout << std::endl;
    
    // Print the same table with indefinite loops
    int i = 1;
    while (i < 13) {
        int j = 1;
        while (j < 13) {
            std::cout << (i*j) << "\t";
            j++;
        }
        std::cout << std::endl;
        i++;
    }
}