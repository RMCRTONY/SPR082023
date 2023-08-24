#include "TriangleHeap.h"


TriangleHeap::TriangleHeap() { //default
	mBase = new float();
	mHeight = new float();
	SetBase(0);
	SetHeight(0);
}

TriangleHeap::TriangleHeap(const TriangleHeap& other) { //copy
	mBase = new float();
	mHeight = new float();
	*this = other;
}
TriangleHeap& TriangleHeap::operator=(const TriangleHeap& other) { //assignment
	if (this != &other) {
		SetBase(*other.mBase);
		SetHeight(*other.mHeight);
	}
	return *this;
}
TriangleHeap::~TriangleHeap() { // destructor
	delete mBase;
	delete mHeight;
}
void TriangleHeap::SetBase(float b) {
	*mBase = b;
}
void TriangleHeap::SetHeight(float h) {
	*mHeight = h;
}

float TriangleHeap::GetArea() {
	float area = (*mBase) * (*mHeight) / 2;
	return area;
}
