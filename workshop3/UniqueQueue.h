/*
    ==================================================
    Workshop 03: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/

#ifndef SDDS_UNIQUEQUEUE_H_
#define SDDS_UNIQUEQUEUE_H_
#include <iostream>
#include <cmath>
#include "Queue.h"
constexpr int SIZE = 100;
namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue<T, SIZE>
    {
    public:
        UniqueQueue() = default;
        virtual ~UniqueQueue() = default;
        bool push(const T& item);
    };
    template <typename T>
    bool UniqueQueue<T>::push(const T& item)
    {
        bool result = false;
        bool found = false;
        for (size_t i = 0; i < Queue<T, 100>::size() && !found; i++)
        {
            if (this->operator[](i) == item)
            {
                found = true;
            }
        }

        if (!found)
        {

            result = Queue<T, SIZE>::push(item);
        }

        return result;
    }
    template <>
    bool UniqueQueue<double>::push(const double& item)
    {
        bool result = false;
        bool found = false;

        for (size_t x = 0; x < size() && !found; x++)
        {
            if (std::fabs(this->operator[](x) - item) <= 0.005)
            {
                found = true;
            }
        }

        if (!found)
        {

            result = Queue<double, SIZE>::push(item);
        }

        return result;
    }

}
#endif // !SDDS_UNIQUEQUEUE_H_