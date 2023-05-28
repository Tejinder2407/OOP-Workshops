

#include "TennisLog.h"
#include <fstream>
#include <cstring>
namespace sdds {


    // Default constructor
    TennisLog::TennisLog() {




    };

    // One argument 

    TennisLog::TennisLog(const char* fName) {
        std::ifstream is(fName);

        // Counting the total no of matches.

        unsigned int noMatches = -1;
        bool keepReading = true;
        while (keepReading) {
            if (is.peek() == EOF) {
                keepReading = false;
            }
            else {
                noMatches += 1;
                std::string str;
                getline(is, str);
            };

        };

        is.close();




        // Allocating the dynamic memory
        allTennisMatches = new TennisMatch[noMatches];
        totalMatches = noMatches;



        
        std::ifstream is2(fName);
        std::string ig;
      
        getline(is2, ig);


        keepReading = true;
        int currentMtach = 0;
        while (keepReading) {
            if (is2.peek() == EOF) {
                keepReading = false;
            }
            else {
               
               
                getline(is2, allTennisMatches[currentMtach].tID, ',');
             
                getline(is2, allTennisMatches[currentMtach].tName, ',');

                
                is2 >> allTennisMatches[currentMtach].matchID;
                is2.ignore();

               
                getline(is2, allTennisMatches[currentMtach].wMatch, ',');



                getline(is2, allTennisMatches[currentMtach].lMatch, '\n');
                currentMtach++;

            };



        };


        is2.close();



    };


   
    std::ostream& operator<<(std::ostream& os, const TennisMatch& src) {
        if (src.tID.length() > 0) {
            
            os.fill('.');

            
            os.width(20);
            os.setf(std::ios::right);
            os << "Tourney ID";
            os.unsetf(std::ios::right);
            os << " : ";
            
            os.width(30);
            os.setf(std::ios::left);
            os << src.tID << std::endl;
            os.unsetf(std::ios::left);

           
            os.width(20);
            os.setf(std::ios::right);
            os << "Match ID";
            os.unsetf(std::ios::right);
            os << " : ";
            
            os.width(30);
            os.setf(std::ios::left);
            os << src.matchID << std::endl;
            os.unsetf(std::ios::left);

            
            os.width(20);
            os.setf(std::ios::right);
            os << "Tourney";
            os.unsetf(std::ios::right);
            os << " : ";
           
            os.width(30);
            os.setf(std::ios::left);
            os << src.tName << std::endl;
            os.unsetf(std::ios::left);

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Winner";
            os.unsetf(std::ios::right);
            os << " : ";
          
            os.width(30);
            os.setf(std::ios::left);
            os << src.wMatch << std::endl;
            os.unsetf(std::ios::left);

           
            os.width(20);
            os.setf(std::ios::right);
            os << "Loser";
            os.unsetf(std::ios::right);
            os << " : ";
            
            os.width(30);
            os.setf(std::ios::left);
            os << src.lMatch << std::endl;
            os.unsetf(std::ios::left);
            os.fill(' ');

        }
        else {
            // An emty state.
            os << "Empty Match";
        };

        return os;

    };

    // Adding the tennis match.
    void TennisLog::addMatch(const TennisMatch& toAdd) {
        // Creating a new array to hold the new match
        TennisMatch* tempAll = new TennisMatch[totalMatches + 1];
        // Copying the values to the new array
        for (unsigned int count = 0; count < totalMatches; count++) {
            tempAll[count] = allTennisMatches[count];

        };

        // Deleting  array.
        delete[] allTennisMatches;
       
        allTennisMatches = tempAll;
       
        allTennisMatches[totalMatches] = toAdd;
        totalMatches++;

    };






    TennisMatch TennisLog::operator[](size_t index) {

        if (allTennisMatches != nullptr && index < totalMatches) {
            return allTennisMatches[index];
        }
        else {
            TennisMatch temp;
            return temp;
        };
    };

    TennisLog::operator size_t() const {
        return totalMatches;

    };


    TennisLog TennisLog::findMatches(std::string name) {
        
        TennisLog playersWithMatch;

        for (unsigned int i = 0; i < totalMatches; i++) {
            if (allTennisMatches[i].wMatch == name || allTennisMatches[i].lMatch == name) {
                playersWithMatch.addMatch(allTennisMatches[i]);
            };

        };

        return playersWithMatch;

    };

    

    

    TennisLog::~TennisLog() {  // Destructor.
        delete[] allTennisMatches;

    };



    // Copy assignment operator
    TennisLog& TennisLog::operator=(const TennisLog& src) {
        delete[] allTennisMatches;
        totalMatches = 0;
        if (this != &src) {
            allTennisMatches = new TennisMatch[src.totalMatches];
            for (unsigned int i = 0; i < src.totalMatches; i++) {
                allTennisMatches[i] = src.allTennisMatches[i];


            };
            totalMatches = src.totalMatches;
        }
        else {
            allTennisMatches = nullptr;

        };
        return *this;

    };

    // Copy Constructor.
    TennisLog::TennisLog(const TennisLog& src) {
        (*this) = src;
    };

    // Move assignment operator
    TennisLog& TennisLog::operator=(TennisLog&& src) {
        delete[] allTennisMatches;
        if (this != &src) {
            totalMatches = size_t(src);
            allTennisMatches = src.allTennisMatches;
            src.allTennisMatches = nullptr;
            src.totalMatches = 0;
        }
        else {
            allTennisMatches = nullptr;
            totalMatches = 0;
        };
        return *this;
    };

    // Move constructor
    TennisLog::TennisLog(TennisLog&& src) {

        (*this) = std::move(src);

    };


}
