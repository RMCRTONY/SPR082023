#pragma once
#include "BaseAccount.h"
class CreditAccount :
    public BaseAccount
{
public:
    void Withdraw(float ammount); //Credit accounts have a spending $40 limit and charge a $5000 fee if you go over that spending limit
private:
    int mAmmountSpent = 0;
};

