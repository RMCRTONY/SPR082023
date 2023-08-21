#pragma once
#include "BaseAccount.h"
class CheckingAccount :
    public BaseAccount
{
public:
    void Withdraw(float ammount); //Checking account charges a $5 fee if more than 10 withdrawals are made
};

