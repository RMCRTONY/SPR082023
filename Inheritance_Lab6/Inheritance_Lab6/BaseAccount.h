#pragma once
class BaseAccount
{
protected:
	float mBalance = 0;
	int mWithdrawls = 0;
public:
	//BaseAccount(float ammount); // constructor

	virtual void Withdraw(float ammount); // decreases balance by amount. Does NOT “move” the money anywhere, simply reduces the balance and adds 1 to number of withdrawals
	void Deposit(float ammount); // increases balance by amount

	float GetBalance() const { return mBalance; } // returns the balance

	//virtual ~BaseAccount(); //destructor
};

