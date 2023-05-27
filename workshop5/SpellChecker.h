/*
	==================================================
	Workshop 05: OOP435ZCC
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ZCC
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
namespace sdds
{
	class SpellChecker
	{
		std::string m_bad[6]{};
		std::string m_good[6]{};
		size_t m_repl[6]{};

	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}
#endif