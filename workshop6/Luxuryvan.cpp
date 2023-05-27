/*
   Name - Tejiner Singh
   Email - ktejinder-singh@myseneca.ca
   Student Id - 129121219
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Luxuryvan.h"

namespace sdds {
    Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
        std::string ConsmpSpace;
        std::getline(in, ConsmpSpace, '\n');

        std::string arr[1] = { ConsmpSpace };
        for (int i = 0; i < 1; i++) {
            if (arr[i][0] != ' ' && arr[i][arr[i].length() - 1] != ' ') {
            }
            else if (arr[i][0] == ' ' && arr[i][arr[i].length() - 1] == ' ') {
                int f_NrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        f_NrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, f_NrepPos);

                int first_SpacePos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] == ' ') {
                        if (i2 + 1 < arr[i].length()) {
                            if (arr[i][i2 + 1] == ' ') {
                                first_SpacePos = i2;
                                i2 = arr[i].length();
                            };

                        }
                        else {
                            first_SpacePos = i2;
                            i2 = arr[i].length();
                        };
                    };
                };
                arr[i].erase(first_SpacePos);


            }
            else if (arr[i][0] == ' ') {
                int firstNrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        firstNrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, firstNrepPos);
            }
            else {
                int firstSpacePos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] == ' ') {
                        if (i2 + 1 < arr[i].length()) {
                            if (arr[i][i2 + 1] == ' ') {
                                firstSpacePos = i2;
                                i2 = arr[i].length();
                            };

                        }
                        else {
                            firstSpacePos = i2;
                            i2 = arr[i].length();
                        };
                    };
                };
                arr[i].erase(firstSpacePos);

            };

        };


        if (arr[0] == "e") {
            m_consumption = arr[0];

        }
        else {
            // Invalid
            throw "Invalid record!";
        };



    };

    void Luxuryvan::display(std::ostream& out) const {
        Van::display(out);
        out << " electric van  *";

    };

    std::string Luxuryvan::consumption() const {
        std::string returnVal;
        if (m_consumption == "e") {

            returnVal = "electric";
        };
        return returnVal;
    };

}