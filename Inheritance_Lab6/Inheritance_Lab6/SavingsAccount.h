#pragma once
#include "BaseAccount.h"
class SavingsAccount :
    public BaseAccount
{
public:
    void Withdraw(float ammount); //Savings account will not allow more than 3 withdrawals
};

