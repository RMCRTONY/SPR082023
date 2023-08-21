#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::Withdraw(float ammount) {
	if (mWithdrawls <= 3) { //Less than or ==, you nonce
		BaseAccount::Withdraw(ammount);
		std::cout << "\n$" << ammount << " withdrawn from savings!";
	}
	else {
		std::cout << "\n~Maximum Withdrawls Exceeded~\n";
	}
}