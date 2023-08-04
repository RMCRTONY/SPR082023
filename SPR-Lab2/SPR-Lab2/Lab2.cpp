#include "Lab2.h"
#include <iostream>
//#include <bitset>

void TurnOn(int bit); // i dont think any of these need to return anything as all they do is mod bitField
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();

int VerifyTrueInt();

unsigned int bitField; // 4 bytes of zeros, currently

void main() {
	int operation;
	std::cout << "bitField value: " << bitField << "\nBits: " /* << find a way to represent bitField in bits */ ;
	std::cout << "\nOptions:\n\tTurnOn = 1, TurnOff = 2, Toggle = 3, Negate = 4, Left Shift = 5, Right Shift = 6, Exit = 7\nChoose Operation: ";
	if (!(std::cin >> operation)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		operation = VerifyTrueInt();
	}

	int bitVal;
	bool inMenu = true;
	do {
		switch (operation) {
		case 1:
			std::cout << "\n";
		case 2:

		case 3:

		case 4:

		case 5:

		case 6:

		default:
			std::cout << "\n\t\tExiting...";
			inMenu = false;
			break;
		}
	} while (inMenu = true);
}

void TurnOn(int bit) {  //parameter variable acts as the actual value in which the bit being turned on lies
	bitField |= bit;
}

void TurnOff(int bit) { //like turn on but reverse
	bitField &= ~bit;
}

void Toggle(int bit) { //toggles bit in question at value "bit"
	bitField ^= bit;
}

void Negate() { //inverts all the bits in the byte
	~bitField;
}

void LeftShift() { //shifts whole bit field left once
	bitField << 1;
}

void RightShift() { //shifts whole bit field right once
	bitField >> 1;
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