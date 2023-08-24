#include "Helper.h"
#include "Base.h"
#include "Student.h"
#include "Employee.h"
#include <iostream>
#include <vector>

void AddRecord(std::vector<Base*>& v);
void DisplayRecords(std::vector<Base*>& v);
void DuplicateRecord(std::vector<Base*>& v);

int main() {
	//MEMORY LEAK DETECTOR CODE (goes at the beginning of main):
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //set block for memory leak
	_CrtDumpMemoryLeaks();

	std::vector<Base*> records;
	
	bool inMenu = 1;
	while (inMenu) {
		int choice = Helper::PrntMenu("\n~MAIN MENU~\n\t1) Add Record\n\t2) Display Records\n\t3) Duplicate Record\n\t4) Exit");
		switch (choice) {
		case 1: // add Record
			AddRecord(records);
			break;
		case 2: // display
			DisplayRecords(records);
			break;
		case 3: // duplicate
			DuplicateRecord(records);
			break;
		default:
			std::cout << "\n\nGoodbye\n\n";
			inMenu = false;
			break;
		}
	}



	for (int i = 0; i < records.size(); i++) {
		delete records[i];
	}
}


void AddRecord(std::vector<Base*>& v) {
	int choice = Helper::GetValidatedInt("Record type?\n\t1) Employee\n\t2) Student", 1, 2);
	Helper::PurgeCin();
	if (choice == 1) {
		Employee* nEmployee = new Employee(); //create employee object pointer

		//Helper::PurgeCin();
		char empName[32]; //prompt and set name
		std::cout << "Enter Employee Name: ";
		std::cin.getline(empName, 32);
		nEmployee->SetName(empName);
		
		
		int empSalary; //prompt and set salary
		std::cout << "Enter Salary for " << nEmployee->GetName() << ": ";
		std::cin >> empSalary;
		nEmployee->SetSalary(empSalary);
		

		//add to vector
		v.push_back(nEmployee);
		std::cout << "\nEmployee Added!";
	}
	else {
		Student * nStudent = new Student(); //create Student object pointer

		//Helper::PurgeCin();
		char stuName[32]; //prompt and set name
		std::cout << "Enter Student Name: ";
		std::cin.getline(stuName, 32);
		nStudent->SetName(stuName);
		

		float stuGPA; //prompt and set GPA
		std::cout << "Enter GPA for " << nStudent->GetName() << ": ";
		std::cin >> stuGPA;
		nStudent->SetGpa(stuGPA);
		

		//add to vector
		v.push_back(nStudent);
		std::cout << "\nStudent Added!";
	}
}

void DisplayRecords(std::vector<Base*>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i]->DisplayRecord();
	}
}

void DuplicateRecord(std::vector<Base*>& v) {
	int index = Helper::GetValidatedInt("Enter the index of the record to be copied", 0, v.size() - 1);

	Employee* testE = dynamic_cast<Employee*>(v[index]);
	if (testE != nullptr) {
		Employee* nEmployee = new Employee(*testE);
		v.push_back(nEmployee);
		std::cout << "\nEmployee Record Copied!";
	}
	Student* testS = dynamic_cast<Student*>(v[index]);
	if (testS != nullptr) {
		Student* nStudent = new Student(*testS);
		v.push_back(nStudent);
		std::cout << "\nStudent Record Copied!";
	}
}