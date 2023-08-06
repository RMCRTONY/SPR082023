#include "Lab2.h"
#include <iostream>
#include "Console.h"  //included here because ??????????
//#include <bitset>

void TurnOn(int bit); // i dont think any of these need to return anything as all they do is mod bitField
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();
void GetBits(int loopMaster);

int VerifyTrueInt();

unsigned int bitField = 12; //  currently: 0000 0000 0000 0000 0000 0000 0000 1100 

int main() {
	int operation;
	int bitVal;
	bool inMenu = true;
	while (inMenu) { 
		//normal menu, displays bits every time
		std::cout << "bitField value: " << bitField << "\nBits: ";
		GetBits(32) /* find a way to represent bitField in bits */;
		std::cout << "\n\tOptions:\n\tTurnOn = 1, TurnOff = 2, Toggle = 3, Negate = 4, Left Shift = 5, Right Shift = 6, Exit = 7\nChoose Operation: ";
		if (!(std::cin >> operation)) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			operation = VerifyTrueInt();
		}
		//menu interface selection switch
		switch (operation) {
		case 1: //turnOn
			std::cout << "\nTurnOn\nChoose bit index: ";
			if (!(std::cin >> bitVal)) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				bitVal = VerifyTrueInt();
			}
			TurnOn(bitVal);
			std::cout << "\nSuccess!\n";
			break;
		case 2: //turnOff
			std::cout << "\nTurnOf\nChoose bit index: ";
			if (!(std::cin >> bitVal)) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				bitVal = VerifyTrueInt();
			}
			TurnOff(bitVal);
			std::cout << "\nSuccess!\n";
			break;
		case 3: //Toggle
			std::cout << "\nToggle\nChoose bit index: ";
			if (!(std::cin >> bitVal)) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				bitVal = VerifyTrueInt();
			}
			Toggle(bitVal);
			std::cout << "\nSuccess!\n";
			break;
		case 4: //Negate
			std::cout << "\nNegating...\n";
			Negate();
			std::cout << "\nSuccess!\n";
			break;
		case 5: //Left shift
			std::cout << "\nShifting Left...\n";
			LeftShift();
			std::cout << "\nSuccess!\n";
			break;
		case 6: //Right shift
			std::cout << "\nShifting Right...\n";
			RightShift();
			std::cout << "\nSuccess!\n";
			break;
		case 7: //exit
			std::cout << "\n\t\tExiting...\n";
			inMenu = false;
			break;
		}
	} 
	return 0;
}

void TurnOn(int bit) {  //parameter variable acts as the actual value in which the bit being turned on lies
	int location = 1 << bit; //bit acts as the location of the bit in question
	
	bitField |= location;
}

void TurnOff(int bit) { //like turn on but reverse		EX: pass in 3
	int location = 1 << bit;							//	EX: 0000 0000 0000 1000  BitField = 0000 0000 0001 1100
														//~bit: 1111 1111 1111 0111          &  1111 1111 1111 0111
	bitField &= ~location;								//										0000 0000 0001 0100
}

void Toggle(int bit) { //toggles bit in question at value "bit"
	int location = 1 << bit; 

	bitField ^= location;
}

void Negate() { //inverts all the bits in the byte
	bitField = ~bitField;
}

void LeftShift() { //shifts whole bit field left once
	bitField = bitField << 1;
}

void RightShift() { //shifts whole bit field right once
	bitField = bitField >> 1;
}

int VerifyTrueInt() { //wanted to validate inputs out of fear of screwing the buffer
	int input;
	bool good = false;
	while (true) {
		std::cout << "\nPlease enter a real number: ";
		if (std::cin >> input) {
			good = true;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		if (good) return input;
	}
}

void GetBits(int loopMaster) { //loopmaster is the loop control variable.
	//check if each bit is on. 
	//print that bit else print 0
	unsigned int checker = 1 << 31;
	for (int i = 0; i < loopMaster; i++) {
		if ((bitField & checker) > 0) { // if the result is greater than 1 then the bit is active
			std::cout << "1";
		}
		else {
			std::cout << "0";
		}
		checker = checker >> 1;
	}
}