/*
	==================================================
	Workshop 05: OOP435ZCC
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ZCC
*/
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>
#include <string>
namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
	public:
		Movie();
		Movie(const std::string& strMovie);
		virtual ~Movie();
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& m);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}
	};

}
#endif
