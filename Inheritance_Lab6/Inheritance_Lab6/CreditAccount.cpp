#include "CreditAccount.h"
#include <iostream>

void CreditAccount::Withdraw(float ammount) {
	BaseAccount::Withdraw(ammount);
	std::cout << "\n$" << ammount << " withdrawn from credit account!";
	mAmmountSpent += ammount;
	if (mAmmountSpent >= 40) {
		std::cout << "\n~Spent ammount exceeds $40; $5000 fee incurred~\n";
		BaseAccount::Withdraw(5000);
	}
}