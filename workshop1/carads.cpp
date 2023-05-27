/*
    ==================================================
    Workshop 01: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/


#include "carads.h"
#include <cstring>
double g_discount;
double g_taxrate;
namespace sdds {
    void listArgs(int noArg, char* arguments[]) {
        std::cout << "Command Line:" << std::endl;
        std::cout << "--------------------------" << std::endl;

        
        for (int i = 0; i < noArg; i++) {
            std::cout << "  " << (i + 1) << ": " << arguments[i] << std::endl;

        };

        std::cout << "--------------------------" << std::endl << std::endl;

    };
    // Constructor
    Cars::Cars() {
       
        brand = nullptr;

    };



 
    std::istream& Cars::read(std::istream& is) {

        if (is) {
          
            status = is.get();

            
            is.ignore();

            // Getting car brand
            bool commaReached = false;
            int x = 0;
           
            char temp_str[1000] = { '\0' };
            while (!commaReached) {
                if (is.peek() == ',') {
                    commaReached = true;
                    is.ignore();
                }
                else {
                    temp_str[x] = is.get();
                    x++;
                };
            };
            temp_str[x] = '\0';
            delete[] brand; 
            brand = new char[std::char_traits<char>::length(temp_str) + 1];
            
            strcpy(brand, temp_str);


            // Getting car model
            commaReached = false;
            x = 0;
            while (!commaReached) {
                if (is.peek() == ',') {
                    commaReached = true;
                    is.ignore();
                }
                else {
                    model[x] = is.get();
                    x++;
                };
            };
            model[x] = '\0';

            // Getting year
            is >> manufactureYear;
            is.ignore();
            // Getting price

            is >> price;
            is.ignore();

            
            char temp;
            temp = is.get();
            if (temp == 'Y') {
                promotionDisc = true;
            }
            else {
                promotionDisc = false;
            };

            is.get();
            is.get();


        };
        return is;

    };


    // Display function
    void Cars::display(bool reset) {


        static int counter = 1;
        if (reset) {
            counter = 1;

        };
        
        if (brand[0] != '\0') {
            // Outputting the counter
            std::cout.width(2);
            std::cout.setf(std::ios::left);
            std::cout << counter;

            std::cout << ". ";

            // Outputting the brand
            std::cout.width(10);
            std::cout.setf(std::ios::left);
            std::cout << brand;

            std::cout << "| ";

            // Outputting the model
            std::cout.width(15);
            std::cout.setf(std::ios::left);
            std::cout << model;

            std::cout << "| ";

            // Outputting the year
            std::cout.width(4);
            std::cout << manufactureYear;

            std::cout << " |";

            
            double priceWithTax = price + price * g_taxrate;
     
            std::cout.width(12);
            std::cout.setf(std::ios::right);
            std::cout.setf(std::ios::fixed);
            std::cout.precision(2);
            std::cout << priceWithTax;

            std::cout << "|";



            if (promotionDisc == true) {
               
                std::cout.width(12);
                std::cout.setf(std::ios::right);
                std::cout.setf(std::ios::fixed);
                std::cout.precision(2);
                
                double discount_price = priceWithTax - (g_discount * priceWithTax);
               
                std::cout << discount_price;
            };
            std::cout.unsetf(std::ios::right);

            std::cout << std::endl;


        }
        else {
          
            std::cout.width(2);
            std::cout.setf(std::ios::left);
            std::cout << counter;

            std::cout << ". ";

            std::cout << "No Car" << std::endl;

        };
        std::cout.unsetf(std::ios::right);
        counter++;


    };


    char Cars::getStatus() {
        return status;

    };

    
    Cars::operator bool() const {
        bool rtrnVal;
        if (status == 'N') {
            rtrnVal = true;
        }
        else {
            rtrnVal = false;
        };

        return rtrnVal;
    };

   
    Cars::~Cars() {
        delete[] brand;  // Destructor

    };

   
    Cars& Cars::operator=(const Cars& src) {
       
        if (this != &src) {
           
            manufactureYear = src.manufactureYear;
            price = src.price;
            status = src.status;
            promotionDisc = src.promotionDisc;

          
            strcpy(model, src.model);

            
            delete[] brand;
            
            if (src.brand != nullptr) {
                brand = new char[std::char_traits<char>::length(src.brand) + 1];
                strcpy(brand, src.brand);

            }
            else {
                brand = nullptr;
            };


        };
        return *this;
    };

    // Copy Constructor
    Cars::Cars(const Cars& src) {
        brand = nullptr;
        
        *this = src;

    };

  
    std::istream& operator>>(std::istream& is, Cars& car) {
        return car.read(is);

    };

    
    void operator>>(const Cars& car1, Cars& car2) {
        car2 = car1; 

    };






}




