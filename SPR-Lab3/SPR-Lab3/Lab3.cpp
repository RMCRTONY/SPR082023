#include "Lab3.h"
#include <iostream>

enum EnumColorDefintion {Red = 1, Blue, Gray, Silver, White, Black};

struct Car {
	char Make[32];
	char Model[32];
	int Year;
	int Mileage;
	EnumColorDefintion Color;
};


void Prg1();
void Prg2(int reg, int* pntr);
void Prg3();
void PrintCar(Car c);
void PrintCarPointer(Car* c);
void PurgeCin();
void RepaintCar(Car* ptrCar, EnumColorDefintion newColor);
void AddMileage(Car* ptrCar, int milestoadd);


int main() {
	Prg1();
	std::cout << "~~End of Program 1~~" << std::endl;

	int nums[15];
	
	srand(time(NULL)); //srand object

	for (int i = 0; i < 15; i++) {
		nums[i] = rand();

	}

	for (int j = 0; j < 15; j++) {
		
		Prg2(nums[j], &nums[j]);
	}
	std::cout << "~~End of Program 2~~" << std::endl;

	std::cout << "Entering Garage...\n";
	Prg3();
	std::cout << "Exiting Garage...";

	

	return 0;
}

void Prg1() {
	int nums[15];

	srand(time(NULL)); //srand object

	for (int i = 0; i < 15; i++) {
		nums[i] = rand();
	}
	
	std::cout << "Values\t\tAddresses\n" << "---------------------------------------------" << std::endl;
	for (int j = 0; j < 15; j++) {
		std::cout << nums[j] << "\t\t" << &nums[j] << std::endl;
	}
	
}

void Prg2(int reg, int* pntr) {
	std::cout << "int: " << reg << "\tPointer: " << pntr << std::endl;
}

void Prg3() {
	Car cars[3];
	std::cout << "You bought 3 new cars!";
	for (int i = 0; i < 3; i++) { // loop storing user inputs for each car
		std::cout << "\nWhat is the make of car #" << i + 1 << "? ";
		std::cin.getline(cars[i].Make, 32);
		std::cout << "\nWhat is the model? ";
		std::cin.getline(cars[i].Model, 32);
		//PurgeCin();
		int year;
		std::cout << "\nThe year? ";
		std::cin >> year;
		cars[i].Year = year;
		int mileage;
		std::cout << "\nMileage: ";
		std::cin >> mileage;
		cars[i].Mileage = mileage;
		int colorInput;
		std::cout << "\nColor (1 - Red, 2 - Blue, 3 - Gray, 4 - Silver, 5 - White, 6 - Black)\n> ";
		std::cin >> colorInput;
		cars[i].Color = (EnumColorDefintion)colorInput;
		PurgeCin();
	}

	std::cout << "\nPrinting Cars...";
	for (int f = 0; f < 3; f++) {
		std::cout << "\nCar " << f + 1;
		PrintCar(cars[f]);
	}

	while (true) {
		char userCnfrm;
		std::cout << "\n\nWould you like to repaint any of these cars? Y/N?\n>";
		std::cin >> userCnfrm;
		if (userCnfrm == 'Y' || userCnfrm == 'y') {
			std::cout << "\nWhich car? ";
			int carChoice;
			std::cin >> carChoice;
			std::cout << "\nWhat color? \n(1 - Red, 2 - Blue, 3 - Gray, 4 - Silver, 5 - White, 6 - Black)\n> ";
			int colorChoice;
			std::cin >> colorChoice;
			EnumColorDefintion realColor = (EnumColorDefintion)colorChoice; //input conversion
			RepaintCar(&cars[carChoice - 1], realColor); //carChoice - 1 so no outofbounds exception thrown
			std::cout << "\nNew paint applied" << "\nPrinting Car Pointers...";
			for (int j = 0; j < 3; j++) {
				std::cout << "\nCar " << j + 1;
				PrintCarPointer(&cars[j]);
			}
		}
		else {
			break;
		}
	}

	while (true) {
		char userCnfrm;
		std::cout << "\n\nWould you like to drive any of these cars? Y/N?\n>";
		std::cin >> userCnfrm;
		if (userCnfrm == 'Y' || userCnfrm == 'y') {
			std::cout << "\nWhich car? ";
			int carChoice;
			std::cin >> carChoice;
			std::cout << "\nHow Far? ";
			int distanceTrvld;
			std::cin >> distanceTrvld;
			AddMileage(&cars[carChoice - 1], distanceTrvld); //carChoice - 1 so no outofbounds exception thrown
			std::cout << "\nCar Driven " << distanceTrvld << " miles " << "\nPrinting Car Pointers...";
			for (int j = 0; j < 3; j++) {
				std::cout << "\nCar " << j + 1;
				PrintCarPointer(&cars[j]);
			}
		}
		else {
			break;
		}
	}
}

void PrintCar(Car c) {
	
	std::cout << " - " << c.Year << ' ';
	switch (c.Color) {
	case 1:
		std::cout << "Red ";
		break;
	case 2:
		std::cout << "Blue ";
		break;
	case 3:
		std::cout << "Gray ";
		break;
	case 4:
		std::cout << "Silver ";
		break;
	case 5:
		std::cout << "White ";
		break;
	case 6:
		std::cout << "Black ";
		break;
	}
	std::cout << c.Make << ' ' << c.Model << " with " << c.Mileage << " miles.";
	
}

void PrintCarPointer(Car* c) { //this code could literally just be PrintCar(*c);
	std::cout << " - " << (*c).Year << ' ';  //(*c): deref + Parenthesis = obj
	switch ((*c).Color) {
	case 1:
		std::cout << "Red ";
		break;
	case 2:
		std::cout << "Blue ";
		break;
	case 3:
		std::cout << "Gray ";
		break;
	case 4:
		std::cout << "Silver ";
		break;
	case 5:
		std::cout << "White ";
		break;
	case 6:
		std::cout << "Black ";
		break;
	}
	std::cout << (*c).Make << ' ' << (*c).Model << " with " << (*c).Mileage << " miles.";
}

void RepaintCar(Car* ptrCar, EnumColorDefintion newColor) {
	ptrCar->Color = newColor;
}

void AddMileage(Car* ptrCar, int milestoadd) {
	ptrCar->Mileage += milestoadd;
}

void PurgeCin() {
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}