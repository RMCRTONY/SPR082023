#pragma once
#include <iostream>
#include <string>

namespace Helper {

	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0); //displays string, validates input, ensures int is within provided range
	void PurgeCin(); //clears and ignores the input buffer
	int GetRandNum(int nMinimumRange = 0, int nMaximumRange = 0); //gets random number (possibly within a range)
	int PrntMenu(std::string* menu);


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

	int PrntMenu(std::string* menu) {
		int size = menu->size();
		for (int i = 0; i < size; i++) {
			std::cout << i + 1 << ") " << (*menu)[i] << std::endl;
		}

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
}
 