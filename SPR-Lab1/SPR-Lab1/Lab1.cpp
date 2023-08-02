#include "Lab1.h"
#include <iostream>

#define EQUNO(a,b,c) (a + 1 * b + 2 - c)
#define EQDOS(a,b,c) ((a + 1) * (b + 2) - c)



void OneOne();
void OneTwo();
void OneThree();
void OneFour();
void OneFive();
void OneSix();
void OneSeven();
int ValidateIntInput(); // declare method to be used later

int main() 
{
	// ********* PLEASE REMEMBER TO UNCOMMENT THE LINES BELOW BEFORE SUBMISSION PLEASE ********
	OneOne();
	OneTwo();
	OneThree();
	OneFour();
	OneFive();
	OneSix();
	OneSeven();
	
	std::cout << '\n';
	system("pause"); //this is not a "system-dot-pause" in the slightest, who named it that

}

void OneOne() 
{
	// 1-1 will ask usr for age and initials
	int age = 0;
	int days = 0;
	char initials[32];
	std::cout << "\nPlease enter your initials: ";
	std::cin >> initials;
	std::cin.ignore(INT_MAX, '\n');  //ignores buffer
	std::cout << "\nEnter your age: ";
	if (!(std::cin >> age)) //if it fails???
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		age = ValidateIntInput(); //use the validation method
	}
	days = age * 365;
	std::cout << "\n" << initials << ", did you know you are at least " << days << " days old?" << std::endl;

}

void OneTwo() 
{
	int nmbrz[5];
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "\nPlease enter a number: ";
		if (!(std::cin >> nmbrz[i])) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			nmbrz[i] = ValidateIntInput();
		}
		
		//std::cin.ignore(INT_MAX, '\n');
	}

	std::cout << "You entered: ";
	for (int n = 0; n < 5; n++) {
		std::cout << nmbrz[n];
	}
}

void OneThree() 
{
	int numA = 0;
	int numB = 0;
	int numC = 0;
	std::cout << "Please enter 3 numbers.\nEnter value for a: ";

	if (!(std::cin >> numA)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		numA = ValidateIntInput();
	}
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "\nEnter value for b: ";

	if (!(std::cin >> numB)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		numB = ValidateIntInput();
	}
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "\nEnter value for c: ";

	if (!(std::cin >> numC)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		numC = ValidateIntInput();
	}
	std::cin.ignore(INT_MAX, '\n');

	int sum1, sum2;
	sum1 = EQUNO(numA, numB, numC);
	sum2 = EQDOS(numA, numB, numC);

	std::cout << "\na + 1 * b + 2 - c = " << sum1 << "\n(a + 1) * (b + 2) - c = " << sum2;
}

void OneFour() 
{
	std::cout << "Table of integral variable type ranges in C++: \nTYPE: RANGE\n--------------------\nushort: "
		<< "0 to " << USHRT_MAX << "\nshort: " << SHRT_MIN << " to " << SHRT_MAX << "\nint: " << INT_MIN << " to " << INT_MAX
		<< "\nuint: 0 to " << UINT_MAX << "\nlong: " << LONG_MIN << " to " << LONG_MAX << "\nulong: 0 to " << ULONG_MAX
		<< "\nlonglong: " << LLONG_MIN << " to " << LLONG_MAX << "\nulonglong: 0 to " << ULLONG_MAX;
}

void OneFive() 
{
	char fullName[32];
	std::cout << "Please enter your full name: ";
	std::cin.getline(fullName, 32);
	std::cout << "Did you know that there are somewhere between 1 to 9,000,000,000 people named " << fullName << " alive today? \nNeat, right?" 
		<< "\n\nSource: https://babynames.net/names";  //this fact is only technically true. the source is not real.
}

void OneSix() 
{
	int userAge = 0;
	std::cout << "\nHow old are you? ";
	if (!(std::cin >> userAge)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		userAge = ValidateIntInput();
	}

	if (userAge < 16) {
		std::cout << "\nApologies, but you do not seem to meet the age requirement. Have a nice day.";
	}
	else if (userAge < 18) {
		std::cout << "\nNearing the meaningless rite-of-passage that is 18, I see."
			<< "\nI would rather not like to discuss the societal implications of this with you, a minor.";
	}
	else if (userAge < 21) {
		std::cout << "Old enough to be incarcerated and murdered overseas, still not old enough to drink.";
	}
	else if (userAge < 35) {
		std::cout << "I hear if you don't own a Ferrari by now, you are considered to have wasted your prime.";
	}
	else if (userAge < 60) {
		std::cout << "\n........BOO! \n\nOkay, surely you have suffered a heart attack. "
			<< "\nAn alarm will sound soon to inform passerby that this program is still running. \nOh, and to remove your... corpse or whatever.";
	}
	else {
		std::cout << "I am shocked that the mere sight of technology didn't put you in a coma. \nSlowly, step away from the PC before you hurt yourself.";
	}
}

void OneSeven() {
	int evenNumber;
	std::cout << "Please provide an even number: ";
	if (!(std::cin >> evenNumber)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		evenNumber = ValidateIntInput();
	}
	if (evenNumber % 2 == 0) {
		std::cout << "Sick! I love even numbers!";
	}
	else {
		std::cout << "Bruh. That is NOT an even number.";
	}
}

int ValidateIntInput()
{
	int input;

	bool good = false;

	while (true)

	{

		std::cout << "\nEnter a NUMBER: ";

		if (std::cin >> input)

		{

			good = true;

		}

		std::cin.clear();

		std::cin.ignore(INT_MAX, '\n');

		if (good) return input;
	}
}