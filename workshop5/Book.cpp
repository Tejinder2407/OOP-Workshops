
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds
{
    Book::Book() = default;
    Book::Book(const std::string& strBook)
    {
        auto trim = [](std::string str)
        {
            return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
        };
        std::string _str_Book = strBook;
        m_author = trim(_str_Book.substr(0, _str_Book.find(',')));
        _str_Book.erase(0, _str_Book.find(',') + 1);
        m_title = trim(_str_Book.substr(0, _str_Book.find(',')));
        _str_Book.erase(0, _str_Book.find(',') + 1);
        m_country = trim(_str_Book.substr(0, _str_Book.find(',')));
        _str_Book.erase(0, _str_Book.find(',') + 1);
        m_price = std::stod(trim(_str_Book.substr(0, _str_Book.find(','))));
        _str_Book.erase(0, _str_Book.find(',') + 1);
        m_year = std::stoul(trim(_str_Book.substr(0, _str_Book.find(','))));
        _str_Book.erase(0, _str_Book.find(',') + 1);
        m_desc = trim(_str_Book);
    }
    const std::string& Book::title() const
    {
        return m_title;
    }
    const std::string& Book::country() const
    {
        return m_country;
    }
    const size_t& Book::year() const
    {
        return m_year;
    }
    double& Book::price()
    {
        return m_price;
    }
    std::ostream& operator<<(std::ostream& os, const Book& book)
    {
        os.width(20);
        os.fill(' ');
        os << book.m_author << " | ";
        os.width(22);
        os << book.title() << " | ";
        os.width(5);
        os << book.country() << " | ";
        os.width(4);
        os << book.year() << " | ";
        os.width(6);
        os.setf(ios::fixed);
        os.precision(2);
        os << book.m_price << " | ";
        os << book.m_desc << endl;
        os.unsetf(ios::fixed);
        return os;

    }
}
