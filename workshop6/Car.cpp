/*
   Name - Tejiner Singh
   Email - ktejinder-singh@myseneca.ca
   Student Id - 129121219
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Car.h"

namespace sdds {
    Car::Car(std::istream& is) {


        std::string TagSpace;
        std::getline(is, TagSpace, ',');


        std::string MakerSpace;
        std::getline(is, MakerSpace, ',');

        std::string condition_Space;
        std::getline(is, condition_Space, ',');
        is >> carTopSpeed;
        is.ignore();
        std::string arr[3] = { TagSpace,MakerSpace,condition_Space };

        for (int i = 0; i < 3; i++) {
            if (arr[i][0] != ' ' && arr[i][arr[i].length() - 1] != ' ') {
            }
            else if (arr[i][0] == ' ' && arr[i][arr[i].length() - 1] == ' ') {
                int firstNrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        firstNrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, firstNrepPos);
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
                if (arr[i].size() != 0) {
                    arr[i].erase(firstSpacePos);
                };

            }
            else if (arr[i][0] == ' ') {
                int firstN_repPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        firstN_repPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, firstN_repPos);
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

        carMaker = arr[1];
        if (arr[2].length() == 0) {
            carCondition = 'n';
        }
        else {
            carCondition = arr[2].at(0);
        };





        if (carCondition == 'n' || carCondition == 'u' || carCondition == 'b') {
            if (is.fail()) {
                is.clear();
                throw "Invalid record!";

            };

        }
        else {
            throw "Invalid record!";

        };






    };

   
    std::string Car::condition() const {
        std::string returnVal;
        if (carCondition == 'n') {
            // New
            returnVal = "new";
        }
        else if (carCondition == 'u') {
            // Used
            returnVal = "used";
        }
        else {
            // broken
            returnVal = "broken";
        };


        return returnVal;
    };


   
    double Car::topSpeed() const {

        return carTopSpeed;
    };

 
    void Car::display(std::ostream& out) const {
        out << "| ";
        out.width(10);
        out.setf(std::ios::right);
        out << carMaker;
        out.unsetf(std::ios::right);
        out << " | ";
        out.width(6);
        out.setf(std::ios::left);
        out << (*this).condition();
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(6);
        out.setf(std::ios::fixed);
        out.precision(2);
        out << topSpeed();
        out << " |";
        out.unsetf(std::ios::fixed);

    };




}


