#include "Student.h"
#include <iostream>


void Student::SetGpa(float grade) {
	gpa = grade;
}

void Student::DisplayRecord() {
	std::cout << "\nStudent Name: " << Base::GetName() << "\t\t\tGPA: " << gpa ;
}