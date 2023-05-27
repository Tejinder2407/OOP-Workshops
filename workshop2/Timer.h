/*
    ==================================================
    Workshop 02: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace sdds {

    class Timer {
        std::chrono::steady_clock::time_point begin;

    public:
        void start();
        long long stop();

    };

};

#endif
