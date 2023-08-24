#pragma once
#include <iostream>
#include <string>

/*
* 
//MEMORY LEAK DETECTOR CODE (goes at the beginning of main):
_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
_CrtSetBreakAlloc(-1); //set block for memory leak (-1) runs as normal
_CrtDumpMemoryLeaks();
*
*/

namespace Helper {

	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0); //displays string, validates input, ensures int is within provided range
	void PurgeCin(); //clears and ignores the input buffer
	int GetRandNum(int nMinimumRange = 0, int nMaximumRange = 0); //gets random number (possibly within a range)
	int PrntMenu(const char* menu);  //prints a menu, asks user for menu selection. returns selection.
	void CopyString(const char* source, char*& destination); //deep copys a char[]


	int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange) {
		
		// display strMessage
		std::cout << strMessage;

		int input;
		bool good = false;
		//get int from user
		
		//error check and validate
		while (good == false)
		{
			std::cout << "\nEnter a number: ";

			if (std::cin >> input)
			{
				good = true;
			}

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

		if (nMinimumRange == 0 && nMaximumRange == 0) {
				return input; //ignores the range check, just returns input.
		}

		while (true) {

			if (input >= nMinimumRange && input <= nMaximumRange) { //range check, if provided
				return input;
			}

			else {
				std::cout << "\nInt exceeds boundaries. Try again."; //notify user of error
				good = false;
				while (good == false) //get int, error check, validate
				{
					std::cout << "\nEnter a number: ";

					if (std::cin >> input)
					{
						good = true;
					}

					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
			}
		}
	}

	void PurgeCin() {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	int GetRandNum(int nMinimumRange, int nMaximumRange) {
		srand(time(NULL));

		if (nMinimumRange == 0 && nMaximumRange == 0) {
			return rand(); //if no parameters, unlimit random number
		}
		else {
			return ((rand() % nMaximumRange) + nMinimumRange); //if ranged, set number within range
		}
	}

	int PrntMenu(const char* menu) { //simply pass a char array. cout can do the rest
		
		std::cout << menu << std::endl;
		

		int input;
		bool good = false;

		while (good == false)
		{
			std::cout << "\nEnter your selection: ";

			if (std::cin >> input)
			{
				good = true;
			}

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

		return input;
	}

	void CopyString(const char* source, char*& destination) {
		if (destination != nullptr) {
			delete[] destination; //clear the location
		}
		size_t len = strlen(source) + 1; //get length of source
		destination = new char[len]; //re-allocate appropriate space in destination
		strcpy_s(destination, len, source); //strcpy does the rest
	}
}
 