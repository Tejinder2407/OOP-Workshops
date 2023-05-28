

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
