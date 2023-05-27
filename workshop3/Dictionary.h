/*
    ==================================================
    Workshop 03: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/

#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_
#include <iostream>

namespace sdds
{

    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};

    public:
        Dictionary() = default;
        const std::string& getTerm() const { return m_term; }
        const std::string& getDefinition() const { return m_definition; }
        Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
        virtual ~Dictionary() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Dictionary& d);
    bool operator==(const Dictionary& left, const Dictionary& right);

}

#endif // !SDDS_DICTIONARY_H_