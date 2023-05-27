/*
    ==================================================
    Workshop 02: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/

#include "Timer.h"

namespace sdds {

    void Timer::start() {
        begin = std::chrono::steady_clock::now();

    };


    long long Timer::stop() {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        long long val = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        return val;

    };





}
