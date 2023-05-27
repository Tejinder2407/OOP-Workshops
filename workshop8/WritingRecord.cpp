/*
	==================================================
	Workshop 08: OOP435ZCC
	==================================================
	Name   : Tejinder Singh
	ID     : 129121216
	Email  : ktejinder-singh@myseneca.ca
	Section: ZCC
*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		

		for (size_t x = 0; x < emp.size(); x++) {
			for (size_t i2 = 0; i2 < sal.size(); i2++) {
				if (emp[x].id == sal[i2].id) {
					
					EmployeeWage* emp_Wage = new EmployeeWage(emp[x].name, sal[i2].salary);

					try {
						emp_Wage->rangeValidator();

					}
					catch (...) {
						// Exception thrown (Salary is not in the range.)
						delete emp_Wage;
						throw;

					};

					bool sinValid = emp.checkSin(emp[x].id);
					if (!sinValid) {
						delete emp_Wage;
						std::string msg = "SIN Not valid";
						throw msg;
					};

					activeEmp += emp_Wage;

					i2 = sal.size();
				};


			};


		};

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		

		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t i2 = 0; i2 < sal.size(); i2++) {
				if (emp[i].id == sal[i2].id) {
					
					std::unique_ptr<EmployeeWage>empWage(new EmployeeWage(emp[i].name, sal[i2].salary));

					empWage->rangeValidator();

					bool sin_Valid = emp.checkSin(emp[i].id);
					if (!sin_Valid) {
						std::string msg = "SIN Not valid";
						throw msg;
					};

					activeEmp += std::move(empWage);

					i2 = sal.size();
				};


			};


		};

		return activeEmp;
	}
}