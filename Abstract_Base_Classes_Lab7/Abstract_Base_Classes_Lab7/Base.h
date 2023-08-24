#pragma once
#include <string>


class Base
{
private:
	char* name = nullptr;

public:
	Base(); //default

	Base& operator=(const Base& other); //assignment

	Base(const Base& other);// copy

	~Base(); //destructor

	void SetName(const char* source) { //deep copy a string into mName
		if (name != nullptr) {
			delete[] name; //clear the location
		}
		size_t len = strlen(source) + 1; //get length of source
		name = new char[len]; //re-allocate appropriate space in destination
		strcpy_s(name, len, source); //strcpy does the rest
	}

	char* GetName() { return name; }

	virtual void DisplayRecord() = 0;

	
};

