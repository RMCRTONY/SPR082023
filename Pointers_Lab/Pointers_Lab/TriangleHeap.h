#pragma once
class TriangleHeap
{
private:
	float* mBase;
	float* mHeight;

public:
	TriangleHeap(); //default

	TriangleHeap(const TriangleHeap& other); //copy

	TriangleHeap& operator=(const TriangleHeap& other); //assignment

	~TriangleHeap(); // destructor

	void SetBase(float b);
	void SetHeight(float h);

	float GetArea();
};

