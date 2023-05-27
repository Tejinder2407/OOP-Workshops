/*
    ==================================================
    Workshop 02: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/

#ifndef TENNISLOG_H
#define TENNISLOG_H
#include <iostream>
namespace sdds {


    // TennisMatch Struct
    struct TennisMatch {
        std::string tID{ "" };
        std::string tName{ "" };
        unsigned int matchID{ 0 };
        std::string wMatch{ "" };
        std::string lMatch{ "" };


    };


   
    class TennisLog {
        TennisMatch* allTennisMatches{ nullptr };
        unsigned int totalMatches{ 0 };

    public:
        // Default constrcutor
        TennisLog();
        // One argument constructor
        TennisLog(const char* fName);

        TennisMatch operator[](size_t);
        operator size_t() const;
        void addMatch(const TennisMatch& toAdd);

        TennisLog findMatches(std::string name);

        // Destructor
        ~TennisLog();

        // Copy assignment operator
        TennisLog& operator=(const TennisLog& src);

        // Copy Constructor.
        TennisLog(const TennisLog& src);

        // Move assignment operator
        TennisLog& operator=(TennisLog&& src);

        // Move constructor
        TennisLog(TennisLog&& src);


    };


    
    std::ostream& operator<<(std::ostream& os, const TennisMatch& src);


};

#endif
