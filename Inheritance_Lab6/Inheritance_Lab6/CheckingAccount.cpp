#include "CheckingAccount.h"
#include <iostream>


void CheckingAccount::Withdraw(float ammount) {
	BaseAccount::Withdraw(ammount);
	std::cout << "\n$" << ammount << " withdrawn from checking account!";
	if (mWithdrawls % 10 == 0) {
		std::cout << "\n~10 withdrawls made; $5 fee incurred.~";
		mBalance -= 5;
	}
}