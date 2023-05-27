/*
    ==================================================
    Workshop 05: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/
#include "Movie.h"
namespace sdds
{
    Movie::Movie() = default;
    Movie::Movie(const std::string& strMovie)
    {
        auto trim = [](std::string str)
        {
            return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
        };
        std::string _str_Movie = strMovie;
        m_title = trim(_str_Movie.substr(0, _str_Movie.find(',')));
        _str_Movie.erase(0, _str_Movie.find(',') + 1);
        m_year = std::stoul(trim(_str_Movie.substr(0, _str_Movie.find(','))));
        _str_Movie.erase(0, _str_Movie.find(',') + 1);
        m_desc = trim(_str_Movie);
    }
    Movie::~Movie() = default;
    const std::string& Movie::title() const
    {
        return m_title;
    }
    std::ostream& operator<<(std::ostream& os, const Movie& m)
    {
        os.width(40);
        os.fill(' ');
        os << m.m_title << " | ";
        os.width(4);
        os << m.m_year << " | ";
        os << m.m_desc << std::endl;
        return os;
    }
}



