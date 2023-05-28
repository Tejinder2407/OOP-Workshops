
// Header guard
#ifndef CARADS_H
#define CARADS_H

// Header files
#include <iostream>
// Global Variables
extern double g_taxrate;
extern double g_discount;

namespace sdds {
    // Function to print the command line arguments
    void listArgs(int noArg, char* arguments[]);

    // Class : Cars
    class Cars {

        char* brand{ nullptr }; // A null terminated string of any length
        char model[10]{ {'\0'} }; // Setting all characters to null terminator
        int manufactureYear{ -1 }; // Safe state value : -1
        double price{ -1 }; // Safe state value : -1
        char status{ 'Z' }; // Safe state value : 'Z'
        bool promotionDisc{};

    public:
        // Default Constructor
        Cars();
        // Function to read from the file.
        std::istream& read(std::istream& is);
        // Dunction to display the contents
        void display(bool reset);
        // Function to return the status of the car
        char getStatus();
        // Bool operator
        operator bool() const;
        // Rule of 3
        // Copy Constructor
        Cars(const Cars& src);
        // Copy assignment operator
        Cars& operator=(const Cars& src);
        // Destructor
        ~Cars();

    };

    // Overloading the input operator.
    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);


}

#endif
