#include "Base.h"

Base::Base() {
	SetName("DEFAULT");
}

Base::Base(const Base& other) {
	*this = other; //calls asignment operator
}

Base& Base::operator=(const Base& other) {
	if (this != &other) {
		SetName(other.name);
	}
	return *this;
}

Base::~Base() {
	delete name;
}