/*
	==================================================
	Workshop 08: OOP435ZCC
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ZCC
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		
		bool checkSin(const std::string& sin) const {
			bool returnValue;
			
			size_t sum1 = 0;
			for (int i = sin.length() - 2; i >= 0; i -= 2) {
				
				size_t digit = sin[i] - '0';
				size_t dDigit = 2 * digit;
				if (dDigit >= 10) {
					size_t sumDDigit = (dDigit % 10) + (dDigit / 10);
					sum1 += sumDDigit;
				}
				else {
					sum1 += dDigit;
				};

			};

			
			size_t sum2 = 0;

			for (int i = sin.length() - 1; i >= 0; i -= 2) {
				
				size_t digit = sin[i] - '0';
				sum2 += digit;

			};

			size_t total_Sum = sum1 + sum2;
			if (total_Sum % 10 == 0) {
				// Valid sin
				returnValue = true;
			}
			else {
				// Invalid sin
				returnValue = false;
			};

			return returnValue;

		};


		void operator+=(std::unique_ptr<T>ptr_obj) {
			list.push_back(*ptr_obj);

		};


		
		void operator+=(T* ptr_obj) {
			list.push_back(*ptr_obj);
			
			delete ptr_obj;

		};

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
