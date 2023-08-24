#include "Employee.h"
#include <iostream>


void Employee::SetSalary(int money) {
	salary = money;
}

void Employee::DisplayRecord() {
	std::cout << "\nEmployee Name: " << Base::GetName() << "\t\t\tSalary: " << salary;
}