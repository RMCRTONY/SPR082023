#pragma once
#include "Base.h"
class Student :
    public Base
{
private:
    float gpa = 0;

public: 
    void SetGpa(float grade);
    void DisplayRecord();
};

