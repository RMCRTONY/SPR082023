#include "BaseAccount.h"

//BaseAccount::BaseAccount(float ammount) : mBalance(0), mWithdrawls(0) {
//	mBalance = ammount;
//}


void BaseAccount::Withdraw(float ammount) {
	mBalance -= ammount;
	mWithdrawls += 1;
}

void BaseAccount::Deposit(float ammount) {
	mBalance += ammount;
}
