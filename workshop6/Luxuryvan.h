/*
   Name - Tejiner Singh
   Email - ktejinder-singh@myseneca.ca
   Student Id - 129121219
   Date - 2022-11-06
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef LUXURYVAN_H
#define LUXURYVAN_H
#include "Van.h"
#include <iostream>
namespace sdds {
    class Luxuryvan : public Van {
        std::string m_consumption;

    public:
        Luxuryvan(std::istream& in);
        void display(std::ostream& out) const;
        std::string consumption() const;

    };



}

#endif